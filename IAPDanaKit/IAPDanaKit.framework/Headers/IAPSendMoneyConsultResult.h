//
//  IAPSendMoneyConsultResult.h
//  IAPDanaKit
//
//  Created by Wahyudimas Hutama Rachman Syarief on 10/19/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPErrorModel.h"

#define KYC_SATUS @"kycStatus"

@interface IAPSendMoneyConsultResult : NSObject

@property (assign, nonatomic, readonly) BOOL success;
@property (strong, nonatomic, readonly, nullable) IAPErrorModel *error;

- (instancetype _Nonnull)initWithSuccess:(BOOL)success
								   error:(IAPErrorModel *_Nullable)error;

@end
