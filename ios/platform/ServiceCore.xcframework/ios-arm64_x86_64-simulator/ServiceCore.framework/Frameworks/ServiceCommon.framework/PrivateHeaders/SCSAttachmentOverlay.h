//
//  SCSAttachmentOverlay.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 4/15/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSWindow.h"

@class SCSAttachment;

/**
 Protocol used by controllers who wish to participate in, or influence, the behavior of any attachment controllers that may be present above it.
 
 @see SCSAttachmentContainerViewController
 @see SCSAttachmentController
 @see SCSAttachment
 */
@protocol SCSAttachmentOverlay <NSObject>

@optional

/**
 Message sent to the receiver to determine if the indicated attachment should be visible.
 
 @param attachment Attachment that may, or may not, be floating above the receiver.
 
 @return `YES` if the attachment should be visible, otherwise `NO`.
 */
- (BOOL)shouldShowAttachmentOverlay:(SCSAttachment*)attachment;

/**
 Provides the receiver with the opportunity to return a relevant scroll view that should influence the behavior of attachments presented above it.
 
 @param attachment The attachment to determine.
 
 @return A UIScrollView instance that the attachment may be interested in, otherwise `nil`.
 */
- (UIScrollView *)scrollViewInfluencingAttachment:(SCSAttachment*)attachment;

/**
 Indicates which subview, within the presented controller, should be used to constrain the alignment of the supplied attachment.  This can be used when a particular attachment must be constrained to a particular location within the screen.
 
 @param attachment The attachment to consider.
 @return The view to constrain the supplied attachment to, or `nil` if the attachment shouldn't be constrained to anything within the current controller.
 */
- (UIView*)viewToConstrainOverlayForAttachment:(SCSAttachment*)attachment;

/**
 Provides the receiver the opportunity to indicate whether or not the attachment window should occlude / overlay the receiver's window.
 
 This is useful when a window may change its window level, but doesn't want the attachment window to float above it.

 @note This method is only called when the receiver's window changes its window level.  It will not be proactively called, nor will changes in the return value be detected unless the window level changes.

 @return `YES` if the attachment window should not be overlaid on this controller, or `NO` if the attachment window should be relocated.
 */
- (BOOL)preventAttachmentWindowOcclusion;

/**
 Provides a hint about what kind of content is displayed, and whether or not the content can be described as dark, or light.  This can be used by other windows floating above this controller to alter their display to complement it, if their content is visible.
 @return SCSContentStyle type indicating the type of content this controller displays.  Defaults to `SCSContentStyleLightContent` if not implemented.
 */
- (SCSContentStyle)preferredContentStyle;


/**
 Allows controllers to indicate when they would prefer the action container to be hidden for them.

 Note that this is simply a preference on the part of the action subsystem, and the developer integrating the ServiceSDK may choose to override this decision, and allow the action bar to be presented anyway.

 @return `YES` if the action container should be hidden.
 */
- (BOOL)prefersActionContainerHidden;

@end
