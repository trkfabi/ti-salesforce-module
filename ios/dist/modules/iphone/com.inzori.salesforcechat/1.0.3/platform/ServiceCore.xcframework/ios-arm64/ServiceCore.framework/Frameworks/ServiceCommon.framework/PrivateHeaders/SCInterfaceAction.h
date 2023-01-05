//
//  SCInterfaceAction.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCSActionItem;

/**
 Protocol that an SCInterfaceStyle class can adopt to indicate it is capable of returning and presenting interface actions.
 */
@protocol SCInterfaceAction <NSObject>

/**
 Indicates the set of interface actions that are currently available for display.
 
 @return NSSet of interface names, or `nil` if no interface actions are available.
 */
- (nullable NSSet<NSString*>*)availableInterfaceActions;

/**
 Returns a view for an interface action indicated by the supplied action name.
 
 @param actionName Name for the action.
 
 @return Action item to display, or `nil` if this action is unavailable.
 */
- (nullable UIView<SCSActionItem>*)actionItemForInterfaceAction:(NSString*)actionName;

/**
 Returns the name of the event associated with the supplied action name.
 
 @param actionName Name for the action.
 
 @return Event name or `nil' if no event is associated with the supplied action name.
 */
- (nullable NSString*)eventNameForInterfaceAction:(NSString*)actionName;

@optional

/**
 Optional preferred sort order for this item, relative to other preferred sort indexes.
 
 @param actionName Action name.
 
 @return Numeric sort order.
 */
- (NSInteger)preferredSortIndexForInterfaceAction:(NSString*)actionName;

/**
 Allows interface styles to indicate when they would prefer the action container to be hidden for a given controller.
 
 Note that this is simply a preference on the part of the action subsystem, and the developer integrating the ServiceSDK may choose to override this decision, and allow the action bar to be presented anyway.

 @warning It is important that receivers of this message only return `YES` when you know for a _fact_ that the controller should not support the action container.

 @param controller Authoritative view controller being presented.
 @return `YES` if the action container should be hidden, or `NO` if either the controller shouldn't be hidden, or the controller is unknown to you.
 */
- (BOOL)prefersActionContainerHiddenForController:(UIViewController*)controller;

@end

NS_ASSUME_NONNULL_END
