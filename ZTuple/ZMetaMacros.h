//
//  ZZs.h
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import <Foundation/Foundation.h>
#import <ZTuple/ZTupleBase.h>


// Origin data

#define Z_ORDINAL_NUMBERS                                   first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth, eleventh, twelfth, thirteenth, fourteenth, fifteenth, sixteenth, seventeenth, eighteenth, nineteenth, twentieth
#define Z_ORDINAL_CAP_NUMBERS                               First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Ninth, Tenth, Eleventh, Twelfth, Thirteenth, Fourteenth, Fifteenth, Sixteenth, Seventeenth, Eighteenth, Nineteenth, Twentieth
#define Z_CHARS                                             A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z

// Meta macro method

#define Z_STRINGIFY(VALUE)                                  Z_STRINGIFY_(VALUE)
#define Z_STRINGIFY_(VALUE)                                 # VALUE

#define Z_CONCAT(A, B)                                      Z_CONCAT_(A, B)
#define Z_CONCAT_(A, B)                                     A ## B

#define Z_ARG_HEAD(FIRST, ...)                              FIRST
#define Z_ARG_TAIL(FIRST, ...)                              __VA_ARGS__

#define Z_ARG_AT(N, ...)                                    Z_ARG_AT_(N, __VA_ARGS__)
#define Z_ARG_AT_(N, ...)                                   Z_CONCAT(Z_ARG_AT, N)(__VA_ARGS__)
#define Z_ARG_AT0(...)                                      Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT1(_0, ...)                                  Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT2(_0, _1, ...)                              Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT3(_0, _1, _2, ...)                          Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT4(_0, _1, _2, _3, ...)                      Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT5(_0, _1, _2, _3, _4, ...)                  Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT6(_0, _1, _2, _3, _4, _5, ...)              Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT7(_0, _1, _2, _3, _4, _5, _6, ...)          Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT8(_0, _1, _2, _3, _4, _5, _6, _7, ...)      Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...)  Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...)                                                                \
    Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...)                                                           \
    Z_ARG_HEAD(__VA_ARGS__)
#define Z_ARG_AT12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...)                                                      \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...)                                                 \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...)                                            \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...)                                       \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...)                                  \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...)                             \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...)                        \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...)                   \
    Z_ARG_HEAD(__VA_ARGS__)                                                                                                    
#define Z_ARG_AT20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...)              \
    Z_ARG_HEAD(__VA_ARGS__)

#define Z_DEC(VAL)                                          Z_ARG_AT(VAL, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19)
#define Z_INC(VAL)                                          Z_ARG_AT(VAL, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)
#define Z_ARG_COUNT(...)                                    Z_ARG_AT(20, ##__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define Z_TAKE(N, ...)                                      Z_CONCAT(Z_TAKE, N)(__VA_ARGS__)
#define Z_TAKE0(...)
#define Z_TAKE1(...)                                        Z_ARG_HEAD(__VA_ARGS__)
#define Z_TAKE2(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE1(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE3(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE2(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE4(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE3(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE5(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE4(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE6(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE5(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE7(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE6(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE8(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE7(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE9(...)                                        Z_ARG_HEAD(__VA_ARGS__), Z_TAKE8(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE10(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE9(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE11(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE10(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE12(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE11(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE13(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE12(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE14(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE13(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE15(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE14(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE16(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE15(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE17(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE16(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE18(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE17(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE19(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE18(Z_ARG_TAIL(__VA_ARGS__))
#define Z_TAKE20(...)                                       Z_ARG_HEAD(__VA_ARGS__), Z_TAKE19(Z_ARG_TAIL(__VA_ARGS__))

