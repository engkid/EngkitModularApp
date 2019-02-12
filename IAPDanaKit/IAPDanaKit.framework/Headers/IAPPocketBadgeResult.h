//
//  IAPPocketBadgeResult.h
//  IAPDanaKit
//
//  Created by Wahyudimas Hutama Rachman Syarief on 9/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPErrorModel.h"

@interface IAPPocketBadgeResult : NSObject

@property (assign, nonatomic, readonly) BOOL success;
@property (assign, nonatomic, readonly) BOOL isShowPocketBadge;
@property (strong, nonatomic, readonly, nullable) IAPErrorModel *error;

- (instancetype _Nonnull)initWithSuccess:(BOOL)success
					   isShowPocketBadge:(BOOL)isShowPocketBadge
								   error:(IAPErrorModel *_Nullable)error;

@end
