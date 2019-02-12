//
//  IAPLuckyMoneyResult.h
//  IAPDanaKit
//
//  Created by Heru Pratama on 2/19/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPLuckyMoneyResult : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *status;
@property (copy, nonatomic, readonly, nonnull) NSString *remarks;
@property (copy, nonatomic, readonly, nonnull) NSString *orderId;
@property (copy, nonatomic, readonly, nonnull) NSString *payer;
@property (copy, nonatomic, readonly, nullable) NSString *groupId;
@property (copy, nonatomic, readonly, nonnull) NSString *thumbnail;
@property (assign, nonatomic, readonly) NSInteger version;

- (instancetype _Nonnull)initWithStatus:(NSString *_Nonnull)status remarks:(NSString *_Nonnull)remarks orderId:(NSString *_Nonnull)orderId payer:(NSString *_Nonnull)payer groupId:(NSString *_Nullable)groupId thumbnail:(NSString *_Nonnull)thumbnail  version:(NSInteger)version;

@end
