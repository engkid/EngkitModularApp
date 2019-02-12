//
//  UIViewController+navigation.h
//  IAPDanaKit
//
//  Created by Rahardyan Bisma Setya Putra on 02/11/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IAPViewControllerTransition) {
    Push,
    Present
};

@interface UIViewController (Navigation)
+ (void)navigateTo:(UIViewController *_Nonnull)viewController
              from:(UIViewController *_Nonnull)sourceViewController
                by:(IAPViewControllerTransition)transitionMethod;
@end