#define Z_DROP(N, ...)                                      Z_CONCAT(Z_DROP, N)(__VA_ARGS__)
#define Z_DROP0(...)                                        __VA_ARGS__
#define Z_DROP1(...)                                        Z_ARG_TAIL(__VA_ARGS__)
#define Z_DROP2(...)                                        Z_DROP1(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP3(...)                                        Z_DROP2(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP4(...)                                        Z_DROP3(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP5(...)                                        Z_DROP4(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP6(...)                                        Z_DROP5(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP7(...)                                        Z_DROP6(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP8(...)                                        Z_DROP7(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP9(...)                                        Z_DROP8(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP10(...)                                       Z_DROP9(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP11(...)                                       Z_DROP10(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP12(...)                                       Z_DROP11(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP13(...)                                       Z_DROP12(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP14(...)                                       Z_DROP13(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP15(...)                                       Z_DROP14(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP16(...)                                       Z_DROP15(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP17(...)                                       Z_DROP16(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP18(...)                                       Z_DROP17(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP19(...)                                       Z_DROP18(Z_ARG_TAIL(__VA_ARGS__))
#define Z_DROP20(...)                                       Z_DROP19(Z_ARG_TAIL(__VA_ARGS__))

#define Z_INIT(...)                                         Z_TAKE(Z_DEC(Z_ARG_COUNT(__VA_ARGS__)), __VA_ARGS__)
#define Z_LAST(...)                                         Z_DROP(Z_DEC(Z_ARG_COUNT(__VA_ARGS__)), __VA_ARGS__)

#define Z_FOR(COUNT, MARCO, SEP)                            Z_CONCAT(Z_FOR, COUNT)(MARCO, SEP)
#define Z_FOR0(MARCO, SEP)
#define Z_FOR1(MARCO, SEP)                                  MARCO(0)
#define Z_FOR2(MARCO, SEP)                                  Z_FOR1(MARCO, SEP) SEP MARCO(1)
#define Z_FOR3(MARCO, SEP)                                  Z_FOR2(MARCO, SEP) SEP MARCO(2)
#define Z_FOR4(MARCO, SEP)                                  Z_FOR3(MARCO, SEP) SEP MARCO(3)
#define Z_FOR5(MARCO, SEP)                                  Z_FOR4(MARCO, SEP) SEP MARCO(4)
#define Z_FOR6(MARCO, SEP)                                  Z_FOR5(MARCO, SEP) SEP MARCO(5)
#define Z_FOR7(MARCO, SEP)                                  Z_FOR6(MARCO, SEP) SEP MARCO(6)
#define Z_FOR8(MARCO, SEP)                                  Z_FOR7(MARCO, SEP) SEP MARCO(7)
#define Z_FOR9(MARCO, SEP)                                  Z_FOR8(MARCO, SEP) SEP MARCO(8)
#define Z_FOR10(MARCO, SEP)                                 Z_FOR9(MARCO, SEP) SEP MARCO(9)
#define Z_FOR11(MARCO, SEP)                                 Z_FOR10(MARCO, SEP) SEP MARCO(10)
#define Z_FOR12(MARCO, SEP)                                 Z_FOR11(MARCO, SEP) SEP MARCO(11)
#define Z_FOR13(MARCO, SEP)                                 Z_FOR12(MARCO, SEP) SEP MARCO(12)
#define Z_FOR14(MARCO, SEP)                                 Z_FOR13(MARCO, SEP) SEP MARCO(13)
#define Z_FOR15(MARCO, SEP)                                 Z_FOR14(MARCO, SEP) SEP MARCO(14)
#define Z_FOR16(MARCO, SEP)                                 Z_FOR15(MARCO, SEP) SEP MARCO(15)
#define Z_FOR17(MARCO, SEP)                                 Z_FOR16(MARCO, SEP) SEP MARCO(16)
#define Z_FOR18(MARCO, SEP)                                 Z_FOR17(MARCO, SEP) SEP MARCO(17)
#define Z_FOR19(MARCO, SEP)                                 Z_FOR18(MARCO, SEP) SEP MARCO(18)
#define Z_FOR20(MARCO, SEP)                                 Z_FOR19(MARCO, SEP) SEP MARCO(19)

