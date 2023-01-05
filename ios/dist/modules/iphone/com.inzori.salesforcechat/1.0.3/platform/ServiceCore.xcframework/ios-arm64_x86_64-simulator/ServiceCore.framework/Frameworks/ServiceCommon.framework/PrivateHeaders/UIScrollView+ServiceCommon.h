//
//  UIScrollView+ServiceCommon.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 9/8/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SCSScrollDirection) {
    SCSScrollDirectionUnknown,
    SCSScrollDirectionUp,
    SCSScrollDirectionDown,
};

@interface UIScrollView (ServiceCommon)

/**
 Direction the receiver is being scrolled in.  Conforms to KVO.
 */
@property (nonatomic, readonly) SCSScrollDirection scrollDirection;

/**
 Estimated velocity, in points/ms, this scroll view is scrolling in.  Convorms to KVO.
 */
@property (nonatomic, readonly) CGPoint scrollVelocity;

/**
 Requests that scroll direction tracking be enabled.
 */
- (void)beginScrollDirectionTracking;

/**
 Requests that scroll direction tracking be ended.
 */
- (void)endScrollDirectionTracking;

@end
