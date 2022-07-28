//
//  SCSChatMinimizedContentConnected.h
//  ChatUI
//
//  Created by Michael Nachbaur on 9/5/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCSChatMinimizedContent.h"

NS_ASSUME_NONNULL_BEGIN

@class SCSChatMinimizedMessageView;
@interface SCSChatMinimizedContentConnected : SCSChatMinimizedContent

@property (nonatomic, strong, readonly) SCSChatMinimizedMessageView *messageView;
@property (nonatomic, strong) UIImage *agentAvatar;

@end

@interface SCSChatMinimizedContentConnected (UIAppearance)

@property (nonatomic, assign, getter=shouldCropImage) BOOL cropImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGSize minimumAvatarSize UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGSize messageViewOffset UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