#define Z_FOR_SPACE(COUNT, MARCO)                           Z_CONCAT(Z_FOR_SPACE, COUNT)(MARCO)
#define Z_FOR_SPACE0(MARCO)
#define Z_FOR_SPACE1(MARCO)                                 MARCO(0)
#define Z_FOR_SPACE2(MARCO)                                 Z_FOR_SPACE1(MARCO) MARCO(1)
#define Z_FOR_SPACE3(MARCO)                                 Z_FOR_SPACE2(MARCO) MARCO(2)
#define Z_FOR_SPACE4(MARCO)                                 Z_FOR_SPACE3(MARCO) MARCO(3)
#define Z_FOR_SPACE5(MARCO)                                 Z_FOR_SPACE4(MARCO) MARCO(4)
#define Z_FOR_SPACE6(MARCO)                                 Z_FOR_SPACE5(MARCO) MARCO(5)
#define Z_FOR_SPACE7(MARCO)                                 Z_FOR_SPACE6(MARCO) MARCO(6)
#define Z_FOR_SPACE8(MARCO)                                 Z_FOR_SPACE7(MARCO) MARCO(7)
#define Z_FOR_SPACE9(MARCO)                                 Z_FOR_SPACE8(MARCO) MARCO(8)
#define Z_FOR_SPACE10(MARCO)                                Z_FOR_SPACE9(MARCO) MARCO(9)
#define Z_FOR_SPACE11(MARCO)                                Z_FOR_SPACE10(MARCO) MARCO(10)
#define Z_FOR_SPACE12(MARCO)                                Z_FOR_SPACE11(MARCO) MARCO(11)
#define Z_FOR_SPACE13(MARCO)                                Z_FOR_SPACE12(MARCO) MARCO(12)
#define Z_FOR_SPACE14(MARCO)                                Z_FOR_SPACE13(MARCO) MARCO(13)
#define Z_FOR_SPACE15(MARCO)                                Z_FOR_SPACE14(MARCO) MARCO(14)
#define Z_FOR_SPACE16(MARCO)                                Z_FOR_SPACE15(MARCO) MARCO(15)
#define Z_FOR_SPACE17(MARCO)                                Z_FOR_SPACE16(MARCO) MARCO(16)
#define Z_FOR_SPACE18(MARCO)                                Z_FOR_SPACE17(MARCO) MARCO(17)
#define Z_FOR_SPACE19(MARCO)                                Z_FOR_SPACE18(MARCO) MARCO(18)
#define Z_FOR_SPACE20(MARCO)                                Z_FOR_SPACE19(MARCO) MARCO(19)

