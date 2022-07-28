//
//  SCSWindow.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/19/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSStatusBar.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const SCSWindowDidShowNotification;
extern NSString * const SCSWindowDidHideNotification;
extern NSString * const SCSWindowCreatedNotification;
extern NSString * const SCSWindowDestroyedNotification;
extern NSString * const SCSPrimaryWindowChangedNotification;
extern NSString * const SCSWindowAuthoritativeControllerChangedNotification;
extern NSString * const SCSWindowContentStyleChangedNotification;

/**
 Definition of the style a controller's content contains, relative to other UI elements.
 */
typedef NS_ENUM(NSInteger, SCSContentStyle) {
    /** Light content –- the contents of the controller is lighter relative to other view controllers. */
    SCSContentStyleLightContent = 0,

    /** Dark content -- the contents of the controller may be darker relative to other view controllers. */
    SCSContentStyleDarkContent = 1,
};


@class SCSWindow, SCServiceCloud, SCAppearanceConfiguration;
@protocol SCSAttachmentOverlay;

/**
 Delegate protocol used to be informed of key events that occur within a window's lifecycle.
 */
@protocol SCSWindowDelegate <NSObject>

@optional

/**
 Informs the delegate when a subview is added to the window.  If the subview has been identified as belonging to a particular view controller, that controller will be supplied.
 
 @warning Due to implementation details within UIKit, this method may be called multiple times during an animated view controller transition, or when subviews change their order.
 
 @param window     The window instance.
 @param view       The view that was added.
 @param controller The controller this view belongs to, if found.
 */
- (void)window:(SCSWindow*)window didAddView:(UIView*)view forController:(nullable UIViewController*)controller;

/**
 Informs the delegate when a subview is removed from the window.  If the subview has been identified as belonging to a particular view controller, that controller will be supplied.
 
 @param window     The window instance.
 @param view       The view that was removed.
 @param controller The controller this view belongs to, if found.
 */
- (void)window:(SCSWindow*)window willRemoveSubview:(UIView*)view forController:(nullable UIViewController*)controller;

/**
 Informs the delegate when the window level changes.
 
 @param window          The window instance.
 @param newWindowLevel  The new window level.
 @param oldWindowLevel  The old window level.
 */
- (void)window:(SCSWindow*)window windowLevelChanged:(UIWindowLevel)newWindowLevel fromWindowLevel:(UIWindowLevel)oldWindowLevel;

/**
 Informs the delegate when the window changes its visibility.

 @param window     The window instance.
 @param hidden     Indicates whether or not the window is hidden.
 */
- (void)window:(SCSWindow*)window didChangeVisibility:(BOOL)hidden;

/**
 Informs the delegate when it has become occluded by another window.  In other words, when another window's windowLevel property is set to a higher value than the receiver.
 
 @warning This delegate method relies partly on window notifications, and partly on overridden methods in the SCSWindow subclass.  If a window doesn't inherit from SCSWindow, and its window level is changed after it is shown, this delegate method will not be called at that time.

 @param window Window that is being covered by another one.
 @param occlusionWindow Window that is covering the receiver.
 */
- (void)window:(SCSWindow*)window didBecomeOccludedByWindow:(UIWindow*)occlusionWindow;

/**
 Message sent to the receiver when the supplied window has become the top-most window.  This delegate method ignores system windows.
 
 @warning This delegate method relies partly on window notifications, and partly on overridden methods in the SCSWindow subclass.  If a window doesn't inherit from SCSWindow, and its window level is changed after it is shown, this delegate method will not be called at that time.

 @param window Window that is now the topmost window.
 */
- (void)windowDidBecomeTopMostWindow:(SCSWindow*)window;

/**
 Message sent to the receiver when the supplied window closes, or is dealloc'd.

 @param window Window that has been destroyed.
 */
- (void)windowDidClose:(SCSWindow*)window;

@end

/**
 Custom UIWindow subclass that adds advanced capabilities for monitoring the movements of view controllers within them, deferring control and ownership of status bar appearance, and to manage the interactions between multiple windows.
 
 SCSWindow instances need to be constructed with a particular SCServiceCloud instance to allow the windows to properly behave during unit tests, and to make it possible for the entire service cloud stack to be deconstructed as needed when the support experience is no longer needed within a host application.
 
 By using these windows, notifications can be broadcast for key events that not only allows the contents of these windows to be notified of important changes to their contents, but to be notified when changes in the windowing environment around them changes.
 
  * SCSWindowDidShowNotification – Broadcast when a window was shown.
  * SCSWindowDidHideNotification – Broadcast when a window was hidden.
  * SCSWindowCreatedNotification – Broadcast when a window is created.
  * SCSWindowDestroyedNotification – Broadcast when a window is deallocated.  Note that you shouldn't retain a reference to the object in this notification.
  * SCSWindowAuthoritativeControllerChangedNotification – Broadcast when a window's authoritative controller changes.  See `-[UIViewController(SCSAttachment) authoritativeController]` for more information.
  * SCSAuthoritativeAttachmentOverlayChangedNotification – Broadcast when the authoritative controller changes, and supplies the attachment overlay instance.  See `SCSAttachmentOverlay` for more information.
  * SCSViewControllerWillShowNotification – Broadcast when a view controller is shown.  This is sent when a modal view controller is presented, dismissed, when a detail item is changed in a split-view controller, or when a controller is pushed or popped on a navigation controller.  Under some circumstances this may not be broadcast.
  * SCSViewControllerDidShowNotification – Broadcast when the view controller previously mentioned has finished being shown.

 The view controller notifications are particularly useful since it can allow a more hands-off notification as to when the context of a window changes, and to make decisions about it at that time.  There are a series of keys that are sent along with the userInfo dictionary that are useful:
  * SCSViewControllerAnimatedKey – BOOL indicating if the transition is animated.
  * SCSViewControllerTransitionKey – If present, this is the animated transitioning context for the transition.  It can be used to animate other contents along with the view controller animation.
  * SCSViewControllerLastControllerKey – If present, this is the view controller that was previously presented prior to this notification (e.g. the previous navigation item).
 */
