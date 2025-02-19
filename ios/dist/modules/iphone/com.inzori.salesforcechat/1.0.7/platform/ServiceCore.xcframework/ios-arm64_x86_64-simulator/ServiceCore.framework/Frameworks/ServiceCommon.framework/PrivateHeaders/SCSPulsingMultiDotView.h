//
//  SCSPulsingMultiDotView.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-12-14.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSPulsingMultiDotView : UIView

- (instancetype)initWithMinimumRadius:(CGFloat)minimumRadius
                        maximumRadius:(CGFloat)maximumRadius
                        bubbleSpacing:(CGFloat)bubbleSpacing
                    animationDuration:(CGFloat)animationDuration
                         numberOfDots:(CGFloat)numberOfDots
                         pulseOpacity:(BOOL)pulseOpacity;

@property (nonatomic, assign, getter=isAnimating) BOOL animating;

@property (nonatomic) UIColor *dotFillColor UI_APPEARANCE_SELECTOR;

@end
