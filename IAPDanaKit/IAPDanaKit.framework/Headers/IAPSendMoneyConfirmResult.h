//
//  IAPSendMoneyConfirmResult.h
//  IAPDanaKit
//
//  Created by Rahardyan Bisma Setya Putra on 19/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPSendMoneyConfirmInfo.h"
#import "IAPErrorModel.h"

@interface IAPSendMoneyConfirmResult : NSObject

@property (nonatomic, readonly) BOOL success;
@property (strong, nonatomic, readonly, nullable) IAPSendMoneyConfirmInfo *info;
@property (strong, nonatomic, readonly, nullable) IAPErrorModel *errorInfo;

- (instancetype _Nullable) initWithInfoModel:(IAPSendMoneyConfirmInfo *_Nonnull) info;

- (instancetype _Nullable) initWithErrorInfo:(IAPErrorModel *_Nonnull) errorInfo;

- (instancetype _Nullable) initSuccessWithJson:(NSDictionary<NSString *,id> *_Nonnull) data;

@end
