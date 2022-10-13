//
//  UIViewController+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/4/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef SCS_MINIMIZABLE_SUPPORTED
#import "SCSMinimizable.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class SCServiceCloud, SCSWindow;

/**
 Convenience additions to UIViewController for Service Cloud SDK functionality.
 */
@interface UIViewController (ServiceCommon) <SCSMinimizable>

/**
 Convenience method that finds the tompost presented view controller
 */
@property (nonatomic, weak, readonly) UIViewController *topmostViewController;

/**
 Determines if this controller is presented within a ServiceSDK floating window.
 */
@property (nonatomic, assign, readonly, getter=isPresentedInFloatingWindow) BOOL presentedInFloatingWindow;

/**
 Returns a reference to the SCSWindow instance this controller is presented within, if one is found.

 It uses a series of approaches to attempt to find the window without accidentally initializing its view if it hasn't been loaded yet.

 @return `SCSWindow` instance this controller is presented within, otherwise `nil` if it isn't in a floating window.
 */
- (nullable __kindof SCSWindow*)floatingWindow;

/**
 Convenience method to find the list of all presented controllers, starting from the receiver.
 */
- (NSArray*)allPresentedControllers;

/**
 Convenience method to find the list of all child controllers, starting from the receiver.
 */
- (NSArray*)allChildControllers;

/**
 Convenience method to return the view controller at, or below, the level of the receiver that conforms to the given protocol.
 
 @param protocol Protocol to validate.
 
 @return View controller conforming to the given protocol, or `nil`.
 */
- (nullable __kindof UIViewController *)viewControllerConformingToProtocol:(Protocol*)protocol;

/**
 Returns the appropriate transitioning delegate that should be used when presenting the given controller from the sender, using the given service cloud instance.
 
 Whenever a view controller is presented modally, it is important that either the `serviceCloud:presentViewController:animated:completion:` method is used to properly configure the view controller, or that this method is used to assign the transitioning delegate prior to presenting it.  This provides the developer with the ability to override the presentation or transition used when displaying it visually, allowing our default customizations to be overridden by the developer.
 
 @warning In some exceptional cases it may be necessary to not call this, so as to prevent the customer from being able to override some presentation, but we must be careful in doing so.

 @param serviceCloud Service cloud instance to use.
 @param controller The view controller to be presented.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate> *)serviceCloud:(SCServiceCloud*)serviceCloud transitioningDelegateToPresentController:(UIViewController*)controller;

/**
 Convenience method for presenting a view controller, configured and notified through the supplied service cloud instance.
 
 This automatically applies the transitioning delegate, from the `serviceCloud:transitioningDelegateToPresentController:` method and applies it as needed.
 @param serviceCloud The service cloud instance to use.
 @param viewControllerToPresent The view controller to present.
 @param animated Causes the transition to be animated.
 @param completion Completion block.
 */
- (void)serviceCloud:(SCServiceCloud*)serviceCloud presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

/**
 Internal method used to dismiss a tree of view controllers. Except the calling view controller none of the other
 view controller dismissals will be animated. 
 @param animated    Whether or not the calling view controller dismissal will be animated.
 @param completion  Optional completion block to trigger when dismissal is complete.
 */
- (void)dismissViewControllerTreeAnimated:(BOOL)animated completion:(nullable void (^)(void))completion;

/**
 Internal method that can be overridden by view controllers to control if it should be dismissed as part of the
 view controller tree dismissal.
 */
- (BOOL)shouldDismissTreeWithOriginController:(UIViewController*)controller;

@end

NS_ASSUME_NONNULL_END