#define Z_FOR_RECURSIVE(COUNT, MARCO, SEP)                  Z_CONCAT(Z_FOR_RECURSIVE, COUNT)(MARCO, SEP)
#define Z_FOR_RECURSIVE0(MARCO, SEP)
#define Z_FOR_RECURSIVE1(MARCO, SEP)                        MARCO(0)
#define Z_FOR_RECURSIVE2(MARCO, SEP)                        Z_FOR_RECURSIVE1(MARCO, SEP) SEP MARCO(1)
#define Z_FOR_RECURSIVE3(MARCO, SEP)                        Z_FOR_RECURSIVE2(MARCO, SEP) SEP MARCO(2)
#define Z_FOR_RECURSIVE4(MARCO, SEP)                        Z_FOR_RECURSIVE3(MARCO, SEP) SEP MARCO(3)
#define Z_FOR_RECURSIVE5(MARCO, SEP)                        Z_FOR_RECURSIVE4(MARCO, SEP) SEP MARCO(4)
#define Z_FOR_RECURSIVE6(MARCO, SEP)                        Z_FOR_RECURSIVE5(MARCO, SEP) SEP MARCO(5)
#define Z_FOR_RECURSIVE7(MARCO, SEP)                        Z_FOR_RECURSIVE6(MARCO, SEP) SEP MARCO(6)
#define Z_FOR_RECURSIVE8(MARCO, SEP)                        Z_FOR_RECURSIVE7(MARCO, SEP) SEP MARCO(7)
#define Z_FOR_RECURSIVE9(MARCO, SEP)                        Z_FOR_RECURSIVE8(MARCO, SEP) SEP MARCO(8)
#define Z_FOR_RECURSIVE10(MARCO, SEP)                       Z_FOR_RECURSIVE9(MARCO, SEP) SEP MARCO(9)
#define Z_FOR_RECURSIVE11(MARCO, SEP)                       Z_FOR_RECURSIVE10(MARCO, SEP) SEP MARCO(10)
#define Z_FOR_RECURSIVE12(MARCO, SEP)                       Z_FOR_RECURSIVE11(MARCO, SEP) SEP MARCO(11)
#define Z_FOR_RECURSIVE13(MARCO, SEP)                       Z_FOR_RECURSIVE12(MARCO, SEP) SEP MARCO(12)
#define Z_FOR_RECURSIVE14(MARCO, SEP)                       Z_FOR_RECURSIVE13(MARCO, SEP) SEP MARCO(13)
#define Z_FOR_RECURSIVE15(MARCO, SEP)                       Z_FOR_RECURSIVE14(MARCO, SEP) SEP MARCO(14)
#define Z_FOR_RECURSIVE16(MARCO, SEP)                       Z_FOR_RECURSIVE15(MARCO, SEP) SEP MARCO(15)
#define Z_FOR_RECURSIVE17(MARCO, SEP)                       Z_FOR_RECURSIVE16(MARCO, SEP) SEP MARCO(16)
#define Z_FOR_RECURSIVE18(MARCO, SEP)                       Z_FOR_RECURSIVE17(MARCO, SEP) SEP MARCO(17)
#define Z_FOR_RECURSIVE19(MARCO, SEP)                       Z_FOR_RECURSIVE18(MARCO, SEP) SEP MARCO(18)
#define Z_FOR_RECURSIVE20(MARCO, SEP)                       Z_FOR_RECURSIVE19(MARCO, SEP) SEP MARCO(19)

#define Z_FOR_COMMA(COUNT, MARCO)                           Z_CONCAT(Z_FOR_COMMA, COUNT)(MARCO)
#define Z_FOR_COMMA0(MARCO)
#define Z_FOR_COMMA1(MARCO)                                 MARCO(0)
#define Z_FOR_COMMA2(MARCO)                                 Z_FOR_COMMA1(MARCO), MARCO(1)
#define Z_FOR_COMMA3(MARCO)                                 Z_FOR_COMMA2(MARCO), MARCO(2)
#define Z_FOR_COMMA4(MARCO)                                 Z_FOR_COMMA3(MARCO), MARCO(3)
#define Z_FOR_COMMA5(MARCO)                                 Z_FOR_COMMA4(MARCO), MARCO(4)
#define Z_FOR_COMMA6(MARCO)                                 Z_FOR_COMMA5(MARCO), MARCO(5)
#define Z_FOR_COMMA7(MARCO)                                 Z_FOR_COMMA6(MARCO), MARCO(6)
#define Z_FOR_COMMA8(MARCO)                                 Z_FOR_COMMA7(MARCO), MARCO(7)
#define Z_FOR_COMMA9(MARCO)                                 Z_FOR_COMMA8(MARCO), MARCO(8)
#define Z_FOR_COMMA10(MARCO)                                Z_FOR_COMMA9(MARCO), MARCO(9)
#define Z_FOR_COMMA11(MARCO)                                Z_FOR_COMMA10(MARCO), MARCO(10)
#define Z_FOR_COMMA12(MARCO)                                Z_FOR_COMMA11(MARCO), MARCO(11)
#define Z_FOR_COMMA13(MARCO)                                Z_FOR_COMMA12(MARCO), MARCO(12)
#define Z_FOR_COMMA14(MARCO)                                Z_FOR_COMMA13(MARCO), MARCO(13)
#define Z_FOR_COMMA15(MARCO)                                Z_FOR_COMMA14(MARCO), MARCO(14)
#define Z_FOR_COMMA16(MARCO)                                Z_FOR_COMMA15(MARCO), MARCO(15)
#define Z_FOR_COMMA17(MARCO)                                Z_FOR_COMMA16(MARCO), MARCO(16)
#define Z_FOR_COMMA18(MARCO)                                Z_FOR_COMMA17(MARCO), MARCO(17)
#define Z_FOR_COMMA19(MARCO)                                Z_FOR_COMMA18(MARCO), MARCO(18)
#define Z_FOR_COMMA20(MARCO)                                Z_FOR_COMMA19(MARCO), MARCO(19)

