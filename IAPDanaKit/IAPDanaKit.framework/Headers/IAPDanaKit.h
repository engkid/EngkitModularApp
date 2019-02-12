//
//  IAPDanaKit.h
//  IAPAppContainer
//
//  Created by zhaoy on 24/4/17.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import "IAPDanaRequestContactProtocol.h"
#import "IAPAuthProcessorProtocol.h"
#import "IAPBBMUser.h"
#import "IAPTransferResult.h"
#import "IAPLuckyMoneyResult.h"
#import "IAPRequestMoneyRequest.h"
#import "IAPRequestMoneyResult.h"
#import "IAPRequestMoneyError.h"
#import "IAPUserAuthCodeRequest.h"
#import "IAPUserAuthCodeResult.h"
#import "IAPPocketBadgeResult.h"
#import "IAPSendMoneyConsultResult.h"
#import "IAPThreadManager.h"
#import "IAPSendMoneyConfirmRequest.h"
#import "IAPSendMoneyConfirmResult.h"
#import "IAPSendMoneyInitResult.h"
#import "IAPSendMoneyInitRequest.h"
#import "IAPSendMoneyConfirmRequest.h"
#import "IAPSendMoneyConfirmResult.h"
#import "UIViewController+Navigation.h"
#import "IAPSendMoneyTransferResult.h"

#define IAPDanaKitName @"DanaKit"
#define IAPDanaBaseDomain @".dana.id"
#define IAPDanaParameterKeyServiceURLPrefix @"danaServiceURLPrefix"
#define IAPDanaParameterKeyNavigationController @"navigationController"

#define DANA_NOTIF_PAYMENT_FINISHED @"DanaPaymentFinished"
#define DANA_NOTIF_H5_CLOSED @"DanaClosed"
#define DANA_NOTIF_LUCKY_MONEY_ORDER_ID @"DanaLuckyMoneyOrderId"
#define DANA_NOTIF_PREREGISTER_FINISHED @"DanaPreregisterFinish"
#define DANA_NOTIF_USER_INFO_CHANGED @"DanaUserInfoChange"

/**
 Provides unified interface for handling Dana wallet related business logic. Such as start and terminate IAPAppcontainer, etc
 */
@interface IAPDanaKit : NSObject

/**
 A URL presents the prefix of Dana Service.

 Users may use `+NSURL URLWithString:relativeToURL:` to get an absolute URL (fully qualified URL):
 `NSURL *userURL = [NSURL URLWithString:@"/api/user?query" relativeToURL:IAPDanaKit.DanaServiceURLPrefix];`
 */
@property(class, strong, readonly, nonnull) NSURL *DanaServiceURLPrefix;

/**
 Set this property, so `IAPDanaKit` can invoke contact picker.
 */
@property (class, strong, nonatomic, nullable) id<IAPDanaRequestContactProtocol> danaRequestContact;

/**
 Set this property, so `IAPDanaKit` ask to retry Web Access Token process when failed.
 */
@property (class, strong, nonatomic, nullable) id<IAPAuthProcessorProtocol> authProcessor;

/**
 Call this method to initialize Dana wallet, with a async callback to notify the start result

 @param params A `NSDictionary` object containing startup parameters.
 @param completion Asynchronous callback invoked on main_queue to notify the initialization result, passing null indicate the process is successful.
 */
+ (void)startWithParameters:(NSDictionary<NSString *,NSString *> *_Nonnull)params completionHandler:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 Returns an instance of UIViewController which contains web view to load.

 @param parameters A Dictionary includes parameters to create the view controller, `url` should be included.
 @return Returns the view controller, a sub-app is created inside.
 */
+ (UIViewController *_Nullable)viewControllerWithParameters:(NSDictionary<NSString *,id> *_Nonnull)parameters;

/**
 Queries user info from Dana Wallet, gets balance and number of in progress transaction with async callback.

 @param completion Asynchronous callback returns a dictionary;
 {
	 balance =    {    		// balance struct
		 amount = 0;		// balance value
		 currency = Rp;		// currency type
	 };
	 pendingTransaction = 0;// number of in progress transaction
	 success = 1;  			// 1: success (errCode = nil,e rrorMsg = nil) 0: false
	 errorCode = AExxxxxx;  // error code
	 errorMsg = xxx;        // error message
 }

 errorCode and errorDesc:

 errorCode          errorDesc
 -------------------------------------------------------
 AE15102058020034	Unregister or Uninitialized.
 AE15102058020049	Login failed
 AE15002058020002	System busy, please try again later
 AE15002258001012   Network unavailable,please try again later
 AE15002258001005	Network timeout,please try again later
 */
+ (void)queryUserInfoWithCompletionHandler:(void (^_Nullable)(NSDictionary<NSString *,id> * _Nullable result))completion;

/**
 Queries promotion from Dana Wallet, gets promotion information with async callback.

 @param completion Asynchronous callback returns a dictionary;
 {
 	title = "Title"; // Title of promotion
 	message = "Message"; // Message of promotion
 	amount = 0; // Promotion value in Rp
 	imageUrl = "http://www.dana.id/image-path"; // Image URL
 	ctaUrl = "http://www.dana.id/promo-url"; // URL of the promo
 	isDanaUser = YES; // Registered dana user or not
 }
 */
+ (void)queryPromotionWithCompletionHandler:(void (^_Nullable)(NSDictionary<NSString *,id> * _Nullable result, NSError * _Nullable error))completion;


/**
 Returns an instance of `UIViewController` which contains the transfer process.

 @param payer The User in `IAPBBMUser` who will send the money.
 @param payee The User in `IAPBBMUser` who will receieve the money.
 @return Returns the transfer process view controller.
 */
