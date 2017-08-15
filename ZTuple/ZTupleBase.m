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
    unsigned long countOfItemsAlreadyEnumerated = state->state;
    
    state->itemsPtr = buffer;
    state->mutationsPtr = (typeof(state->mutationsPtr))&self->_hashValue;
    
    if (countOfItemsAlreadyEnumerated < count) {
        NSUInteger i;
        for (i = 0; i < MIN(len, count - countOfItemsAlreadyEnumerated); ++i) {
            buffer[i] = self[countOfItemsAlreadyEnumerated + i];
        }
        state->state = countOfItemsAlreadyEnumerated + i;
        return i;
    } else {
        return 0;
    }
}

@end
