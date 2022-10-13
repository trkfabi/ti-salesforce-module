//
//  SCSChatMinimizedContent.h
//  ChatUI
//
//  Created by Michael Nachbaur on 2017-09-06.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCSChatMinimizedMainView : UIView
@end

@interface SCSChatMinimizedFooterView : UIView
@end

@interface SCSChatMinimizedContent : UIView

@property (nonatomic, strong, readonly) SCSChatMinimizedMainView *mainView;
@property (nonatomic, strong, readonly) SCSChatMinimizedFooterView *footerView;
@property (nonatomic, strong, readonly) UIStackView *stackView;
@property (nonatomic, strong, readonly) UILabel *footerTextLabel;
@property (nonatomic, strong, readonly) UIImageView *iconImageView;

@end

@interface SCSChatMinimizedContent (UIAppearance)

@property (nonatomic, assign) UIEdgeInsets contentViewPadding UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat contentViewSpacing UI_APPEARANCE_SELECTOR;

@end


NS_ASSUME_NONNULL_END
