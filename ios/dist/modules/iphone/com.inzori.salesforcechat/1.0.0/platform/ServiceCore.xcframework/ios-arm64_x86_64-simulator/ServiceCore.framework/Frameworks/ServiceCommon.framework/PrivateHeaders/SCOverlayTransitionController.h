//
//  SCOverlayTransitionController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/20/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCOverlayPresentationController, SCServiceCloud;
@protocol SCOverlayPresentationControllerDelegate;
@interface SCOverlayTransitionController : NSObject <UIViewControllerTransitioningDelegate>

@property (nonatomic, weak, nullable, readonly) SCServiceCloud *serviceCloud;
@property (nonatomic, weak, nullable) NSObject <SCOverlayPresentationControllerDelegate> *overlayDelegate;
@property (nonatomic, copy) void (^configurePresentationControllerBlock)(SCOverlayPresentationController *presentationController);

- (instancetype)initWithViewController:(UIViewController*)controller __deprecated_msg("Please use the -initWithServiceCloud:viewController: initializer instead");
- (instancetype)initWithServiceCloud:(SCServiceCloud*)serviceCloud viewController:(UIViewController*)controller NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
