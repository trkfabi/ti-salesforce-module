//
//  SCGradientView.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/19/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

/**
 UIView subclass that displays a layer-based gradient view in the background.
 */
@interface SCGradientView : UIView

/**
 The underlying layer used to display the gradient.
 */
@property (nonatomic, retain, readonly) CAGradientLayer *gradientLayer;

/**
 Array of colors to display in the gradient.
 */
@property (nonatomic, strong) NSArray *colors;

/**
 The locations of the colors within the gradient.
 */
@property (nonatomic, strong) NSArray *locations;

/**
 The layer's type
 */
@property (nonatomic, copy) NSString *type;

/**
 The point in the layer where the gradient will start.
 */
@property (nonatomic) CGPoint startPoint;

/**
 The point in the layer where the gradient will end.
 */
@property (nonatomic) CGPoint endPoint;

/**
 Animated alternative to `setColors:` which will automatically perform an animation to transition from old color values to new values.
 @param colors   The new colors to set.
 @param animated `YES` to animate the new color values, otherwise `NO`.
 */
- (void)setColors:(NSArray *)colors animated:(BOOL)animated;

@end
