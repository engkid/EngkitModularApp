//
//  IAPSendMoneyConfirmInfo.h
//  IAPDanaKit
//
//  Created by Rahardyan Bisma Setya Putra on 19/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPSendMoneyConfirmInfo : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *orderId;
@property (copy, nonatomic, readonly, nonnull) NSString *amount;
@property (copy, nonatomic, readonly, nullable) NSString *currency;
@property (copy, nonatomic, readonly, nullable) NSString *remarks;
@property (copy, nonatomic, readonly, nullable) NSString *cashierOrderId;
@property (copy, nonatomic, readonly, nullable) NSString *cashierParam;

- (instancetype _Nullable)initWithOrderId:(NSString *_Nonnull)orederId
                                   amount:(NSString *_Nonnull)amount
                                 currency:(NSString *_Nullable)currency
                                  remarks:(NSString *_Nullable)remarks
                           cashierOrderId:(NSString *_Nullable)cashierOrderId
                              cashierParam:(NSString *_Nullable)cashierParam;
@end
