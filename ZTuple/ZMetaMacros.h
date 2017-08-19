//
//  ZMetaMacros.h
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import <Foundation/Foundation.h>
#import <libextobjc/metamacros.h>
#import <ZTuple/ZTupleBase.h>

#define Z_ORDINAL_NUMBERS                                   first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth, eleventh, twelfth, thirteenth, fourteenth, fifteenth, sixteenth, seventeenth, eighteenth, nineteenth, twentieth
#define Z_ORDINAL_CAP_NUMBERS                               First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Ninth, Tenth, Eleventh, Twelfth, Thirteenth, Fourteenth, Fifteenth, Sixteenth, Seventeenth, Eighteenth, Nineteenth, Twentieth
#define Z_CHARS                                             A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
                                                            
#define Z_ORDINAL_AT(i)                                     metamacro_at(i, Z_ORDINAL_NUMBERS)
#define Z_ORDINAL_CAP_AT(i)                                 metamacro_at(i, Z_ORDINAL_CAP_NUMBERS)
#define Z_CHARS_AT(i)                                       metamacro_at(i, Z_CHARS)
                                                            
#define metamacro_for_comma(COUNT, MACRO, CONTEXT)          metamacro_concat(metamacro_for_comma, COUNT)(MACRO, CONTEXT)
                                                            
#define metamacro_for_comma0(MACRO, CONTEXT)                
#define metamacro_for_comma1(MACRO, CONTEXT)                MACRO(0, CONTEXT)
#define metamacro_for_comma2(MACRO, CONTEXT)                metamacro_for_comma1(MACRO, CONTEXT), MACRO(1, CONTEXT)
#define metamacro_for_comma3(MACRO, CONTEXT)                metamacro_for_comma2(MACRO, CONTEXT), MACRO(2, CONTEXT)
#define metamacro_for_comma4(MACRO, CONTEXT)                metamacro_for_comma3(MACRO, CONTEXT), MACRO(3, CONTEXT)
#define metamacro_for_comma5(MACRO, CONTEXT)                metamacro_for_comma4(MACRO, CONTEXT), MACRO(4, CONTEXT)
#define metamacro_for_comma6(MACRO, CONTEXT)                metamacro_for_comma5(MACRO, CONTEXT), MACRO(5, CONTEXT)
#define metamacro_for_comma7(MACRO, CONTEXT)                metamacro_for_comma6(MACRO, CONTEXT), MACRO(6, CONTEXT)
#define metamacro_for_comma8(MACRO, CONTEXT)                metamacro_for_comma7(MACRO, CONTEXT), MACRO(7, CONTEXT)
#define metamacro_for_comma9(MACRO, CONTEXT)                metamacro_for_comma8(MACRO, CONTEXT), MACRO(8, CONTEXT)
#define metamacro_for_comma10(MACRO, CONTEXT)               metamacro_for_comma9(MACRO, CONTEXT), MACRO(9, CONTEXT)
#define metamacro_for_comma11(MACRO, CONTEXT)               metamacro_for_comma10(MACRO, CONTEXT), MACRO(10, CONTEXT)
#define metamacro_for_comma12(MACRO, CONTEXT)               metamacro_for_comma11(MACRO, CONTEXT), MACRO(11, CONTEXT)
#define metamacro_for_comma13(MACRO, CONTEXT)               metamacro_for_comma12(MACRO, CONTEXT), MACRO(12, CONTEXT)
#define metamacro_for_comma14(MACRO, CONTEXT)               metamacro_for_comma13(MACRO, CONTEXT), MACRO(13, CONTEXT)
#define metamacro_for_comma15(MACRO, CONTEXT)               metamacro_for_comma14(MACRO, CONTEXT), MACRO(14, CONTEXT)
#define metamacro_for_comma16(MACRO, CONTEXT)               metamacro_for_comma15(MACRO, CONTEXT), MACRO(15, CONTEXT)
#define metamacro_for_comma17(MACRO, CONTEXT)               metamacro_for_comma16(MACRO, CONTEXT), MACRO(16, CONTEXT)
#define metamacro_for_comma18(MACRO, CONTEXT)               metamacro_for_comma17(MACRO, CONTEXT), MACRO(17, CONTEXT)
#define metamacro_for_comma19(MACRO, CONTEXT)               metamacro_for_comma18(MACRO, CONTEXT), MACRO(18, CONTEXT)
#define metamacro_for_comma20(MACRO, CONTEXT)               metamacro_for_comma19(MACRO, CONTEXT), MACRO(19, CONTEXT)

