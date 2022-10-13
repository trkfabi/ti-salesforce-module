//
//  UIViewController+SCSErrorView.h
//  ServiceCommon
//
//  Created by Amit Gosar on 4/19/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCErrorView.h"

@interface UIViewController (SCSErrorView)

@property (nonatomic, strong, readonly) SCErrorView *errorView;
@property (nonatomic) UIEdgeInsets errorViewOuterInsets;
@property (nonatomic) CGFloat keyboardHeight;
@property (nonatomic, weak) UIView *errorParentView;
@property (nonatomic, assign, readonly, getter=isErrorViewVisible) BOOL errorViewVisible;

- (void)showError:(BOOL)show animated:(BOOL)animated;

@end
