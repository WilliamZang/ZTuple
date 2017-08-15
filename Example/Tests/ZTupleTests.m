//
//  ZTupleTests.m
//  ZTupleTests
//
//  Created by WilliamZang on 08/03/2017.
//  Copyright (c) 2017 WilliamZang. All rights reserved.
//

// https://github.com/Specta/Specta

void enumerationMutationHandler(id object) {
    [[NSThread currentThread] threadDictionary][@"mutationErrorObject"] = object;
}

SpecBegin(ZTupleTests)

describe(@"tuple tests", ^{
    context(@"ordinal property", ^{
        it(@"can access tuple using properties", ^{
            ZTuple3<NSNumber *, NSString *, NSDictionary *> *tuple = [[ZTuple3 alloc] initWithFirst:@3 second:@"string" third:@{@"key": @"value"}];
            
            expect(tuple.first).to.equal(@3);
            expect(tuple.second).to.equal(@"string");
            expect(tuple.third).to.equal(@{@"key": @"value"});
            expect(tuple.last).to.equal(tuple.third);
            
            tuple.first = @5;
            expect(tuple.first).to.equal(@5);
            
            tuple.last = @{@"key": @"value2"};
            expect(tuple.third).to.equal(@{@"key": @"value2"});
        });
        
        it(@"can create a new tuple using macro", ^{
            ZTuple4<NSNumber *, NSNumber *, NSNumber *, NSNumber *> *tuple = ZTuple(@1, @2, @3, @4);
            
            expect(tuple.first).to.equal(@1);
            expect(tuple.second).to.equal(@2);
            expect(tuple.third).to.equal(@3);
            expect(tuple.fourth).to.equal(@4);
            expect(tuple.last).to.equal(@4);
        });
        
        it(@"can unpack tuple using macro", ^{
            ZTuple4<NSNumber *, NSNumber *, NSNumber *, NSNumber *> *tuple = ZTuple(@1, @2, @3, @4);
            
            ZTupleUnpack(NSNumber *a, NSNumber *b, NSNumber *c, NSNumber *d, Z_FromVar(tuple));
            
            expect(a).to.equal(@1);
            expect(b).to.equal(@2);
            expect(c).to.equal(@3);
            expect(d).to.equal(@4);
        });
        
        it(@"can invoke KVO", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            
            id observer = [OCMockObject mockForClass:NSObject.class];
            
            [[observer expect] observeValueForKeyPath:@"second"
                                             ofObject:tuple
                                               change:@{NSKeyValueChangeNewKey: @5,
                                                        NSKeyValueChangeKindKey: @(NSKeyValueChangeSetting)
                                                        }
                                              context:OCMArg.anyPointer];
            
            [tuple addObserver:observer
                    forKeyPath:@"second"
                       options:NSKeyValueObservingOptionNew
                       context:NULL];
            
            tuple.second = @5;
            
            [observer verify];
            
            [tuple removeObserver:observer forKeyPath:@"second"];
        });
        
        it(@"can observe property named last, will invoke observe callback when set the last ordinal oproperty", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            
            id observer1 = [OCMockObject mockForClass:NSObject.class];
            id observer2 = [OCMockObject mockForClass:NSObject.class];
            
            [[observer1 expect] observeValueForKeyPath:@"last"
                                              ofObject:tuple
                                                change:@{NSKeyValueChangeNewKey: @5,
                                                         NSKeyValueChangeKindKey: @(NSKeyValueChangeSetting)
                                                         }
                                               context:OCMArg.anyPointer];
            [[observer2 expect] observeValueForKeyPath:@"third"
                                              ofObject:tuple
                                                change:@{NSKeyValueChangeNewKey: @5,
                                                         NSKeyValueChangeKindKey: @(NSKeyValueChangeSetting)
                                                         }
                                               context:OCMArg.anyPointer];
            
            [tuple addObserver:observer1
                    forKeyPath:@"last"
                       options:NSKeyValueObservingOptionNew
                       context:NULL];
            
            [tuple addObserver:observer2
                    forKeyPath:@"third"
                       options:NSKeyValueObservingOptionNew
                       context:NULL];
            
            tuple.third = @5;
            
            [observer1 verify];
            [observer2 verify];
            
            [[observer1 expect] observeValueForKeyPath:@"last"
                                              ofObject:tuple
                                                change:@{NSKeyValueChangeNewKey: @7,
                                                         NSKeyValueChangeKindKey: @(NSKeyValueChangeSetting)
                                                         }
                                               context:OCMArg.anyPointer];
            [[observer2 expect] observeValueForKeyPath:@"third"
                                              ofObject:tuple
                                                change:@{NSKeyValueChangeNewKey: @7,
                                                         NSKeyValueChangeKindKey: @(NSKeyValueChangeSetting)
                                                         }
                                               context:OCMArg.anyPointer];
            
            tuple.last = @7;
            
            [observer1 verify];
            [observer2 verify];
            
            [tuple removeObserver:observer1 forKeyPath:@"last"];
            [tuple removeObserver:observer2 forKeyPath:@"third"];
        });
    });

    context(@"subscript", ^{
        it(@"can access subscript", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            
            expect(tuple[0]).to.equal(@1);
            expect(tuple[1]).to.equal(@2);
            expect(tuple[2]).to.equal(@3);
            
            tuple[0] = @4;
            
            expect(tuple.first).to.equal(@4);
        });
        
        it(@"will raise an assert if access over subscript", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            id assertHandler = [OCMockObject mockForClass:NSAssertionHandler.class];
            
            [[[assertHandler expect] ignoringNonObjectArgs] handleFailureInMethod:@selector(objectForKeyedSubscript:) object:tuple file:OCMOCK_ANY lineNumber:0 description:@"Invalid parameter not satisfying: %@", @"%@"];
            
            [[[NSThread currentThread] threadDictionary] setValue:assertHandler
                                                           forKey:NSAssertionHandlerKey];
            
            id any __attribute((unused)) = tuple[3];
            
            [assertHandler verify];
            
            [[[assertHandler expect] ignoringNonObjectArgs] handleFailureInMethod:@selector(setObject:atIndexedSubscript:) object:tuple file:OCMOCK_ANY lineNumber:0 description:@"Invalid parameter not satisfying: %@", @"%@"];
            
            tuple[4] = @5;
            
            [assertHandler verify];
            
            [[[NSThread currentThread] threadDictionary] removeObjectForKey:NSAssertionHandlerKey];
        });
    });
    
    context(@"fast enumeration", ^{
        it(@"can use for in to access tuple", ^{
            ZTuple20 *tuple = ZTuple(@1, @2, @3, @4, @5, @6, @7, @8, @9, @10,
                                     @11, @12, @13, @14, @15, @16, @17, @18, @19, @20);
            
            NSMutableArray *array = [NSMutableArray array];
            
            for(NSNumber *number in tuple) {
                [array addObject:number];
            }
            expect(array).to.equal(@[@1, @2, @3, @4, @5, @6, @7, @8, @9, @10,
                                     @11, @12, @13, @14, @15, @16, @17, @18, @19, @20]);
        });
        
        it(@"will raise error if modify any item when enumeration", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            
            objc_setEnumerationMutationHandler(enumerationMutationHandler);
            
            for(NSNumber *number in tuple) {
                id useless __attribute((unused)) = number;
                tuple[1] = @5;
            }
            
            expect([[NSThread currentThread] threadDictionary][@"mutationErrorObject"]).to.equal(tuple);
            [[NSThread currentThread] threadDictionary][@"mutationErrorObject"] = nil;
            
            for(NSNumber *number in tuple) {
                id useless __attribute((unused)) = number;
                tuple.last = @12;
            }
            expect([[NSThread currentThread] threadDictionary][@"mutationErrorObject"]).to.equal(tuple);
            [[NSThread currentThread] threadDictionary][@"mutationErrorObject"] = nil;
            
            objc_setEnumerationMutationHandler(NULL);
        });
    });
    
    context(@"copy", ^{
        it(@"can copy to get a cloned one", ^{
            ZTuple3 *tuple = ZTuple(@1, @2, @3);
            ZTuple3 *tupleCopied = [tuple copy];
            
            expect(tupleCopied.first).to.equal(@1);
            expect(tupleCopied.second).to.equal(@2);
            expect(tupleCopied.third).to.equal(@3);
        });
    });
    
});

SpecEnd