#define metamacro_for_recursive(COUNT, MACRO, SEP, CONTEXT) metamacro_concat(metamacro_for_recursive, COUNT)(MACRO, SEP, CONTEXT)

#define metamacro_for_recursive0(MACRO, SEP, CONTEXT)
#define metamacro_for_recursive1(MACRO, SEP, CONTEXT)       MACRO(0, CONTEXT)
#define metamacro_for_recursive2(MACRO, SEP, CONTEXT)       metamacro_for_recursive1(MACRO, SEP, CONTEXT) SEP MACRO(1, CONTEXT)
#define metamacro_for_recursive3(MACRO, SEP, CONTEXT)       metamacro_for_recursive2(MACRO, SEP, CONTEXT) SEP MACRO(2, CONTEXT)
#define metamacro_for_recursive4(MACRO, SEP, CONTEXT)       metamacro_for_recursive3(MACRO, SEP, CONTEXT) SEP MACRO(3, CONTEXT)
#define metamacro_for_recursive5(MACRO, SEP, CONTEXT)       metamacro_for_recursive4(MACRO, SEP, CONTEXT) SEP MACRO(4, CONTEXT)
#define metamacro_for_recursive6(MACRO, SEP, CONTEXT)       metamacro_for_recursive5(MACRO, SEP, CONTEXT) SEP MACRO(5, CONTEXT)
#define metamacro_for_recursive7(MACRO, SEP, CONTEXT)       metamacro_for_recursive6(MACRO, SEP, CONTEXT) SEP MACRO(6, CONTEXT)
#define metamacro_for_recursive8(MACRO, SEP, CONTEXT)       metamacro_for_recursive7(MACRO, SEP, CONTEXT) SEP MACRO(7, CONTEXT)
#define metamacro_for_recursive9(MACRO, SEP, CONTEXT)       metamacro_for_recursive8(MACRO, SEP, CONTEXT) SEP MACRO(8, CONTEXT)
#define metamacro_for_recursive10(MACRO, SEP, CONTEXT)      metamacro_for_recursive9(MACRO, SEP, CONTEXT) SEP MACRO(9, CONTEXT)
#define metamacro_for_recursive11(MACRO, SEP, CONTEXT)      metamacro_for_recursive10(MACRO, SEP, CONTEXT) SEP MACRO(10, CONTEXT)
#define metamacro_for_recursive12(MACRO, SEP, CONTEXT)      metamacro_for_recursive11(MACRO, SEP, CONTEXT) SEP MACRO(11, CONTEXT)
#define metamacro_for_recursive13(MACRO, SEP, CONTEXT)      metamacro_for_recursive12(MACRO, SEP, CONTEXT) SEP MACRO(12, CONTEXT)
#define metamacro_for_recursive14(MACRO, SEP, CONTEXT)      metamacro_for_recursive13(MACRO, SEP, CONTEXT) SEP MACRO(13, CONTEXT)
#define metamacro_for_recursive15(MACRO, SEP, CONTEXT)      metamacro_for_recursive14(MACRO, SEP, CONTEXT) SEP MACRO(14, CONTEXT)
#define metamacro_for_recursive16(MACRO, SEP, CONTEXT)      metamacro_for_recursive15(MACRO, SEP, CONTEXT) SEP MACRO(15, CONTEXT)
#define metamacro_for_recursive17(MACRO, SEP, CONTEXT)      metamacro_for_recursive16(MACRO, SEP, CONTEXT) SEP MACRO(16, CONTEXT)
#define metamacro_for_recursive18(MACRO, SEP, CONTEXT)      metamacro_for_recursive17(MACRO, SEP, CONTEXT) SEP MACRO(17, CONTEXT)
#define metamacro_for_recursive19(MACRO, SEP, CONTEXT)      metamacro_for_recursive18(MACRO, SEP, CONTEXT) SEP MACRO(18, CONTEXT)
#define metamacro_for_recursive20(MACRO, SEP, CONTEXT)      metamacro_for_recursive19(MACRO, SEP, CONTEXT) SEP MACRO(19, CONTEXT)

