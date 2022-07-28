//
//  SCSChatFullscreenContainerView.h
//  ChatUI
//
//  Created by Michael Nachbaur on 7/12/19.
//  Copyright © 2019 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCSChatFullscreenContainerView : UIView

@end

@interface SCSChatLargeConnectingIcon : UIImageView

@end

@interface SCSChatConnectingErrorIcon : UIImageView

@end

@interface SCSChatErrorDetailLabel : UILabel

@end

@interface SCSChatQueuePositionLabel : UILabel

@end

@interface SCSChatQueueStatusLabel : UILabel

@end

@interface SCSChatFullscreenInfoLabel : UILabel

@end

@interface SCSChatFullscreenErrorLabel : UILabel

@end

@interface SCSChatWaitForAgentLabel : UILabel

@end

@interface SCSChatQueueInformationContainerView : UIView

@end

typedef NS_ENUM(NSUInteger, SCSChatFullscreenViewState) {
    SCSChatFullscreenViewStateConnecting = 1,
    SCSChatFullscreenViewStateQueuePosition,
    SCSChatFullscreenViewStateWaitTime,
    SCSChatFullscreenViewStateEnded,
};

@interface SCSChatFullscreenView : SCSChatFullscreenContainerView

@property (nonatomic, strong, readonly) UIView<SCSLoadingIndicator> *loadingIndicator;
@property (nonatomic, strong, readonly) SCSChatQueuePositionLabel *queuePositionLabel;
@property (nonatomic, strong, readonly) SCSChatQueueStatusLabel *queueStatusLabel;
@property (nonatomic, strong, readonly) SCSChatFullscreenInfoLabel *queuePositionInfo;
@property (nonatomic, strong, readonly) SCSChatWaitForAgentLabel *waitForAgentLabel;
@property (nonatomic, strong, readonly) SCSChatFullscreenErrorLabel *errorLabel;
@property (nonatomic, strong, readonly) SCSChatErrorDetailLabel *errorDetailLabel;
@property (nonatomic, strong, readonly) SCSChatFullscreenContainerView *queuePositionContainerView;
@property (nonatomic, strong, readonly) SCSChatFullscreenContainerView *connectingContainerView;
@property (nonatomic, strong, readonly) SCSChatFullscreenContainerView *errorContainerView;
@property (nonatomic, assign) SCSChatFullscreenViewState state;
@property (nonatomic, assign) SCSChatEndReason endReason;
@property (nonatomic, strong, readonly) SCSChatQueueInformationContainerView *queueInformationContainerView;

- (void)setState:(SCSChatFullscreenViewState)state animated:(BOOL)animated;


@end

NS_ASSUME_NONNULL_END
