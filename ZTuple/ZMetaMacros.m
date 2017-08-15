//
//  ZMetaMacros.m
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import "ZMetaMacros.h"

#define _Z_INIT_PARAM_IMP_FIRST(index)                          Z_ORDINAL_CAP_AT(index):(id)Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM_IMP(index)                                Z_ORDINAL_AT(index):(id)Z_ORDINAL_AT(index)
#define Z_INIT_PARAM_IMP(index, _)                              metamacro_if_eq(0, index)(_Z_INIT_PARAM_IMP_FIRST(index))(_Z_INIT_PARAM_IMP(index))

#define Z_INIT_SET_PARAM(index, _)                                                                    \
    metamacro_concat(_, Z_ORDINAL_AT(index)) = Z_ORDINAL_AT(index);                                     \
    self.hashValue ^= (NSUInteger)Z_ORDINAL_AT(index)

#define Z_COPY_SET(index, _)                                    copied. Z_ORDINAL_AT(index) = self. Z_ORDINAL_AT(index);

#define Z_SETTER(index, _)                                                                            \
- (void)metamacro_concat(set, Z_ORDINAL_CAP_AT(index)):(id)value {                                     \
    self.hashValue ^= (NSUInteger)metamacro_concat(_, Z_ORDINAL_AT(index));                            \
    metamacro_concat(_, Z_ORDINAL_AT(index)) = value;                                                  \
    self.hashValue ^= (NSUInteger)value;                                                              \
}

#define Z_TUPLE_IMP(i)                                                                                \
@implementation metamacro_concat(ZTuple, i)                                                           \
@synthesize Z_ORDINAL_AT(metamacro_dec(i)) = metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i)));       \
                                                                                                      \
- (instancetype)metamacro_concat(initWith, metamacro_for_recursive(i, Z_INIT_PARAM_IMP, , _)) {       \
    if (self = [super init]) {                                                                        \
        metamacro_for_recursive(i, Z_INIT_SET_PARAM,;, _);                                            \
    }                                                                                                 \
    return self;                                                                                      \
}                                                                                                     \
                                                                                                      \
- (nonnull id)copyWithZone:(nullable NSZone *)zone {                                                  \
    metamacro_concat(ZTuple, i) *copied = [metamacro_concat(ZTuple, i) new];                          \
    metamacro_for_recursive(i, Z_COPY_SET, , _);                                                      \
    copied.hashValue = self.hashValue;                                                                \
    return copied;                                                                                    \
}                                                                                                     \
                                                                                                      \
metamacro_for_recursive(metamacro_dec(i), Z_SETTER, ,_)                                               \
                                                                                                      \
- (id)Z_ORDINAL_AT(metamacro_dec(i)) {                                                                 \
    return metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i)));                                        \
}                                                                                                     \
                                                                                                      \
- (void)metamacro_concat(set, Z_ORDINAL_CAP_AT(metamacro_dec(i))):(id)value {                          \
    self.hashValue ^= (NSUInteger)metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i)));                 \
    [self willChangeValueForKey:@"last"];                                                             \
    metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i))) = value;                                       \
    self.hashValue ^= (NSUInteger)value;                                                              \
    [self didChangeValueForKey:@"last"];                                                              \
}                                                                                                     \
                                                                                                      \
- (id)last {                                                                                          \
    return metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i)));                                        \
}                                                                                                     \
                                                                                                      \
- (void)setLast:(id)last {                                                                            \
    self.hashValue ^= (NSUInteger)metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i)));                 \
    [self willChangeValueForKey:@metamacro_stringify(Z_ORDINAL_AT(metamacro_dec(i)))];                 \
    metamacro_concat(_, Z_ORDINAL_AT(metamacro_dec(i))) = last;                                        \
    self.hashValue ^= (NSUInteger)last;                                                               \
    [self didChangeValueForKey:@metamacro_stringify(Z_ORDINAL_AT(metamacro_dec(i)))];                  \
}                                                                                                     \
                                                                                                      \
@end

#define Z_TUPLE_IMP_FOREACH(index, _)           Z_TUPLE_IMP(metamacro_inc(index))

metamacro_for_cxt(20, Z_TUPLE_IMP_FOREACH, ;, _)
