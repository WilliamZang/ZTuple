//
//  ZTupleBase.m
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import "ZTupleBase.h"
#import "ZMetaMacros.h"
#include "string.h"
@import ObjectiveC.runtime;

#define Z_SETTER_FUNC_DEF(index, _)                                                                             \
static void metamacro_concat(setter, index)(metamacro_concat(ZTuple, metamacro_inc(index)) *tuple, id value) {  \
    tuple. Z_ORDINAL_AT(index) = value;                                                                          \
}

metamacro_for_cxt(20, Z_SETTER_FUNC_DEF, , _)

#define Z_GETTER_FUNC_DEF(index, _)                                                                             \
static id metamacro_concat(getter, index)(metamacro_concat(ZTuple, metamacro_inc(index)) *tuple) {              \
    return [tuple Z_ORDINAL_AT(index)];                                                                          \
}

metamacro_for_cxt(20, Z_GETTER_FUNC_DEF, , _)

typedef void (*SetterType)(ZTupleBase *tuple, id value);

#define Z_SETTER_TABLE_ITEM(index, context)     &metamacro_concat(setter, index)

SetterType setterTable[] = {
    metamacro_for_comma(20, Z_SETTER_TABLE_ITEM, _)
};

typedef id (*GetterType)(ZTupleBase *tuple);

#define Z_GETTER_TABLE_ITEM(index, context)     &metamacro_concat(getter, index)

GetterType getterTable[] = {
    metamacro_for_comma(20, Z_GETTER_TABLE_ITEM, _)
};

static NSUInteger tupleCountWithObject(ZTupleBase *obj) {
    unsigned long count = 0;
    sscanf(class_getName(object_getClass(obj)), "ZTuple%lud", &count);
    return count;
}

@implementation ZTupleBase

- (NSUInteger)hash {
    return self.hashValue;
}

- (id)objectAtIndexedSubscript:(NSUInteger)idx {
    NSParameterAssert(idx < tupleCountWithObject(self));
    if (idx < tupleCountWithObject(self)) {
        return getterTable[idx](self);
    } else {
        return nil;
    }
}

- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx {
    NSParameterAssert(idx < tupleCountWithObject(self));
    if (idx < tupleCountWithObject(self)) {
        setterTable[idx](self, obj);
    }
}

- (nonnull id)copyWithZone:(nullable NSZone *)zone {
    NSAssert(false, @"Should implement within subclass");
    return nil;
}

- (NSUInteger)countByEnumeratingWithState:(nonnull NSFastEnumerationState *)state objects:(id  _Nullable __unsafe_unretained * _Nonnull)buffer count:(NSUInteger)len {
    NSUInteger count = tupleCountWithObject(self);
    if (state->state == count) {
        return 0;
    }
    
    Ivar ivar = class_getInstanceVariable(self.class, "_first");
    
    state->itemsPtr = (id  _Nullable __unsafe_unretained * _Nonnull)((__bridge void *)self + ivar_getOffset(ivar));
    state->mutationsPtr = (typeof(state->mutationsPtr))&self->_hashValue;
    
    state->state = count;
    return count;
}

- (BOOL)isEqual:(ZTupleBase *)other {
    if (![other isKindOfClass:ZTupleBase.class]) {
        return NO;
    }
    if (self == other) {
        return YES;
    }
    if (self.class != other.class) {
        return NO;
    }
    for (int i = 0; i < tupleCountWithObject(self); ++i) {
        if (self[i] == other[i] || [self[i] isEqual:other[i]]) {
            continue;
        }
        return NO;
    }
    return YES;
}

- (__kindof ZTupleBase *)join:(ZTupleBase *)other { 
    NSUInteger selfCount = tupleCountWithObject(self);
    NSUInteger otherTupleCount = tupleCountWithObject(other);
    NSAssert(selfCount + otherTupleCount <= 20, @"two tuple items count added cannot larger than 20");
    if (selfCount + otherTupleCount > 20) {
        return nil;
    }
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%lu", selfCount + otherTupleCount]);
    ZTupleBase *newInstance = [class new];
    for (int i = 0; i < selfCount; ++i) {
        newInstance[i] = self[i];
    }
    for (int i = 0; i < otherTupleCount; ++i) {
        newInstance[selfCount + i] = other[i];
    }
    return newInstance;
}

- (__kindof ZTupleBase *)take:(NSUInteger)count {
    NSParameterAssert(count >= 1);
    if (count < 1) {
        return nil;
    }
    if (count >= tupleCountWithObject(self)) {
        return [self copy];
    }
    
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%lu", count]);
    ZTupleBase *newInstance = [class new];
    for (int i = 0; i < count; ++i) {
        newInstance[i] = self[i];
    }
    return newInstance;
}

- (__kindof ZTupleBase *)drop:(NSUInteger)count {
    NSUInteger selfCount = tupleCountWithObject(self);
    NSParameterAssert(count < selfCount);
    if (count >= selfCount) {
        return nil;
    }
    if (count == 0) {
        return [self copy];
    }
    
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%lu", selfCount - count]);
    ZTupleBase *newInstance = [class new];
    for (int i = 0; i + count < selfCount; ++i) {
        newInstance[i] = self[i + count];
    }
    return newInstance;;
}

@end