#define Z_FOR_EACH(MACRO, SEP, ...)                         Z_FOR_EACH_CTX(Z_FOR_EACH_ITER_, SEP, MACRO, ##__VA_ARGS__)
#define Z_FOR_EACH_ITER_(INDEX, PARAM, MACRO)               MACRO(INDEX, PARAM)

#define Z_FOR_EACH_CTX(MACRO, SEP, CTX, ...)                Z_CONCAT(Z_FOR_EACH_CTX, Z_ARG_COUNT(__VA_ARGS__))(MACRO, SEP, CTX, ##__VA_ARGS__)
#define Z_FOR_EACH_CTX0(MACRO, SEP, CTX)
#define Z_FOR_EACH_CTX1(MACRO, SEP, CTX, _0) MACRO(0, _0, CTX)
#define Z_FOR_EACH_CTX2(MACRO, SEP, CTX, _0, _1) \
    Z_FOR_EACH_CTX1(MACRO, SEP, CTX, _0) SEP MACRO(1, _1, CTX)
#define Z_FOR_EACH_CTX3(MACRO, SEP, CTX, _0, _1, _2) \
    Z_FOR_EACH_CTX2(MACRO, SEP, CTX, _0, _1) SEP MACRO(2, _2, CTX)
#define Z_FOR_EACH_CTX4(MACRO, SEP, CTX, _0, _1, _2, _3) \
    Z_FOR_EACH_CTX3(MACRO, SEP, CTX, _0, _1, _2) SEP MACRO(3, _3, CTX)
#define Z_FOR_EACH_CTX5(MACRO, SEP, CTX, _0, _1, _2, _3, _4) \
    Z_FOR_EACH_CTX4(MACRO, SEP, CTX, _0, _1, _2, _3) SEP MACRO(4, _4, CTX)
#define Z_FOR_EACH_CTX6(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5) \
    Z_FOR_EACH_CTX5(MACRO, SEP, CTX, _0, _1, _2, _3, _4) SEP MACRO(5, _5, CTX)
#define Z_FOR_EACH_CTX7(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6) \
    Z_FOR_EACH_CTX6(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5) SEP MACRO(6, _6, CTX)
#define Z_FOR_EACH_CTX8(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7) \
    Z_FOR_EACH_CTX7(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6) SEP MACRO(7, _7, CTX)
#define Z_FOR_EACH_CTX9(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    Z_FOR_EACH_CTX8(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7) SEP MACRO(8, _8, CTX)
#define Z_FOR_EACH_CTX10(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    Z_FOR_EACH_CTX9(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8) SEP MACRO(9, _9, CTX)
#define Z_FOR_EACH_CTX11(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    Z_FOR_EACH_CTX10(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) SEP MACRO(10, _10, CTX)
#define Z_FOR_EACH_CTX12(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    Z_FOR_EACH_CTX11(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) SEP MACRO(11, _11, CTX)
#define Z_FOR_EACH_CTX13(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    Z_FOR_EACH_CTX12(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) SEP MACRO(12, _12, CTX)
#define Z_FOR_EACH_CTX14(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    Z_FOR_EACH_CTX13(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) SEP MACRO(13, _13, CTX)
#define Z_FOR_EACH_CTX15(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    Z_FOR_EACH_CTX14(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) SEP MACRO(14, _14, CTX)
#define Z_FOR_EACH_CTX16(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    Z_FOR_EACH_CTX15(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) SEP MACRO(15, _15, CTX)
#define Z_FOR_EACH_CTX17(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    Z_FOR_EACH_CTX16(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) SEP MACRO(16, _16, CTX)
#define Z_FOR_EACH_CTX18(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    Z_FOR_EACH_CTX17(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) SEP MACRO(17, _17, CTX)
#define Z_FOR_EACH_CTX19(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    Z_FOR_EACH_CTX18(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) SEP MACRO(18, _18, CTX)
#define Z_FOR_EACH_CTX20(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    Z_FOR_EACH_CTX19(MACRO, SEP, CTX, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) SEP MACRO(19, _19, CTX)

