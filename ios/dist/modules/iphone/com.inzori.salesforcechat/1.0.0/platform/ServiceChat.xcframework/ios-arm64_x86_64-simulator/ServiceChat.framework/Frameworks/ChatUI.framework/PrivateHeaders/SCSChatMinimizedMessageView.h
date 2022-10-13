//
//  SCSChatMinimizedMessageView.h
//  ChatUI
//
//  Created by Michael Nachbaur on 9/7/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSChatMinimizedView.h"
@import ServiceCore.ServiceCommon.Private;

NS_ASSUME_NONNULL_BEGIN

@interface SCSChatMinimizedMessageView : UIView <SCSLoadingIndicator>

@property (nonatomic, strong, readonly) UIImageView *imageView;
@property (nonatomic, strong, readonly) UILabel *countLabel;

@end

@interface SCSChatMinimizedMessageView (UIAppearance)

@property (nonatomic, assign) CGSize countLabelOffset UI_APPEARANCE_SELECTOR;

/**
 The total duration of each loop of the animation.
 */
@property (nonatomic, assign) NSTimeInterval animationDuration UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
