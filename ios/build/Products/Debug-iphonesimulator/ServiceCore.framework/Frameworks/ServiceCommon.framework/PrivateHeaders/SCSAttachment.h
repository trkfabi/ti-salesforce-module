//
//  SCSAttachment.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/12/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Attachment animation operation types that may be supplied to [SCSAttachmentController animationControllerForAttachment:forTransitionOperation:].
 */
typedef NS_ENUM(NSInteger, SCSAttachmentControllerOperation) {
    /** No transition is occurring. */
    SCSAttachmentControllerOperationNone,

    /** The attachment controller will be shown. */
    SCSAttachmentControllerOperationShow,

    /** The attachment controller will be hidden. */
    SCSAttachmentControllerOperationHide,
};

@class SCSAttachment;

/**
 Protocol used to define controllers that are capable of being bound to an attachment.
 
 All methods defined within this protocol are optional, but can be adopted individually to provide the controller with more influence over how it interacts with the view controllers surrounding it.
 */
@protocol SCSAttachmentController <NSObject>

@optional

/**
 If the receiver is capable of interacting with scroll views, this method should return `YES`.  Otherwise the default is to skip this controller when working with scroll views.
 
 @warning It is a programmer error if only one of interactsWithOverlayScrollViews: or setOverlayScrollView: is implemented by the receiver
 @return `YES` if this attachment should be notified when a scroll view is availabile, otherwise `NO`.
 @see -[SCSAttachmentOverlay scrollViewInfluencingAttachment]
 */
- (BOOL)interactsWithOverlayScrollViews;

/**
 Message sent to the receiver when the active overlay scroll view changes.
 
 @warning It is a programmer error if only one of interactsWithOverlayScrollViews: or setOverlayScrollView: is implemented by the receiver
 @param scrollView New primary scroll view, or `nil` if no primary scroll view is present.
 @see interactsWithOverlayScrollViews
 */
- (void)setOverlayScrollView:(nullable UIScrollView*)scrollView;

/**
 Indicates which level this attachment should be shown in within the view hierarchy.
 
 If this method is not implemented, a default value of `0.0` is assumed.  Higher number values results in the attachment being placed above others with lower values.
 */
- (CGFloat)attachmentLevel;

/**
 Indicates if the given attachment should defer its visibility to view controllers that are presented below it.
 
 This means view controllers that conform to SCSAttachmentOverlay can control the visibility of this attachment automatically.
 
 If this method is not implemented, the default is `YES`.

 @return `YES` if the controller should adapt its visibility as view controllers navigate, otherwise `NO` if this controller wants control over visibility to be explicit.
 */
- (BOOL)shouldAutomaticallyAdaptVisibility;

/**
 Optional method allowing a controller to customize the appearance transition for its associated attachment.
 
 @param attachment The attachement being animated.
 @param operation  The style of transition operation being performed.
 @return Animator instance conforming to UIViewControllerAnimatedTransitioning, or `nil` for a default transition.
 @see SCSAttachment
 */
- (nullable id <UIViewControllerAnimatedTransitioning>)animationControllerForAttachment:(SCSAttachment*)attachment
                                                                 forTransitionOperation:(SCSAttachmentControllerOperation)operation;

@end

@class SCSAttachmentContainerViewController;

/**
 This class represents a view that can be attached to a SCSAttachmentContainerViewController instance.  These views are the containers that manage the position and behaviors of child controllers that can be presented omnipresently over other controllers.
 
 Attachments are specialized views that represents a child controller which can be positioned at arbitrary locations on the screen, presented in an omnipresent fashion above all other controllers.  These attachments encapsulate the logic of that positioning, and has facilities to interact with the controllers around it.
 
 These attachments need to be initialized with a view controller that conforms to the SCSAttachmentController protocol.  These attachments then respond and behave in different ways depending on which view controllers are presented on the screen (either modally, within navigation controllers, etc).  Those controllers may optionally conform to the SCSAttachmentOverlay protocol to indicate which attachments are capable of being presented along side them.
 */
@interface SCSAttachment : UIView

/**
 Access to the controller supplied to the initializer.  Setting this value will result in that new controller being presented within this attachment.
 @see SCSAttachmentController
 */
@property (nonatomic, strong, nullable) UIViewController<SCSAttachmentController> *controller;

/**
 Convenience property to refer to the parent attachment container controller.
 
 @see SCSAttachmentContainerViewController
 */
@property (nonatomic, weak, readonly) SCSAttachmentContainerViewController *attachmentContainerController;

/**
 Name to identify this attachment by.  Can be used in conjunction with [SCSAttachmentContainerViewController attachmentWithName:].
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Boolean property indicating whether or not the controller within this attachment is dismissed.  When an attachment is dismissed, it is still present within the view hierarchy, but the controller contained within it is dismissed.  That controller's appearance methods will be called as appropriate to indicate when the views will disappear, or when they reappear.
 
 Setting this value will perform a non-animated transition.  To perform an animated transition, see the setDismissed:animated: method.
 
 This value defaults to `YES`.
 */
@property (nonatomic, assign, getter=isDismissed) BOOL dismissed;

/**
 Convenience method to remove the attachment from its parent controller.
 */
- (void)removeAttachment;

/**
 Designated initializer.
 
 @param controller Child controller to attach to the floating root controller.  Must conform to SCSAttachmentController.
 @return Initialized object
 @see SCSAttachmentController
 */
- (instancetype)initWithController:(UIViewController<SCSAttachmentController>*)controller NS_DESIGNATED_INITIALIZER;

/**
 Performs an animated update to hide or show the attachment; the default doesn't perform an animation.
 
 @param dismissed `YES` if the view should be hidden, otherwise `NO`
 @param animated  `YES` to animate the visibility change.
 @see dismissed
 */
- (void)setDismissed:(BOOL)dismissed animated:(BOOL)animated completion:(nullable void(^)(void))completion NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END

