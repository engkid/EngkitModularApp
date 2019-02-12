//
//  IAPTransferResult.h
//  IAPDanaKit
//
//  Created by Heru Pratama on 11/24/17.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IAPBBMUser.h"

@interface IAPTransferResult : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *status;
@property (assign, nonatomic, readonly) BOOL refunded;
@property (copy, nonatomic, readonly, nonnull) NSString *amount;
@property (copy, nonatomic, readonly, nonnull) NSString *currency;
@property (copy, nonatomic, readonly, nonnull) NSString *remarks;
@property (copy, nonatomic, readonly, nonnull) NSString *orderId;
@property (copy, nonatomic, readonly, nonnull) NSString *payer;
@property (copy, nonatomic, readonly, nonnull) NSString *payee;
@property (assign, nonatomic, readonly) NSInteger version;

- (instancetype _Nonnull)initWithStatus:(NSString *_Nonnull)status refunded:(BOOL)refunded amount:(NSString *_Nonnull)amount currency:(NSString *_Nonnull)currency remarks:(NSString *_Nonnull)remarks orderId:(NSString *_Nonnull)orderId payer:(NSString *_Nonnull)payer payee:(NSString *_Nonnull)payee version:(NSInteger)version;

@end
