//
//  IAPSendMoneyInitRequest.h
//  IAPDanaKit
//
//  Created by Engkit Satia Riswara on 18/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPSendMoneyInitRequest : NSObject

@property (copy, nonatomic, readonly) NSString *_Nonnull payeeRegId;

- (instancetype _Nullable)initWithPayeeRegId: (NSString *_Nonnull)payeeRegId;

- (NSDictionary *_Nonnull)jsonPayload;

@end
