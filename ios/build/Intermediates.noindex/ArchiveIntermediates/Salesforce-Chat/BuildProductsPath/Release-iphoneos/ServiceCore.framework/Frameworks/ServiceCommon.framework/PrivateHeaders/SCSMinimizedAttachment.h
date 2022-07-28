//
//  SCSMinimizedAttachment.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 4/19/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCSPointAttachment.h"

@class SCSWindow;
@protocol SCSMinimizable;

NS_ASSUME_NONNULL_BEGIN

/**
 Variant of a SCSPointAttachment that is used to represent a minimized window.
 */
@interface SCSMinimizedAttachment : SCSPointAttachment

/**
 Minimized window that this attachment represents.
 */
@property (nonatomic, weak, readonly) SCSWindow<SCSMinimizable> *minimizedWindow;

/**
 Designated initializer.

 @param controller Attachment content controller.
 @param minimizedWindow Minimized window that this attachment represents.
 @param centerPoint Initial center point.
 */
- (instancetype)initWithController:(UIViewController<SCSAttachmentController> *)controller minimizedWindow:(SCSWindow<SCSMinimizable>*)minimizedWindow centerPoint:(CGPoint)centerPoint;

@end

NS_ASSUME_NONNULL_END
