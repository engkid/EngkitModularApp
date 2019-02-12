//
//  IAPDanaContactInfo.h
//  IAPDanaKit
//
//  Created by Heru Pratama on 11/21/17.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPDanaContactInfo : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *name;
@property (copy, nonatomic, readonly, nonnull) NSString *phoneNumber;

- (instancetype _Nullable)initWithName:(NSString *_Nonnull)name phoneNumber:(NSString *_Nonnull)phoneNumber;

@end
