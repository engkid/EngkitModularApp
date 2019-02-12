//
//  IAPBBMUser.h
//  IAPDanaKit
//
//  Created by Heru Pratama on 11/14/17.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPBBMUser : NSObject

@property (copy, nonatomic, nullable) NSString *regId;
@property (copy, nonatomic, nullable) NSString *nickname;
@property (copy, nonatomic, nullable) NSString *avatarUrl;

@end
