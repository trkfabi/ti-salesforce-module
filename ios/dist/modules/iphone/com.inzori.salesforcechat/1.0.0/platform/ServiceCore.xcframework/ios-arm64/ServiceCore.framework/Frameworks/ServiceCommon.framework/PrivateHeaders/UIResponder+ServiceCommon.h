//
//  UIResponder+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/23/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCSPresentationWindow;
@interface UIResponder (ServiceCommon)

/**
 Returns the current first responder within this view.
 
 @return Current first responder, or `nil` if nothing has the responder chain open.
 */
- (nullable UIResponder *)findFirstResponder;

/**
 Returns the view controller most directly associated with the current responder.

 @return View controller associated with this responder, or `nil` if none was found.
 */
- (nullable UIViewController*)nextViewController;

/**
 Convenience method that tries through several different mechanisms to identify the presentation window, if this responder is in any way associated with a presentation window.
 */
- (nullable SCSPresentationWindow*)presentationWindow;

@end

NS_ASSUME_NONNULL_END
