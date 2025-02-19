//
//  SCOverlayOverlayPresentationController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/20/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCOverlayPresentationController;
@protocol SCOverlayPresentationControllerDelegate;

@interface SCOverlayPresentationView : UIView @end

/**
 Presentation controller for displaying a semi-opaque background behind the presented controller.
 */
@interface SCOverlayPresentationController : UIPresentationController

/**
 The delegate to control interactions with the presentation controller.
 
 @discussion
 If the presented, or presenting, view controllers conform to this protocol, they will automatically be used
 as the default for this property.
 */
@property (nonatomic, weak, nullable) NSObject<SCOverlayPresentationControllerDelegate> *overlayDelegate;

/**
 The current margin insets applied to adjust the margins from the edge of the presenting controller.
 */
@property (nonatomic, assign, readonly) UIEdgeInsets marginInsets;

/**
 The corner radius to apply to the overlaid controller.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 The background view that will be displayed between the presented and presenting view controllers.
 */
@property (nonatomic, strong, readonly) UIView *backgroundView;

/**
 Indicates whether or not this presentation controller should ignore the safe area insets property.

 If `NO`, then the actual insets applied to the presentation controller will be the largest value, in each dimension, between the marginInsets value and the current safe area insets.  This will only be applied to dimensions whose value is non-zero in the marginInsets value.  For example, this allows the Knowledge Home controller to be "docked" to the bottom of the screen.
 */
@property (nonatomic, assign, getter=shouldIgnoreSafeAreaInsets) BOOL ignoreSafeAreaInsets;

@property (nonatomic, assign, getter=isFullscreen) BOOL fullscreen;

/**
 Sets the margin insets for which this presentation controller should be adjusted.
 
 @param marginInsets    The margin insets.
 @param traitCollection The trait collection the margin insets will be used for, if applicable.
 */
- (void)setMarginInsets:(UIEdgeInsets)marginInsets compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection UI_APPEARANCE_SELECTOR;

/**
 The margin insets for which this presentation controller should be adjusted.
 
 @param traitCollection The trait collection to retrieve the margin insets for.
 */
- (UIEdgeInsets)marginInsetsCompatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection UI_APPEARANCE_SELECTOR;

- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
