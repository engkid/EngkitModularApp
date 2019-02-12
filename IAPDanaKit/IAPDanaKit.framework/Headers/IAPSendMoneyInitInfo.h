//
//  IAPSendMoneyInitInfo.h
//  IAPDanaKit
//
//  Created by Engkit Satia Riswara on 18/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPBalanceModel.h"

@interface IAPSendMoneyInitInfo : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *payeeInfo;
@property (nonatomic, readonly, nonnull) IAPBalanceModel *payerMinAmount;
@property (nonatomic, readonly, nonnull) IAPBalanceModel *payerMaxAmount;
@property (nonatomic, readonly, nonnull) IAPBalanceModel *payerAccountBalance;


- (instancetype _Nullable)initWithPayeeInfo:(NSString *_Nonnull)payeeInfo
                             payerMinAmount: (IAPBalanceModel *_Nonnull)payerMinAmount
                             payerMaxAmount: (IAPBalanceModel *_Nonnull)payerMaxAmount
                        payerAccountBalance: (IAPBalanceModel *_Nonnull)payerAccountBalance;

@end
