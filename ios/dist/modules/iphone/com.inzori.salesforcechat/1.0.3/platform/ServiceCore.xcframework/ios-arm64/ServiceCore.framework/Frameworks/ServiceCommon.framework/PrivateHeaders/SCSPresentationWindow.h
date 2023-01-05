//
//  SCSPresentationWindow.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/20/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSWindow.h"
#import "SCSAttachment.h"

#ifndef SCS_MINIMIZABLE_SUPPORTED
#import "SCSMinimizable.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol SCSAttachmentController;
@class SCSPresentationWindow;

extern CGPoint const SCSPresentationWindowPreviousPoint;
extern CGPoint const SCSPresentationWindowDefaultPoint;

/**
 Delegate protocol used to be informed of key events that occur within a presentation window's lifecycle.
 */
@protocol SCSPresentationWindowDelegate <SCSWindowDelegate>

@optional

/**
 Overrides the attachment controller to use when the presentation window is minimized.  The default implementation renders the window's contents as an image and scales it down to the target attachment.
 
 @param window The window instance.
 @return View controller to represent the minimization target, or `nil` if no thumbnail should be used.
 */
- (nullable __kindof UIViewController<SCSAttachmentController>*)minimizationAttachmentControllerForWindow:(SCSPresentationWindow*)window;

/**
 Overrides the attachment controller to use when the presentation window is minimized.  The default implementation renders the window's contents as an image and scales it down to the target attachment.
 
 The point is a floating point value between 0.0 and 1.0 to indicate a relative position across the screen.  If any dimension in the point is larger than 1.0, it will be assumed to be an absolute position on the screen, and its value will be converted.  If you want to accept the previous position the attachment was minimized to, you can return the constant `SCSPresentationWindowPreviousPoint`.

 @param window The window instance.
 @param attachment The minimized attachment.
 @return View controller to represent the minimization target, or `nil` if no thumbnail should be used.
 */
- (CGPoint)window:(SCSPresentationWindow*)window destinationPointForMinimizedAttachment:(SCSAttachment*)attachment;

/**
 Informs the receiver when the minimized attachment is moved to a new point.
 
 @param window The window instance.
 @param attachment The minimized attachment being moved.
 @param point The new center point for the attachment.
 */
- (void)window:(SCSPresentationWindow*)window minimizedAttachment:(SCSAttachment*)attachment movedToPoint:(CGPoint)point;

/**
 Notifies the receiver when the window will be minimized.
 
 @param window The window being minimized.
 @param attachment The attachment the window will be minimized to.  May be `nil` if the minimizationAttachmentControllerForWindow: method returns `nil`.
 @param animated Whether or not the minimization will be animated.
 */
- (void)window:(SCSPresentationWindow*)window windowWillMinimizeToAttachment:(nullable SCSAttachment*)attachment animated:(BOOL)animated;

/**
 Notifies the receiver when the window minimization is complete.

 @param window The window being minimized.
 @param attachment The attachment the window was minimized to.  May be `nil` if the minimizationAttachmentControllerForWindow: method returns `nil`.
 @param animated Whether or not the minimization was animated.
 */
- (void)window:(SCSPresentationWindow*)window windowDidMinimizeToAttachment:(nullable SCSAttachment*)attachment animated:(BOOL)animated;

/**
 Notifies the receiver when the window will be maximized.

 @param window The window being maximized.
 @param attachment The attachment the window will be maximized from.  May be `nil` if the minimizationAttachmentControllerForWindow: method returned `nil`.
 @param animated Whether or not the maximization will be animated.
 */
- (void)window:(SCSPresentationWindow*)window windowWillMaximizeFromAttachment:(nullable SCSAttachment*)attachment animated:(BOOL)animated;

/**
 Notifies the receiver when the window was maximized.

 @param window The window being maximized.
 @param attachment The attachment the window was maximized from.  May be `nil` if the minimizationAttachmentControllerForWindow: method returned `nil`.
 @param animated Whether or not the maximization was animated.
 */
- (void)window:(SCSPresentationWindow*)window windowDidMaximizeFromAttachment:(nullable SCSAttachment*)attachment animated:(BOOL)animated;

@end

/**
 Window used for presenting a modal stack of view controllers over the host application.
 
 This can be used, for example, to present the Knowledge service interface.  Similarly, a separate window of this instance type may be constructed specifically for the Chat experience.  Separating these stacks into separate windows allows entire sets of controllers to be shown and hidden, or dismissed in bulk, without interfering with each other.
 
 The root view controller defaults to a special controller that defaults to be completely transparent, and passes touches down to lower windows.  Any modal view controller presented on top of this will have its transitioning delegate automatically applied from the SCServiceCloud instance.
 */
@interface SCSPresentationWindow : SCSWindow<SCSMinimizable>

/**
 Delegate to receive updates about changes to this window.
 */
@property (nonatomic, weak, nullable) NSObject<SCSPresentationWindowDelegate> *windowDelegate;

/**
 If the window is minimized, this property contains the attachment that represents the minimized window.  This attachment contains the view controller returned from the `-[SCSPresentationWindowDelegate minimizationAttachmentControllerForWindow:]` method, or the automatic default.  If that delegate method returns `nil`, then no attachment will be stored in this property.
 */
@property (nullable, nonatomic, weak, readonly) SCSAttachment *minimizedAttachment;

@end

NS_ASSUME_NONNULL_END
