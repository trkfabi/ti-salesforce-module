//
//  UIViewController+SCActivityIndicator.h
//  ServiceSDK
//
//  Created by Amit Gosar on 7/9/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SCSLoading;

/**
 Category adding support for embedding activity indicators in a generic fashion to basic view controllers.  Note that this doesn't work as expected for view controllers that have a tyep of UIScrollView as the `self.view`.
 */
@interface UIViewController (SCSLoading)

/**
 Activity indicator view.  Can be explicitly assigned, or can be lazily loaded with a default.
 */
@property (nonatomic, strong) UIView<SCSLoading> *activityIndicatorView;

/**
 Overrides the superview where the activity indicator will be assigned.  If not used, the activity indicator is automatically added to `self.view`.
 
 @param containerView Container view where the activity indicator should be added.
 */
- (void)setActivityIndicatorSuperView:(UIView*)containerView;

@end
