//
//  IAPDanaRequestContactProtocol.h
//  IAPDanaKit
//
//  Created by Heru Pratama on 11/21/17.
//  Copyright © 2017 Alipay. All rights reserved.
//

#ifndef IAPDanaRequestContactProtocol_h
#define IAPDanaRequestContactProtocol_h

#import <UIKit/UIKit.h>
#import "IAPDanaContactInfo.h"

typedef void (^IAPDanaRequestContactCompletionBlock)(IAPDanaContactInfo *);
typedef void (^IAPDanaRequestContactErrorBlock)(NSError *);

@protocol IAPDanaRequestContactProtocol <NSObject>

- (void)openContactListFromViewController:(UIViewController *)viewController completionBlock:(IAPDanaRequestContactCompletionBlock)completionBlock errorBlock:(IAPDanaRequestContactErrorBlock)errorBlock;

@end


#endif /* IAPDanaRequestContactProtocol_h */
