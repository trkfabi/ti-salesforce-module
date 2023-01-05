//
//  UIViewController+SCSAttachment.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 10/30/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCSAttachment;

/** Category that adds some convenience methods for view controllers that interact with SCSAttachment instances
 */
@interface UIViewController (SCSAttachment)

/** Convenience reference to a view controller's parent attachment instance, if it is currently assigned to one.
 */
@property (nonatomic, weak, readonly, nullable) SCSAttachment *parentAttachment;

/**
 Returns the child controller capable of making UI and presentation decisions, typically from within UISplitViewController or UINavigationController containers.
 
 The default behavior will be to return the topmost controller in those circumstances, traversing past presented view controllers.  This method maybe overridden if a different controller should be used.
 
 @note For most uses it is unlikely this method needs to be overridden, except when custom container view controllers are used.  The default implementation does not traverse child view controllers except in the cases of UISplitViewController and UINavigationControllers.
 
 @return UIViewController capable of making UI presentation decisions, or `nil` if no controller is applicable.
 */
- (nullable __kindof UIViewController*)authoritativeController;

@end
