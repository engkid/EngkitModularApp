//
//  IAPApiErrorResult.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 20/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPErrorModel : NSObject

@property (strong, nonatomic, nullable) NSError *error;
@property (copy, nonatomic, nullable) NSString *code;
@property (copy, nonatomic, nullable) NSString *message;

- (instancetype _Nonnull)initWithError:(NSError *_Nullable)error code:(NSString *_Nullable)code message:(NSString *_Nullable)message;

@end
