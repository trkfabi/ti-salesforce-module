//
//  SCSChatMinimizedView.h
//  ChatUI
//
//  Created by Thomas Myrden on 2016-06-07.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

@import ServiceCore.ServiceCommon;
@import ServiceCore.ServiceCommon.Private;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SCSChatMinimizedViewState) {
    SCSChatMinimizedViewStateConnecting = 1,
    SCSChatMinimizedViewStateQueuePosition,
    SCSChatMinimizedViewStateWaitTime,
    SCSChatMinimizedViewStateConnected,
    SCSChatMinimizedViewStateConnectedChatBot,
    SCSChatMinimizedViewStateFailure,
    SCSChatMinimizedViewStateEnded,
};

@class SCSChatMinimizedContentConnecting;
@class SCSChatMinimizedContentQueuePosition;
@class SCSChatMinimizedContentWaitTime;
@class SCSChatMinimizedContentConnected;
@class SCSChatMinimizedContentConnectedChatBot;
@class SCSChatMinimizedContentFailure;
@class SCSChatMinimizedContentEnded;

@interface SCSChatMinimizedView : SCSMinimizedView

@property (nonatomic, strong, readonly) SCSChatMinimizedContentConnecting *connectingView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentQueuePosition *queuePositionView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentWaitTime *waitTimeView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentConnected *connectedView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentConnectedChatBot *connectedChatBotView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentFailure *failureView;
@property (nonatomic, strong, readonly) SCSChatMinimizedContentEnded *endedView;
@property (nonatomic, strong, readonly) UIView<SCSLoadingIndicator> *loadingIndicator;
@property (nonatomic, assign) SCSChatMinimizedViewState state;
@property (nonatomic, assign) BOOL endedWithError;

- (void)setState:(SCSChatMinimizedViewState)state animated:(BOOL)animated;

@end

@interface SCSChatMinimizedView (UIAppearance)

@end

NS_ASSUME_NONNULL_END
