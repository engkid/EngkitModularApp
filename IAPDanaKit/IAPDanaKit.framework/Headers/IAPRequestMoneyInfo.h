//
//  IAPRequestMoneyInfo.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 13/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPRequestMoneyInfo : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *orderId;
@property (copy, nonatomic, readonly, nonnull) NSString *groupId;
@property (copy, nonatomic, readonly, nonnull) NSString *remarks;

- (instancetype _Nullable)initWithOrderId:(NSString *_Nonnull)orderId
								  groupId:(NSString *_Nonnull)groupId
								  remarks:(NSString *_Nonnull)remarks;

@end
