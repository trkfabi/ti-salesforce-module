//
//  SCOverlayPresentationControllerDelegate.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/30/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCOverlayPresentationController;

/**
 Delegate protocol used by the SCOverlayController class to manage presentation and dismissal of the controller.
 */
@protocol SCOverlayPresentationControllerDelegate <NSObject>

@optional

/**
 Sent to the receiver when the background is tapped.
 
 @discussion
 This allows the delegate so it can respond when the background is tapped.  If this method isn't implemented by the receiver, then the default behavior is to simply invoke `dismissViewController:animated:`.
 
 @param controller Controller sending the message.
 @param background The background view that was tapped.
 */
- (void)overlayPresentationController:(SCOverlayPresentationController*)controller backgroundViewTapped:(UIView*)background;

@end

NS_ASSUME_NONNULL_END