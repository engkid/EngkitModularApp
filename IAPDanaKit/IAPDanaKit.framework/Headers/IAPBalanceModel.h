//
//  IAPBalanceModel.h
//  IAPDanaKit
//
//  Created by Engkit Satia Riswara on 19/10/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPBalanceModel : NSObject

@property (copy, nonatomic, nullable) NSString *amount;
@property (copy, nonatomic, nullable) NSString *currency;

- (instancetype _Nonnull)initWithDictionary:(NSDictionary *_Nonnull)balanceDict;

- (NSDictionary *_Nullable)json;

@end
