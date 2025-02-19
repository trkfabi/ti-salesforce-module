//
//  SCSEdgeAttachmentView.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/12/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import "SCSAttachment.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Instance of an SCSAttachment that is intrinsically bound to a specific edge of the screen.
 */
@interface SCSEdgeAttachment : SCSAttachment

/**
 Edge of the screen to be attached to, defaults to CGRectMaxYEdge.
 
 Changing this value will cause the controller to reattach itself to the indicated edge.
 */
@property (nonatomic, assign) CGRectEdge edge;

/**
 Designated initializer.
 
 @param controller Child controller to attach.  Must conform to SCSAttachmentController.
 @param edge       Edge to attach the controller to.
 @return Initialized object.
 */
- (instancetype)initWithController:(UIViewController<SCSAttachmentController>*)controller edge:(CGRectEdge)edge NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
