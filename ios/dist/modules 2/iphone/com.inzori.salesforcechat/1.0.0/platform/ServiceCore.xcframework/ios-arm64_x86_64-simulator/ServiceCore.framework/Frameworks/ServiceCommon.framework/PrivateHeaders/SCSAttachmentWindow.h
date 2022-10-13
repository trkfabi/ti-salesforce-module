//
//  SCSAttachmentWindow.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/20/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSWindow.h"
#import "SCSAttachmentContainerViewController.h"

NS_ASSUME_NONNULL_BEGIN

SCS_EXTERN NSString * const SCSAuthoritativeAttachmentOverlayChangedNotification;

/**
 Window used specifically for presenting attachemnts and the attachment controller.
 */
@interface SCSAttachmentWindow : SCSWindow

@property (nullable, nonatomic, strong) SCSAttachmentContainerViewController *rootViewController;

- (NSArray<UIViewController<SCSAttachmentOverlay>*> *)authoritativeAttachmentOverlays;

/**
 Forces the attachment window to reevaluate its target window level.
 */
- (void)updateWindowLevel;

- (void)updateContentStyle;

@end

NS_ASSUME_NONNULL_END