+ (UIViewController *_Nonnull)transferWithPayer:(IAPBBMUser *_Nonnull)payer payee:(IAPBBMUser *_Nonnull)payee completionHandler:(void (^_Nullable)(IAPTransferResult  * _Nonnull result))completion;

/**
 Returns an instance of `UIViewController` which contains the transfer detail.

 @param orderId `orderId` of transfer.
 @return Returns the transfer detail view controller.
 */
+ (UIViewController *_Nonnull)transferDetailWithOrderId:(NSString *_Nonnull)orderId;

/**
 Returns an instance of `UIViewController` which contains the lucky money process.

 @param payer The User in `IAPBBMUser` who will send the money.
 @param numberOfMember Number of member is group.
 @param groupId Unique identifier for BBM Group
 @return Returns the transfer process view controller.
 */
+ (nonnull UIViewController *)luckyMoneyWithPayer:(nonnull IAPBBMUser *)payer numberOfMember:(NSUInteger)numberOfMember groupId:(NSString *_Nonnull)groupId completionHandler:(void (^_Nullable)(IAPLuckyMoneyResult * _Nonnull result))completion;

/**
 Returns an instance of `UIViewController` which contains the transfer detail.

 @param user The User in `IAPBBMUser` who will open lucky money detail.
 @param orderId `orderId` of lucky money.
 @return Returns the transfer detail view controller.
 */
+ (UIViewController *_Nonnull)luckyMoneyDetailWithUser:(nonnull IAPBBMUser *)user orderId:(nonnull NSString *)orderId;

/**
 Request to create request money, and will return asynchrounous callback once done.
 
 @param requestParameter `IAPRequestMoneyRequest` is a required parameter value for creating the request
 @param completion Asynchronous callback returns a `IAPRequestMoneyResult`;
 {
 	success = YES; // Request creation success state
 	info = {
 		orderId = ""; // Request money order id
 		groupId = ""; // Request money group id
 		remarks = ""; // Request money remarks
 	}
 	error = {
 		title = ""; // Error title
 		message = ""; // Error message
 	}
 }
 */
+ (void)createRequestMoneyWithParameter:(nonnull IAPRequestMoneyRequest *)requestParameter completionHandler:(void (^_Nonnull)(IAPRequestMoneyResult *_Nonnull result))completion;

/**
 Returns an instance of `UIViewController` which contains summary of the request money.
 
 @param orderId `orderId` of request money.
 @return Returns the request money summary view controller.
 */
+ (UIViewController *_Nullable)requestMoneySummaryWithOrderId:(NSString *_Nonnull)orderId;

/**
 Asks DanaKit to open a resource specified by a URL, and provides a dictionary of launch options.

 @param pathAndQuery Path and query of the URL to open.
 @param options A dictionary of launch options. Currently, instance of UINavigationController should be passed with key `IAPDanaParameterKeyNavigationController`.
 @return YES if DanaKit successfully handled the request or NO if the attempt to open the URL resource failed.
 */
+ (BOOL)openURLString:(nonnull NSString *)pathAndQuery options:(nullable NSDictionary<NSString *,id> *)options;

/**
 Clean current account from Dana Wallet
 */
+ (void)cleanCurrentAccount;

/**
 Returns an instance of `UIViewController` which contains specific DANA page based on the given `serviceName` parameter.
 */
+ (UIViewController *_Nullable)viewControllerForServiceName:(NSString *_Nonnull)serviceName;

/**
 Method to check if the current BBM user has registered Dana. Please call this method after DANA initialization.
 */
+ (BOOL)isDanaRegistered;

/**
 Method to open Payment QR screen
 */
+ (UIViewController *_Nullable)startPaymentQRViewController;

/**
 Method to get User AuthCode
 */
+ (void)queryUserAuthcode:(nonnull IAPUserAuthCodeRequest *)requestParameter completion:(void(^_Nonnull)(IAPUserAuthCodeResult *_Nonnull result))completion;

/**
 Perform network request to register new user, and will make a user as pre-registered.
 
 @param authCode an BBM auth code
 */
+ (void)startPreRegister:(NSString *_Nonnull)authCode;

/**
 Method to queryPocketBadge
 */
+ (void)queryPocketBadgeWithCompletionHandler:(void (^_Nonnull)(IAPPocketBadgeResult * _Nonnull result))completion;

/**
 Method to open BBM Quiz Transaction Detail Page
 */
+ (UIViewController *_Nonnull)startBBMQuizDetailWithBizOrderId:(NSString *_Nonnull)bizOrderId;

/**
 Method to consult payee after payer finished picking up BBM contact to send money
 */
+ (void)initSendMoneyWithRequest:(nonnull IAPSendMoneyInitRequest *)request completionHandler:(void (^_Nonnull)(IAPSendMoneyInitResult *_Nonnull result))completionHandler;

/**
 Method to consult send money preocess
 
 @param completionHandler async callback when consult process was completed
*/
+ (void)consultSendMoneyFrom:(UIViewController *_Nonnull)sourceViewController
                          by:(IAPViewControllerTransition)transitionMethod
       withCompletionHandler:(void (^_Nonnull)(IAPSendMoneyConsultResult *_Nonnull result))completion;

/**
 Method to confirm send money proccess
 - @param source view controller from BBM page
 - @param transition method
 - @param request parameter for confirm send money
 - @param completion async callback when confirmation process was completed (IAPSendMoneyTransferResult)
 */
+ (void)confirmSendMoneyFrom:(UIViewController * _Nonnull)sourceViewController by:(IAPViewControllerTransition)transitionMethod withRequest:(IAPSendMoneyConfirmRequest * _Nonnull)request completionHandler:(void (^_Nonnull)(IAPSendMoneyTransferResult * _Nonnull))completion;

@end

#define IAPDanaKitVersion @"1.9.0"
