//
//  UIView+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Shared category on UIView that adds convenience properties to expose underlying CALayer properties as UIAppearance selectors.
 */
@interface UIView (ServiceCommon)

/**
 Appearance selector to expose the `layer.shadowColor` property.
 */
@property (nonatomic, strong) IBInspectable UIColor *shadowColor UI_APPEARANCE_SELECTOR;

/**
 Appearance selector to expose the `layer.shadowRadius` property.
 */
@property (nonatomic, assign) IBInspectable CGFloat shadowRadius UI_APPEARANCE_SELECTOR;

/**
 Appearance selector to expose the `layer.shadowOpacity` property.
 */
@property (nonatomic, assign) IBInspectable CGFloat shadowOpacity UI_APPEARANCE_SELECTOR;

/**
 Appearance selector to expose the `layer.shadowOffset` property.
 */
@property (nonatomic, assign) IBInspectable CGSize shadowOffset UI_APPEARANCE_SELECTOR;

/**
 Indicates the horizontal and vertical motion effect size for this view.
 
 This can automatically apply a Core Motion effect to the view, allowing it to alter its position based on the physical orientation of the device, giving it an appearance of 3D depth.  If a value is negative, it will make the view appear to be "below" the screen, whereas positive values causes the view to appear to float above the screen.
 
 @see addNaturalOnTopEffectWithMaximumRelativeValue:
 @see addNaturalBelowEffectWithMaximumRelativeValue:
 */
@property (nonatomic, assign) CGSize naturalMotionEffectSize UI_APPEARANCE_SELECTOR;

/**
 Adds a natural motion effect to the view, causing the view to appear to be floating "on top" of the screen.
 
 @param maximumRealtiveValue The maximum relative horizontal and vertical distances to apply to the effect.
 */
- (void)addNaturalOnTopEffectWithMaximumRelativeValue:(CGSize)maximumRealtiveValue;

/**
 Adds a natural motion effect to the view, causing the view to appear to be floating "below" the level of the screen.
 
 @param maximumRealtiveValue The maximum relative horizontal and vertical distances to apply to the effect.
 */
- (void)addNaturalBelowEffectWithMaximumRelativeValue:(CGSize)maximumRealtiveValue;

@end
