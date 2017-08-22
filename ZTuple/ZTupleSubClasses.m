    //
    //  ZTupleSubClass.m
    //  Expecta-iOS
    //
    //  Created by Chengwei Zang on 2017/8/22.
    //

#import "ZTupleSubClasses.h"

#define _Z_INIT_PARAM_IMP_FIRST(index)                          Z_ORDINAL_CAP_AT(index):(id)Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM_IMP(index)                                Z_ORDINAL_AT(index):(id)Z_ORDINAL_AT(index)
#define Z_INIT_PARAM_IMP(index)                                 Z_IF_EQ(0, index)(_Z_INIT_PARAM_IMP_FIRST(index))(_Z_INIT_PARAM_IMP(index))

#define Z_SYNTHESIZE(index)                                                                                                    \
@synthesize Z_ORDINAL_AT(index) = Z_CONCAT(_, Z_ORDINAL_AT(index))

#define Z_INIT_SET_PARAM(index)                                                                                                \
Z_CONCAT(_, Z_ORDINAL_AT(index)) = Z_ORDINAL_AT(index);                                                                        \
self.hashValue ^= (NSUInteger)Z_ORDINAL_AT(index)

#define Z_COPY_SET(index)                                    copied. Z_ORDINAL_AT(index) = self. Z_ORDINAL_AT(index)

#define Z_SETTER(index)                                                                                                        \
- (void)Z_CONCAT(set, Z_ORDINAL_CAP_AT(index)):(id)value {                                                                     \
self.hashValue ^= (NSUInteger)Z_CONCAT(_, Z_ORDINAL_AT(index));                                                                \
Z_CONCAT(_, Z_ORDINAL_AT(index)) = value;                                                                                      \
self.hashValue ^= (NSUInteger)value;                                                                                           \
}

#define Z_TUPLE_IMP(i)                                                                                                         \
@implementation Z_CONCAT(ZTuple, i)                                                                                            \
Z_FOR_RECURSIVE(i, Z_SYNTHESIZE, ;);                                                                                           \
                                                                                                                               \
- (instancetype)Z_CONCAT(initWith, Z_FOR_SPACE(i, Z_INIT_PARAM_IMP)) {                                                         \
if (self = [super init]) {                                                                                                     \
Z_FOR_RECURSIVE(i, Z_INIT_SET_PARAM, ;);                                                                                       \
}                                                                                                                              \
return self;                                                                                                                   \
}                                                                                                                              \
                                                                                                                               \
- (nonnull id)copyWithZone:(nullable NSZone *)zone {                                                                           \
Z_CONCAT(ZTuple, i) *copied = [Z_CONCAT(ZTuple, i) new];                                                                       \
Z_FOR_RECURSIVE(i, Z_COPY_SET, ;);                                                                                             \
copied.hashValue = self.hashValue;                                                                                             \
return copied;                                                                                                                 \
}                                                                                                                              \
                                                                                                                               \
Z_FOR_RECURSIVE(Z_DEC(i), Z_SETTER, ;)                                                                                         \
                                                                                                                               \
- (id)Z_ORDINAL_AT(Z_DEC(i)) {                                                                                                 \
return Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i)));                                                                                    \
}                                                                                                                              \
                                                                                                                               \
- (void)Z_CONCAT(set, Z_ORDINAL_CAP_AT(Z_DEC(i))):(id)value {                                                                  \
self.hashValue ^= (NSUInteger)Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i)));                                                             \
[self willChangeValueForKey:@"last"];                                                                                          \
Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i))) = value;                                                                                   \
self.hashValue ^= (NSUInteger)value;                                                                                           \
[self didChangeValueForKey:@"last"];                                                                                           \
}                                                                                                                              \
                                                                                                                               \
- (id)last {                                                                                                                   \
return Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i)));                                                                                    \
}                                                                                                                              \
                                                                                                                               \
- (void)setLast:(id)last {                                                                                                     \
self.hashValue ^= (NSUInteger)Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i)));                                                             \
[self willChangeValueForKey:@Z_STRINGIFY(Z_ORDINAL_AT(Z_DEC(i)))];                                                             \
Z_CONCAT(_, Z_ORDINAL_AT(Z_DEC(i))) = last;                                                                                    \
self.hashValue ^= (NSUInteger)last;                                                                                            \
[self didChangeValueForKey:@Z_STRINGIFY(Z_ORDINAL_AT(Z_DEC(i)))];                                                              \
}                                                                                                                              \
                                                                                                                               \
@end

#define Z_TUPLE_IMP_FOREACH(index)           Z_TUPLE_IMP(Z_INC(index))

Z_FOR(20, Z_TUPLE_IMP_FOREACH, ;)
