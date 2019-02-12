//
//  IAPRequestMoneyOrder.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 13/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IAPBBMUser.h"

@interface IAPRequestMoneyOrder : NSObject

@property (assign, nonatomic, readonly) NSUInteger amount;
@property (strong, nonatomic, readonly, nonnull) IAPBBMUser *payer;

- (instancetype _Nullable)initWithAmount:(NSUInteger)amount payer:(IAPBBMUser *_Nonnull)payer;

@end