#define Z_IF_EQ(A, B)                                       Z_CONCAT(Z_IF_EQ, A)(B)

#define Z_CONSUME_(...)
#define Z_EXPAND_(...)                                      __VA_ARGS__

#define Z_IF_EQ0(VALUE)                                     Z_CONCAT(Z_IF_EQ0_, VALUE)
#define Z_IF_EQ0_0(...)                                     __VA_ARGS__ Z_CONSUME_
#define Z_IF_EQ0_1(...)                                     Z_EXPAND_
#define Z_IF_EQ0_2(...)                                     Z_EXPAND_
#define Z_IF_EQ0_3(...)                                     Z_EXPAND_
#define Z_IF_EQ0_4(...)                                     Z_EXPAND_
#define Z_IF_EQ0_5(...)                                     Z_EXPAND_
#define Z_IF_EQ0_6(...)                                     Z_EXPAND_
#define Z_IF_EQ0_7(...)                                     Z_EXPAND_
#define Z_IF_EQ0_8(...)                                     Z_EXPAND_
#define Z_IF_EQ0_9(...)                                     Z_EXPAND_
#define Z_IF_EQ0_10(...)                                    Z_EXPAND_
#define Z_IF_EQ0_11(...)                                    Z_EXPAND_
#define Z_IF_EQ0_12(...)                                    Z_EXPAND_
#define Z_IF_EQ0_13(...)                                    Z_EXPAND_
#define Z_IF_EQ0_14(...)                                    Z_EXPAND_
#define Z_IF_EQ0_15(...)                                    Z_EXPAND_
#define Z_IF_EQ0_16(...)                                    Z_EXPAND_
#define Z_IF_EQ0_17(...)                                    Z_EXPAND_
#define Z_IF_EQ0_18(...)                                    Z_EXPAND_
#define Z_IF_EQ0_19(...)                                    Z_EXPAND_
#define Z_IF_EQ0_20(...)                                    Z_EXPAND_

#define Z_IF_EQ1(VALUE)                                     Z_IF_EQ0(Z_DEC(VALUE))
#define Z_IF_EQ2(VALUE)                                     Z_IF_EQ1(Z_DEC(VALUE))
#define Z_IF_EQ3(VALUE)                                     Z_IF_EQ2(Z_DEC(VALUE))
#define Z_IF_EQ4(VALUE)                                     Z_IF_EQ3(Z_DEC(VALUE))
#define Z_IF_EQ5(VALUE)                                     Z_IF_EQ4(Z_DEC(VALUE))
#define Z_IF_EQ6(VALUE)                                     Z_IF_EQ5(Z_DEC(VALUE))
#define Z_IF_EQ7(VALUE)                                     Z_IF_EQ6(Z_DEC(VALUE))
#define Z_IF_EQ8(VALUE)                                     Z_IF_EQ7(Z_DEC(VALUE))
#define Z_IF_EQ9(VALUE)                                     Z_IF_EQ8(Z_DEC(VALUE))
#define Z_IF_EQ10(VALUE)                                    Z_IF_EQ9(Z_DEC(VALUE))
#define Z_IF_EQ11(VALUE)                                    Z_IF_EQ10(Z_DEC(VALUE))
#define Z_IF_EQ12(VALUE)                                    Z_IF_EQ11(Z_DEC(VALUE))
#define Z_IF_EQ13(VALUE)                                    Z_IF_EQ12(Z_DEC(VALUE))
#define Z_IF_EQ14(VALUE)                                    Z_IF_EQ13(Z_DEC(VALUE))
#define Z_IF_EQ15(VALUE)                                    Z_IF_EQ14(Z_DEC(VALUE))
#define Z_IF_EQ16(VALUE)                                    Z_IF_EQ15(Z_DEC(VALUE))
#define Z_IF_EQ17(VALUE)                                    Z_IF_EQ16(Z_DEC(VALUE))
#define Z_IF_EQ18(VALUE)                                    Z_IF_EQ17(Z_DEC(VALUE))
#define Z_IF_EQ19(VALUE)                                    Z_IF_EQ18(Z_DEC(VALUE))
#define Z_IF_EQ20(VALUE)                                    Z_IF_EQ19(Z_DEC(VALUE))

