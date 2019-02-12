//
//  IAPThreadManager.h
//  IAPDanaKit
//
//  Created by 祝威 on 2018/8/16.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPThreadManager : NSObject

void IAPThreadMainCall(dispatch_block_t block);

@end