#define Z_GENERIC_TYPE(index, _)                            __covariant Z_CHARS_AT(index): id
#define Z_PROPERTY_DEF(index, _)                            @property (nonatomic, strong) Z_CHARS_AT(index) Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM_FIRST(index)                          Z_ORDINAL_CAP_AT(index):(Z_CHARS_AT(index))Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM(index)                                Z_ORDINAL_AT(index):(Z_CHARS_AT(index))Z_ORDINAL_AT(index)
#define Z_INIT_PARAM(index, _)                              metamacro_if_eq(0, index)(_Z_INIT_PARAM_FIRST(index))(_Z_INIT_PARAM(index))

#define Z_TUPLE_DEF(i)                                                                                                           \
@interface metamacro_concat(ZTuple, i)<metamacro_for_comma(i, Z_GENERIC_TYPE, _)> :ZTupleBase                                    \
                                                                                                                                 \
metamacro_for_recursive(i, Z_PROPERTY_DEF, ;, _);                                                                                \
                                                                                                                                 \
@property (nonatomic, strong) Z_CHARS_AT(metamacro_dec(i)) last;                                                                 \
                                                                                                                                 \
- (instancetype)metamacro_concat(initWith, metamacro_for_recursive(i, Z_INIT_PARAM, , _));                                       \
                                                                                                                                 \
@end

#define Z_TUPLE_DEF_FOREACH(index, _)                       Z_TUPLE_DEF(metamacro_inc(index))

metamacro_for_cxt(20, Z_TUPLE_DEF_FOREACH, ;, _)

#define _Z_INIT_PARAM_CALL_FIRST(index, param)              Z_ORDINAL_CAP_AT(index):param
#define _Z_INIT_PARAM_CALL(index, param)                    Z_ORDINAL_AT(index):param
#define Z_INIT_PARAM_CALL(index, param)                     metamacro_if_eq(0, index)(_Z_INIT_PARAM_CALL_FIRST(index, param))(_Z_INIT_PARAM_CALL(index, param))

#define ZTuple(...)                                         [[metamacro_concat(ZTuple, metamacro_argcount(__VA_ARGS__)) alloc] metamacro_concat(initWith, metamacro_foreach(Z_INIT_PARAM_CALL, ,__VA_ARGS__))]

#define Z_FromVar(tuple)                                    (tuple)

#define metamacro_init(...)                                 metamacro_take(metamacro_dec(metamacro_argcount(__VA_ARGS__)), __VA_ARGS__)
#define metamacro_last(...)                                 metamacro_drop(metamacro_dec(metamacro_argcount(__VA_ARGS__)), __VA_ARGS__)

#define Z_UNPACK(index, value, param)                       param = [value Z_ORDINAL_AT(index)]

#define ZTupleUnpack(...)                                   metamacro_foreach_cxt(Z_UNPACK, ;, metamacro_last(__VA_ARGS__), metamacro_init(__VA_ARGS__))

#define ZTupleExtend(tuple, ...)                            [tuple join:ZTuple(__VA_ARGS__)]
