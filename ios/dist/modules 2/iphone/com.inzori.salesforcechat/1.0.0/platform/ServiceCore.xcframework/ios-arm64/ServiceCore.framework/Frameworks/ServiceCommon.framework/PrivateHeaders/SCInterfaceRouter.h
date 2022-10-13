//
//  SCUAppearanceRouter.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 10/28/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCInterfaceStyle;
@class SCServiceCloud, SCAppearanceConfiguration, SFCContainer;

/**
 Factory container class to manage a collection of SCInterfaceStyle instances responsible for presenting and managing the display and navigation of a collection of view controllers.
 
 The router provies an abstraction layer to collect interface style instances and allows different UI components to communicate, potentially distributed across multiple sublibrary targets that may not have visibility to one-another.
 */
@interface SCInterfaceRouter : NSObject

/**
 Registers a class to respond to a given interface style.
 
 This is the primary entry point for enrolling a class to handle events, interface decisions, or other behavioral interactions to a shared interface.  No judgements are made about which classes should respond, but the various interface handler classes are collected together into the interface style router.  This router is then used by the shared interface singleton to delegate decisions about interface navigation events, UI transition controllers, and other behaviors.
 
 It is up to the implementation to determine how to access the appropriate objects.  Either directly accessing the allInterfaceStyleHandlers property to iterate through the registered handler instances, or utilizing interfaceStylesConformingToProtocol: to limit the handlers to those that are needed for a particular capability, are useful.
 @param styleClass The class to register.
 @param style      The style name to associate this class with.
 */
+ (void)registerClass:(Class)styleClass forStyle:(NSString*)style;

/**
 Readonly property returning the service cloud instance supplied to the initializer.
 @see SCServiceCloud
 */
@property (nonatomic, weak, readonly) SCServiceCloud *serviceCloud;

/**
 Readonly convenience method for accessing the shared authentication container.
 @see SFCContainer
 */
@property (nonatomic, weak, readonly) SFCContainer *container;

/**
 Readonly property to return the style name this handler instance is currently adopting.
 
 This value may change if it supports the adoptInterfaceStyle: method, and the interface style changes at runtime.
 */
@property (nonatomic, copy, readonly) NSString *interfaceStyle;

/**
 Accessor to retrieve the full list of handlers for this interface style.
 @see SCInterfaceStyle
 */
@property (nonatomic, strong, readonly) NSArray<NSObject<SCInterfaceStyle>*> *allInterfaceStyleHandlers;

/**
 Designated initializer that returns an interface style router with the given style.
 @param serviceCloud The service cloud instance constructing this router.
 @param style        Interface style to use.
 @see SCServiceCloud
 */
- (instancetype)initWithServiceCloud:(SCServiceCloud*)serviceCloud interfaceStyle:(NSString*)style NS_DESIGNATED_INITIALIZER;

/**
 Transitions to the given interface style.  If any handlers active within this interface router are capable of adapting to the new style (e.g. they respond to the [SCInterfaceStyle adoptInterfaceStyle:] method and return `YES`), they will be preserved during the transition.
 @param style New interface style to transition to.
 */
- (void)transitionToInterfaceStyle:(NSString*)style;

/**
 Returns a subset of the interface styles conforming to the given protocol.
 @param protocol The protocol members must conform to.
 @see SCInterfaceStyle
 */
- (nullable NSArray<NSObject<SCInterfaceStyle>*> *)interfaceStylesConformingToProtocol:(Protocol*)protocol;

@end

/**
 ## View controller presentation

 These methods relate to controlling how view controllers are influenced when controllers are presented.  This provides an opportunity for transitioning delegates to be specified.
 
 Interface style instances that conform to SCInterfacePresentation can override the [transitioningDelegateForPresentedController:presentingController:]([SCInterfacePresentation transitioningDelegateForPresentedController:presentingController:]) method to define a default transitioning delegate when being presented.  This value may be overridden by the [SCServiceCloudDelegate serviceCloud:transitioningDelegateForViewController:] delegate method.
 */
@interface SCInterfaceRouter (ViewControllerPresentation)

/**
 Requests a transitioning delegate for the given controller from the various interface style instances that conform to SCInterfacePresentation.
 @param presentingController View controller about to be presented
 @param presentedController View controller the target controller is being presented from.
 @return Object conforming to UIViewControllerTransitioningDelegate, or `nil` if no transitioning delegate is needed.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)transitioningDelegateForPresentedController:(UIViewController*)presentedController presentingController:(UIViewController*)presentingController;

/**
 Requests the given presentation controller to be customized, as needed, prior to use.
 @param presentationController Presentation controller about to be used when presenting another controller.
 */
- (void)applyStyleToPresentationController:(UIPresentationController*)presentationController;

@end

@class SCSEvent;

/**
 ## Interface event responder
 
 When interaction events are broadcast (e.g. SCSEvent instances), it provides an opportunity for various components to respond to those events and present the necessary UI operations, without the need for explicit dependencies between the sender and receiver(s).
 
 Components that want to send an event can supply an SCSEvent instance to the [sendInteractionEvent:]([SCInterfaceRouter sendInteractionEvent:]) method.
 */
@interface SCInterfaceRouter (SCInterfaceEventResponder)