@interface SCSWindow : UIWindow <SCSStatusBar>

@property (nonatomic, weak, readonly) SCServiceCloud *serviceCloud;

/**
 Optional name to reference this window by.  This can be convenient when wanting to access presentation windows in a centralized fashion.
 
 It's important to note that windows containing only a root view controller will automatically be garbage collected when nothing else is referencing it.  However, when a view controller is presented modally onto it, the relationship of the presented view controller back to its presenting view controller will automatically create a retain cycle, keeping the window alive.
 
 This means that when all view controllers are dismissed, the window will be cleaned up.  This is convenient, because this means the name property can be used by the `windowWithName:` class method to return a window that may already exist.
 */
@property (nonatomic, copy) NSString *name;

/**
 Delegate to receive updates about changes to this window.
 */
@property (nonatomic, weak, nullable) NSObject<SCSWindowDelegate> *windowDelegate;

/**
 Indicates the offset that this window should maintain relative to the primary window's window level.
 
 If this value is assigned to `0.0` (the default), the window offset tracking functionality is disabled.
 */
@property (nonatomic, assign) UIWindowLevel windowLevelOffset;

+ (NSArray<__kindof SCSWindow*>*)windowWithName:(NSString*)name;

/**
 Designated initializer.  When creating a window, you must supply the SCServiceCloud instance to it on its constructor.
 
 @warning Do not simply pass the value from [SCServiceCloud sharedInstance].  It's important for your code to keep track of which SCServiceCloud instance it was created with, and pass that along, to avoid testability and tear-down problems in the future.

 @param serviceCloud SCServiceCloud instance
 @return Initialized window.
 */
- (instancetype)initWithServiceCloud:(SCServiceCloud*)serviceCloud NS_DESIGNATED_INITIALIZER;

/**
 Designated initializer.  When creating a window, you must supply the SCServiceCloud instance to it on its constructor.

 @warning Do not simply pass the value from [SCServiceCloud sharedInstance].  It's important for your code to keep track of which SCServiceCloud instance it was created with, and pass that along, to avoid testability and tear-down problems in the future.

 @param frame Frame
 @param serviceCloud SCServiceCloud instance
 @return Initialized window.
 */
- (instancetype)initWithFrame:(CGRect)frame serviceCloud:(SCServiceCloud*)serviceCloud NS_DESIGNATED_INITIALIZER;

/**
 Indicates whether or not this window wants the attachment window to float above it.
 
 Defaults to NO except within the SCSPresentationWindow.  Can be overridden by other subclasses.
 @return `YES` if the attachment window should float above this one, if it exists.
 */
- (BOOL)wantsAttachmentWindowVisible;

/**
 Indicates that some subclassable method value may have changed, and that the window should reevaluate its options.
 */
- (void)setNeedsUpdateWindowState;

/**
 Indicates whether or not this window supports the concept of authoritative controllers.
 
 Authoritative controllers are used by some classes, such as the SCSAttachmentWindow, to identify which controller in other windows are capable of making decisions on behalf of the window.  This allows the attachments window to change its state, or the visibility of its contents, depending on the changes that occur in other windows.
 
 By default this method returns `NO`, except for within the SCSPresentationWindow.
 
 @return `YES` if the window should be asked about its authoritative controllers, otherwise `NO` if it won't participate in that process.
 */
- (BOOL)supportsAuthoritativeViewControllers;

/**
 Returns the current attachment overlay controller within this window that is authoritative for making decisions about the attachments.

 @return Authoritative view controller conforming to SCSAttachmentOverlay, or `nil` if none was found or was considered appropriate.
 */
- (nullable __kindof UIViewController<SCSAttachmentOverlay>*)authoritativeAttachmentOverlayController NS_REQUIRES_SUPER;

/**
 Convenience method to return the ordered list of windows below the current one.  They are sorted in descending order.

 @return Sorted array of windows below the receiver.
 */
- (NSArray<UIWindow*> *)lowerWindows;

/**
 Convenience method to return the ordered list of windows above the current one.  They are sorted in ascending order.

 @return Sorted array of windows above the receiver.
 */
- (NSArray<UIWindow*> *)higherWindows;

@property (nonatomic, assign) SCSContentStyle contentStyle;

- (void)setContentStyle:(SCSContentStyle)contentStyle animated:(BOOL)animated;

- (void)willApplyAppearanceConfiguration:(SCAppearanceConfiguration*)configuration NS_REQUIRES_SUPER;
- (void)didApplyAppearanceConfiguration:(SCAppearanceConfiguration*)configuration NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
