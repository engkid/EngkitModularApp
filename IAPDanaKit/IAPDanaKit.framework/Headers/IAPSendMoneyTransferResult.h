//
//  IAPSendMoneyTransferResult.h
//  IAPDanaKit
//
//  Created by Engkit Satia Riswara on 05/11/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPErrorModel.h"
#import "IAPTransferResult.h"

@interface IAPSendMoneyTransferResult : IAPTransferResult

@property (nonatomic) BOOL success;
@property (strong, nonatomic, nullable) IAPErrorModel *errorInfo;

- (instancetype _Nonnull)initWithStatus:(NSString *_Nonnull)status
                               refunded:(BOOL)refunded
                                 amount:(NSString *_Nonnull)amount
                               currency:(NSString *_Nonnull)currency
                                remarks:(NSString *_Nonnull)remarks
                                orderId:(NSString *_Nonnull)orderId
                                  payer:(NSString *_Nonnull)payer
                                  payee:(NSString *_Nonnull)payee
                                version:(NSInteger)version
                                success:(BOOL)success;

- (instancetype _Nonnull)initWithErrorInfo:(IAPErrorModel *_Nullable)errorInfo;

@end
