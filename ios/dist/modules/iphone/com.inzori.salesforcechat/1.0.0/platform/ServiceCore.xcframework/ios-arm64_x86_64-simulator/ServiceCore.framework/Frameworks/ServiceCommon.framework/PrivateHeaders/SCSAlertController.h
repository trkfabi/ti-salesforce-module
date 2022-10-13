//
//  SCSAlertController.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 3/28/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCServiceCloud;

/**
 Specialized UIAlertController subclass that presents into its own managed window, ensuring that it will always float over any other window or view controller.
 
 UIAlertController, unlike UIAlertView, presents as a view controller within its view hierarchy using a custom presentation controller.  This means you can't get an alert to float over other windows unless it is isolated in its own window.
 */
@interface SCSAlertController : UIAlertController

/** 
 Service cloud instance to use when creating the window.  If not assigned, it defaults to the shared instance.
 */
@property (null_resettable, nonatomic, weak) SCServiceCloud *serviceCloud;

/**
 Show the alert with a default animation.
 */
- (void)show;

/**
 Shows the alert with an optional animation and completion block.
 
 @param animated Animated.
 @param completion Optional completion block.
 */
- (void)show:(BOOL)animated completion:(nullable void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
