//
//  SCSProgressLineAnimationView.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/5/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCSLoadingIndicator <NSObject>

@property (nonatomic, readonly, getter=isAnimating) BOOL animating;

- (void)startAnimating;
- (void)stopAnimating;

@end

@interface SCSProgressLineAnimationView : UIView <SCSLoadingIndicator>

/**
 The view that is animated.
 */
@property (nonatomic, strong, readonly) UIView *animationIndicator;

@end

@interface SCSProgressLineAnimationView (UIAppearance)

/**
 Size of the colored indicator view.
 */
@property (nonatomic, assign) CGSize indicatorSize UI_APPEARANCE_SELECTOR;

/**
 The color of the animated indicator view.
 */
@property (nonatomic, strong) UIColor *indicatorColor UI_APPEARANCE_SELECTOR;

/**
 The total duration of each loop of the animation.
 */
@property (nonatomic, assign) NSTimeInterval animationDuration UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
