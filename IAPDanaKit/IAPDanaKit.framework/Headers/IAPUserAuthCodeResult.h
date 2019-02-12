//
//  IAPUserAuthCodeResult.h
//  IAPDanaKit
//
//  Created by Wahyudimas Hutama Rachman Syarief on 9/4/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPErrorModel.h"

@interface IAPUserAuthCodeResult : NSObject

@property (assign, nonatomic) BOOL success;
@property (copy, nonatomic, nullable) NSString *authCode;
@property (strong, nonatomic, nullable) IAPErrorModel *error;

- (instancetype _Nonnull)initWithSuccess:(BOOL)success
								authCode:(NSString *_Nullable)authCode
								   error:(IAPErrorModel *_Nullable)error;

@end
