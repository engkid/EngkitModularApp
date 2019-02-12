//
//  IAPUserAuthCodeRequest.h
//  IAPDanaKit
//
//  Created by Wahyudimas Hutama Rachman Syarief on 9/4/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPUserAuthCodeRequest : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *clientId;

- (instancetype _Nullable)initWithClientId:(NSString *_Nonnull)clientId;
- (NSDictionary *_Nonnull)jsonPayload;

@end
