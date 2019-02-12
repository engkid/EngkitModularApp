//
//  IAPSendMoneyInitResult.h
//  IAPDanaKit
//
//  Created by Engkit Satia Riswara on 18/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPSendMoneyInitInfo.h"
#import "IAPErrorModel.h"

@interface IAPSendMoneyInitResult : NSObject

@property (assign, nonatomic, readonly) BOOL success;
@property (strong, nonatomic, readonly, nullable) IAPSendMoneyInitInfo *info;
@property (strong, nonatomic, readonly, nullable) IAPErrorModel *error;

- (instancetype _Nonnull)initWithDictionary:(NSDictionary<NSString *,id> *_Nonnull)data;

- (instancetype _Nonnull)initWithErrorInfo:(IAPErrorModel *_Nonnull)errorInfo;

@end
