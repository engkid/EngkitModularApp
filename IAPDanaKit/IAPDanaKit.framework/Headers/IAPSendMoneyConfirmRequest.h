//
//  IAPConfirmSendMoneyRequest.h
//  IAPDanaKit
//
//  Created by Rahardyan Bisma Setya Putra on 18/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPBBMUser.h"

@interface IAPSendMoneyConfirmRequest : NSObject
@property (copy, nonatomic, nonnull, readonly) NSString *payAmount;
@property (copy, nonatomic, nonnull, readonly) IAPBBMUser *payer;
@property (copy, nonatomic, nonnull, readonly) IAPBBMUser *payee;
@property (copy, nonatomic, nonnull, readonly) NSString *remark;
@property (assign, nonatomic, readonly) BOOL share;

- (instancetype _Nullable)initWithPayAmount:(NSString *_Nonnull)payAmount
                                      payer:(IAPBBMUser *_Nonnull)payer
                                      payee:(IAPBBMUser *_Nonnull)payee
                                    remarks:(NSString *_Nonnull)remarks
                                      share:(BOOL)share;
                
- (NSDictionary *_Nonnull)jsonPayload;
@end
