//
//  IAPRequestMoneyParameter.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 13/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPBBMUser.h"
#import "IAPRequestMoneyOrder.h"

@interface IAPRequestMoneyRequest : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *groupId;
@property (assign, nonatomic, readonly) BOOL isShareable;
@property (assign, nonatomic, readonly) NSUInteger totalAmount;
@property (assign, nonatomic, readonly) NSUInteger requestedAmount;
@property (copy, nonatomic, readonly, nonnull) NSString *remarks;
@property (strong, nonatomic, readonly, nonnull) IAPBBMUser *payee;
@property (strong, nonatomic, readonly, nonnull) NSArray<IAPRequestMoneyOrder *> *requestMoneyOrders;

- (instancetype _Nullable)initWithGroupId:(NSString *_Nonnull)groupId
							  isShareable:(BOOL)isShareable
							  totalAmount:(NSUInteger)totalAmount
								  remarks:(NSString *_Nonnull)remarks
									payee:(IAPBBMUser *_Nonnull)payee
					   requestMoneyOrders:(NSArray<IAPRequestMoneyOrder *> *_Nonnull)requestMoneyOrders;

- (NSDictionary *_Nonnull)jsonPayload;

@end