/**
 Sends the given event to the appropriate interface handler that supports the SCInterfaceEventResponder protocol.
 
 The appropriate handler or handlers will be given the opportunity to respond to the event.
 
 @discussion
 If no interaction responder is available for the receiver, then the event will be silently ignored.
 
 @param event Event to send.
 @return `YES` if the event has been handled, otherwise `NO` means no responder was available to handle the event.
 @see SCSEvent
 */
- (BOOL)sendInteractionEvent:(SCSEvent*)event;

/**
 Returns a view controller capable of handling the given event.
 
 This allows an arbitrary event to be fired from one component in the SDK, and to receive another view controller in response.
 
 @warning It is not recommended to return any container controllers such as UINavigationController, UISplitViewController, etc.  The intent is for the returned controller to be hosted within the caller somehow, and it is up to the discretion of the caller to handle it as they see fit.
 @param event Event to be handled.
 @return View controller capable of handling the given event, or `nil` if no controller was available.
 */
- (nullable __kindof UIViewController*)viewControllerForEvent:(SCSEvent*)event;

@end

@protocol SCSActionItemContainer, SCSActionItem;
/**
 ## Interface actions (Floating Action Bar)
 
 These methods relate to the floating action bar (aka FAB), allowing components to control the visibility of individual action buttons, or the action bar as a whole.  It also exposes the action display view controller to provide direct control over adding SCSActionItem instances directly.
 
 There are two primary ways action buttons can be managed:
 
 1. Implicitly defined action buttons, which are implicitly added by the [SCInterfaceAction] interface styles, or;
 2. Explicitly added action buttons by adding them directly to the [actionItemContainer]([SCInterfaceRouter actionItemContainer]) using the [addActionView:forName:preferredSortIndex:animated:]([SCSActionItemContainer addActionView:forName:preferredSortIndex:animated:]) method.
 
 Components can drive the visibility of these buttons, regardless of being implicitly or explicitly added, using the [setActionVisible:name:animated:]([SCInterfaceRouter setActionVisible:name:animated:]) method, [isActionVisible:]([SCInterfaceRouter isActionVisible:]), and the action bar itself can be shown or hidden through the use of [setActionButtonsVisible:animated:]([SCInterfaceRouter setActionButtonsVisible:animated:]).
 */
@interface SCInterfaceRouter (SCInterfaceAction)

/**
 Sets the visibility status of an interface action item with the given name.
 
 @param visible    `YES` if the action should be shown on the action bar, otherwise `NO` if the action should not be shown.
 @param actionName Name of the action, as returned from [SCInterfaceAction availableInterfaceActions]
 @param animated   `YES` if the action item should be animated, otherwise `NO`.
 */
- (void)setActionVisible:(BOOL)visible name:(NSString*)actionName animated:(BOOL)animated;

/**
 Indicates whether or not the supplied action is visible.
 
 @param actionName Action name.
 
 @return `YES` if the action is visible.
 */
- (BOOL)isActionVisible:(NSString*)actionName;

/**
 Enables or disables the entire action bar.
 
 @param actionButtonsVisible Boolean indicating if the action bar should be visible.
 @param animated             Animated.
 */
- (void)setActionButtonsVisible:(BOOL)actionButtonsVisible animated:(BOOL)animated;

/**
 Performs the action associated with the action name for the supplied action item.
 
 @param actionName Name of the action to perform
 @param actionItem Action item for which the action needs to be performed.
 
 @return 'YES' if the action is successfully performed, 'NO' otherwise.
 */
- (BOOL)performActionWithName:(NSString*)actionName actionItem:(nullable UIView<SCSActionItem>*)actionItem;

@end

@class SCSNotification;

/**
 ## Notification handling
 
 When notifications are received that may or may not need to be processed within the ServiceSDK, these methods are exposed within the interface router to notify it when notifications are received, and to respond to actionable notifications.
 
 Interface styles that conform to [SCSInterfaceNotificationResponder] can respond to notifications in direct response to the [SCInterfaceRouter] notification handling methods.
 */
@interface SCInterfaceRouter (SCSNotifications)

/**
 Sends the given notification to the appropriate interface handler that supports the SCSInterfaceNotificationResponder protocol.
 
 The appropriate handler or handlers will be given the opportunity to respond to the notification.
 
 @discussion
 If no interaction responder is available for the receiver, then the notification will be silently ignored. This method can be used 
 by responders to prefetch data related to the notification before showing the interface.
 
 @param notification SCSNotification to send.
 @return `YES` if the notification has been handled, otherwise `NO` means no responder was available to handle the notification.
 @see SCSNotification
 */
- (BOOL)didReceiveNotification:(SCSNotification*)notification;

/**
 Sends the given notification to the appropriate interface handler that supports the SCSInterfaceNotificationResponder protocol.
 
 The appropriate handler or handlers will be given the opportunity to respond to the notification.
 
 @discussion
 If no interaction responder is available for the receiver, then the notification will be silently ignored. This method can be used 
 by responders to navigate to the viewController of choice.
 
 @param notification SCSNotification to send.
 @return `YES` if the notification has been handled, otherwise `NO` means no responder was available to handle the notification.
 @see SCSNotification
 */
- (BOOL)showInterfaceForNotification:(SCSNotification*)notification;

@end

NS_ASSUME_NONNULL_END
