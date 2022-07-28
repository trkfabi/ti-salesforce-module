//
//  SCErrorView.h
//  ServiceSDK
//
//  Created by Jyoti Khubchandani on 3/16/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCAppearanceConfiguration;

NS_ASSUME_NONNULL_BEGIN

@interface SCErrorView : UIView

@property (null_resettable, nonatomic, copy) SCAppearanceConfiguration *appearanceConfiguration;
@property (nullable, nonatomic, copy) NSString *errorImageName;
@property (nonatomic, strong, readonly) UILabel *errorTitle;
@property (nonatomic, strong, readonly) UILabel *errorDescription;

@property (nonatomic, strong) UIColor *errorTitleLabelColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *errorTitleLabelFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *errorDescriptionLabelColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *errorDescriptionLabelFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *errorImageColor UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
