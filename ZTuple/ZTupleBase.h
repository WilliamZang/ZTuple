//
//  ZTupleBase.h
//  Expecta
//
//  Created by Chengwei Zang on 2017/8/3.
//

#import <Foundation/Foundation.h>

@interface ZTupleBase : NSObject <NSCopying, NSFastEnumeration>

@property (nonatomic, assign) NSUInteger hashValue;

- (id)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
- (__kindof ZTupleBase *)join:(ZTupleBase *)other;

@end