// Functions

#define Z_ORDINAL_AT(N)                                     Z_ARG_AT(N, Z_ORDINAL_NUMBERS)
#define Z_ORDINAL_CAP_AT(N)                                 Z_ARG_AT(N, Z_ORDINAL_CAP_NUMBERS)
#define Z_CHARS_AT(N)                                       Z_ARG_AT(N, Z_CHARS)

#define Z_GENERIC_TYPE(index)                               __covariant Z_CHARS_AT(index): id
#define Z_PROPERTY_DEF(index)                               @property (nonatomic, strong) Z_CHARS_AT(index) Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM_FIRST(index)                          Z_ORDINAL_CAP_AT(index):(Z_CHARS_AT(index))Z_ORDINAL_AT(index)
#define _Z_INIT_PARAM(index)                                Z_ORDINAL_AT(index):(Z_CHARS_AT(index))Z_ORDINAL_AT(index)
#define Z_INIT_PARAM(index)                                 Z_IF_EQ(0, index)(_Z_INIT_PARAM_FIRST(index))(_Z_INIT_PARAM(index))

#define Z_TUPLE_DEF(i)                                                                                                         \
@interface Z_CONCAT(ZTuple, i)<Z_FOR_COMMA(i, Z_GENERIC_TYPE)> :ZTupleBase                                                     \
                                                                                                                               \
Z_FOR_RECURSIVE(i, Z_PROPERTY_DEF, ;);                                                                                         \
                                                                                                                               \
@property (nonatomic, strong) Z_CHARS_AT(Z_DEC(i)) last;                                                                       \
                                                                                                                               \
- (instancetype)Z_CONCAT(initWith, Z_FOR_SPACE(i, Z_INIT_PARAM));                                                              \
                                                                                                                               \
@end

#define Z_TUPLE_DEF_FOREACH(index)                          Z_TUPLE_DEF(Z_INC(index))

#define Z_TUPLE_CLASSES_DEF                                 Z_FOR(20, Z_TUPLE_DEF_FOREACH, ;)

#define _Z_INIT_PARAM_CALL_FIRST(index, param)              Z_ORDINAL_CAP_AT(index):param
#define _Z_INIT_PARAM_CALL(index, param)                    Z_ORDINAL_AT(index):param
#define Z_INIT_PARAM_CALL(index, param)                     Z_IF_EQ(0, index)(_Z_INIT_PARAM_CALL_FIRST(index, param))(_Z_INIT_PARAM_CALL(index, param))

#define ZTuple(...)                                         [[Z_CONCAT(ZTuple, Z_ARG_COUNT(__VA_ARGS__)) alloc] Z_CONCAT(initWith, Z_FOR_EACH(Z_INIT_PARAM_CALL, ,__VA_ARGS__))]

#define Z_FromVar(tuple)                                    (tuple)

#define Z_UNPACK(index, param, tuple)                       param = [tuple Z_ORDINAL_AT(index)]

#define ZTupleUnpack(...)                                   Z_FOR_EACH_CTX_(Z_UNPACK, ;, Z_LAST(__VA_ARGS__), Z_INIT(__VA_ARGS__))
#define Z_FOR_EACH_CTX_(...)                                Z_FOR_EACH_CTX(__VA_ARGS__)

#define ZTupleExtend(tuple, ...)                            [tuple join:ZTuple(__VA_ARGS__)]
