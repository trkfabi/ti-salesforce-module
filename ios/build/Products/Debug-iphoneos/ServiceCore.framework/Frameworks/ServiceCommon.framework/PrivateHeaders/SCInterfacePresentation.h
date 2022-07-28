//
//  SCViewControllerPresentation.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/18/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Protocol that an SCInterfaceStyle class can adopt to indicate it is capable of applying presentation and transitioning appearance updates to view controllers.
 */
@protocol SCInterfacePresentation <NSObject>

@optional

/**
 Message sent to the receiver when a transitioning delegate is desired for the given controller.
 
 If the controller is not controlled by this SCInterfaceStyle instance, or if no animation controller should be used, `nil` should be returned.
 @param presentedController View controller about to be presented
 @param presentingController View controller the target controller is being presented from.
 @return Object conforming to UIViewControllerTransitioningDelegate, or `nil` if this interface style instance doesn't have a transitioning delegate for the supplied controller.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)transitioningDelegateForPresentedController:(UIViewController*)presentedController presentingController:(UIViewController*)presentingController;

/**
 Message sent to the receiver when a custom presentation controller is about to be used, which provides the interface style instance the opportunity to modify it as needed.
 @param presentationController Presentation controller about to be used when presenting another controller.
 @return `YES` if this interface style instance has applied customizations, or `NO` to indicate other style instances should be consulted instead.
 */
- (BOOL)applyStyleToPresentationController:(UIPresentationController*)presentationController __deprecated_msg("This should be handled at the time the transitioning delegate is passed along");

@end

NS_ASSUME_NONNULL_END
