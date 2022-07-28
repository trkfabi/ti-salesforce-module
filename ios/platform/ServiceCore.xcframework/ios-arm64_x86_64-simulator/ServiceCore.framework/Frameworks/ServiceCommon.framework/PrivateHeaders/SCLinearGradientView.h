//
//  SCLinearGradientView.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/19/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import "SCGradientView.h"

typedef NS_ENUM(NSUInteger, SCLinearGradientDirection) {
    SCLinearGradientDirectionAutomatic,
    SCLinearGradientDirectionHorizontal,
    SCLinearGradientDirectionVertical,
};

IB_DESIGNABLE
/**
 Linear gradient view.
 
 This is a subclass of `SCGradientView` that makes it easier to render simple linear gradients.  It also has the added benefit of fully supporting UIAppearance for its color values, as well as Interface Builder designable and inspectable properties.
 */
@interface SCLinearGradientView : SCGradientView

/**
 The color for the beginning of the gradient.
 */
@property (nonatomic, strong) IBInspectable UIColor *startColor UI_APPEARANCE_SELECTOR;

/**
 The color for the end of the gradient.
 */
@property (nonatomic, strong) IBInspectable UIColor *endColor UI_APPEARANCE_SELECTOR;

/**
 The direction the gradient should go in.  Can be one of:
 
 * `SCLinearGradientDirectionAutomatic`
 * `SCLinearGradientDirectionHorizontal`
 * `SCLinearGradientDirectionVertical`
*/
@property (nonatomic) SCLinearGradientDirection direction;

/**
 Setter to animate the change of the start color.
 @param startColor The new starting color to set.
 @param animated   `YES` to animate the new color values, otherwise `NO`.
 */
- (void)setStartColor:(UIColor *)startColor animated:(BOOL)animated;

/**
 Setter to animate the change of the start color.
 @param endColor The new ending color to set.
 @param animated `YES` to animate the new color values, otherwise `NO`.
 */
- (void)setEndColor:(UIColor *)endColor animated:(BOOL)animated;

@end
