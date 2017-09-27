//
//  ZTupleBase.m
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import "ZTupleBase.h"
#import "ZTupleSubClasses.h"
#import "ZMetaMacros.h"
#include "string.h"
@import ObjectiveC.runtime;

#define Z_SETTER_FUNC_DEF(index)                                                                                               \
static void Z_CONCAT(setter, index)(Z_CONCAT(ZTuple, Z_INC(index)) *tuple, id value) {                                         \
    tuple. Z_ORDINAL_AT(index) = value;                                                                                        \
}

Z_FOR_SPACE(20, Z_SETTER_FUNC_DEF)

#define Z_GETTER_FUNC_DEF(index)                                                                                               \
static id Z_CONCAT(getter, index)(Z_CONCAT(ZTuple, Z_INC(index)) *tuple) {                                                     \
    return [tuple Z_ORDINAL_AT(index)];                                                                                        \
}

Z_FOR_SPACE(20, Z_GETTER_FUNC_DEF)

typedef void (*SetterType)(ZTupleBase *tuple, id value);

#define Z_SETTER_TABLE_ITEM(index)     & Z_CONCAT(setter, index)

SetterType setterTable[] = {
    Z_FOR_COMMA(20, Z_SETTER_TABLE_ITEM)
};

typedef id (*GetterType)(ZTupleBase *tuple);

#define Z_GETTER_TABLE_ITEM(index)     & Z_CONCAT(getter, index)

GetterType getterTable[] = {
    Z_FOR_COMMA(20, Z_GETTER_TABLE_ITEM)
};

static unsigned short tupleCountWithObject(ZTupleBase *obj) {
    unsigned short count = 0;
    sscanf(class_getName(object_getClass(obj)), "ZTuple%hu", &count);
    return count;
}

@implementation ZTupleBase

+ (instancetype)tupleWithArray:(NSArray *)array {
    ZTupleBase *tuple = [self tupleWithCount:array.count];
    for (int i = 0; i < array.count; ++i) {
        tuple[i] = [array[i] isEqual:NSNull.null] ? nil : array[i];
    }
    return tuple;
}

+ (__kindof ZTupleBase *)tupleWithCount:(NSUInteger)count {
    Class tupleClass = NSClassFromString([NSString stringWithFormat:@"ZTuple%lu", (unsigned long)count]);
    ZTupleBase *tuple = [tupleClass new];
    return tuple;
}

- (NSUInteger)hash {
    return self.hashValue;
}

- (NSUInteger)count {
    return tupleCountWithObject(self);
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
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%@", @(selfCount + otherTupleCount)]);
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
    
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%@", @(count)]);
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
    
    Class class = NSClassFromString([NSString stringWithFormat:@"ZTuple%@", @(selfCount - count)]);
    ZTupleBase *newInstance = [class new];
    for (int i = 0; i + count < selfCount; ++i) {
        newInstance[i] = self[i + count];
    }
    return newInstance;;
}

- (NSArray *)allObjects {
    NSMutableArray *array = [NSMutableArray array];
    for (NSObject *item in self) {
        [array addObject:item ?: NSNull.null];
    }
    return [array copy];
}

- (NSString *)description {
    return [NSString stringWithFormat:@"%@%@", [super description], [self allObjects]];
}

@end
