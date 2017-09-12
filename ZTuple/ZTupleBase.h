//
//  ZTupleBase.h
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import <Foundation/Foundation.h>

@interface ZTupleBase : NSObject <NSCopying, NSFastEnumeration>

@property (nonatomic, assign) NSUInteger hashValue;
@property (nonatomic, assign, readonly) NSUInteger count;

+ (instancetype)tupleWithArray:(NSArray *)array;

- (id)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
- (__kindof ZTupleBase *)join:(ZTupleBase *)other;
- (__kindof ZTupleBase *)take:(NSUInteger)count;
- (__kindof ZTupleBase *)drop:(NSUInteger)count;
- (NSArray *)allObjects;

@end
