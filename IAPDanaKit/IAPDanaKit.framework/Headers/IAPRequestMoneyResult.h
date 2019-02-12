//
//  IAPRequestMoneyResult.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 13/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPRequestMoneyInfo.h"
#import "IAPRequestMoneyError.h"

@interface IAPRequestMoneyResult : NSObject

@property (assign, nonatomic, readonly) BOOL success;
@property (strong, nonatomic, readonly, nullable) IAPRequestMoneyInfo *info;
@property (strong, nonatomic, readonly, nullable) IAPRequestMoneyError *error;

- (instancetype _Nonnull)initWithSuccessStatus:(BOOL)success
										  info:(IAPRequestMoneyInfo *_Nullable)info
										 error:(IAPRequestMoneyError *_Nullable)error;

@end
