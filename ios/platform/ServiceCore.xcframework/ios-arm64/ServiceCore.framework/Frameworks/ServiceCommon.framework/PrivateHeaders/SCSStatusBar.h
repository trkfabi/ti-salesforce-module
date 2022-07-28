//
//  SCSStatusBar.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/22/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Protocol that view controllers can conform to, to indicate they may or may not want to be in charge of overriding the status bar appearance when presented.
 */
@protocol SCSStatusBar <NSObject>

@required

/**
 Indicates whether or not this receiver wants control over the status bar.

 @return `YES` if the receiver wants to control the statusbar, otherwise `NO` to pass through to the lower-level window.
 */
- (BOOL)wantsControlOverStatusBar;

@optional

/**
 Optional controller for exposing the specific child controller that should be responsible for controlling the status bar.

 @return Child controller that should be used for controlling the statusbar.
 */
- (nullable UIViewController<SCSStatusBar>*)childViewControllerControllingStatusBar;

@end

NS_ASSUME_NONNULL_END
