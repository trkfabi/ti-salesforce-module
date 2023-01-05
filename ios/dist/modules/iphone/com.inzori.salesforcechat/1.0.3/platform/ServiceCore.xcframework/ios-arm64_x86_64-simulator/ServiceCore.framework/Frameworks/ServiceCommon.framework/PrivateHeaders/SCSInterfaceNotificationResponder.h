//
//  SCSInterfaceNotificationResponder.h
//  ServiceCommon
//
//  Created by Amit Gosar on 5/2/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Protocol that an SCInterfaceStyle class can adopt to indicate it can respond to SCSNotifications.
 */
@protocol SCSInterfaceNotificationResponder <NSObject>

/**
 Implement this method to prefetch data or notify an observer when a notifiation is received.
 This method should return YES, if it was successul in perforing its task.
 */
- (BOOL)didReceiveNotification:(SCSNotification*)notification;

/**
 Implement this method to navigate to a viewController of choice based on information in the notification. 
 This method should return YES if it was sucessful in navigating to a viewController.
 */
- (BOOL)showInterfaceForNotification:(SCSNotification*)notification;

@end
