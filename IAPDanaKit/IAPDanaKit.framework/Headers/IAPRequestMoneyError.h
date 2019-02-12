//
//  IAPRequestMoneyError.h
//  IAPDanaKit
//
//  Created by Nanda Julianda Akbar on 13/04/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IAPRequestMoneyError : NSObject

@property (copy, nonatomic, readonly, nonnull) NSString *title;
@property (copy, nonatomic, readonly, nonnull) NSString *message;

- (instancetype _Nonnull)initWithTitle:(NSString *_Nonnull)title
							   message:(NSString *_Nonnull)message;

@end
