//
//  SCSMinimizedView.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/5/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SCAppearanceApplicator.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The view used by SCSMinimizedView for storing the customizable content of the minimized view.
 */
@interface SCSMinimizedContentView : UIView

@end

/**
 The view used by SCSMinimizedView that acts as a container for its children, and is used for clipping rounded corners.
 */
@interface SCSMinimizedContainerView : UIView

@end


/**
 Generic backing view for the thumbnail minimized controller.  It isn't meant to be used directly, but rather to update its appearance using the provided appearance selectors.
 */
@interface SCSMinimizedView : UIView <SCAppearanceApplicator>

/**
 The overall container view that contains the corner radius.
 */
@property (nonatomic, strong, readonly) SCSMinimizedContainerView *containerView;

/**
 The view that contains the thumbnail content view.
 */
@property (nonatomic, strong, readonly) SCSMinimizedContentView *contentView;

/*
 The top close button view.
 */
@property (nonatomic, strong, readonly) UIButton *closeButton;

@end

/**
 UIAppearance configuration properties.
 */
@interface SCSMinimizedView (UIAppearance)

/**
 Outer corner radius for the containerView.
 */
@property (nonatomic, assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;

/**
 Color of the view's shadow.
 */
@property (nullable, nonatomic, strong) UIColor *shadowColor UI_APPEARANCE_SELECTOR;

/**
 Color of the view's shadow.
 */
@property (nonatomic, assign) CGFloat shadowRadius UI_APPEARANCE_SELECTOR;

/**
 Background color for the contentView.
 */
@property (nullable, nonatomic, strong) UIColor *contentViewBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 Background color for the header region.
 */
@property (nullable, nonatomic, strong) UIColor *headerViewBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 Image to use for the close button.
 */
@property (nullable, nonatomic, strong) UIImage *closeImage UI_APPEARANCE_SELECTOR;

/**
 Minimum image insets to use within the close button.
 */
@property (nonatomic, assign) UIEdgeInsets closeImageInsets UI_APPEARANCE_SELECTOR;

/**
 If any dimension is zero, it will maintain the aspect ratio with the non-zero dimension being the limiting factor.
 */
@property (nonatomic, assign) CGSize maximumContentSize UI_APPEARANCE_SELECTOR;

/**
 If non-zero, it enforces a minimum content size.
 */
@property (nonatomic, assign) CGSize minimumContentSize UI_APPEARANCE_SELECTOR;

/**
 The fixed height the header should be.  If set to `0`, the header will automatically adjust its size based on
 the height of its image.
 */
@property (nonatomic, assign) CGFloat headerHeight UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
