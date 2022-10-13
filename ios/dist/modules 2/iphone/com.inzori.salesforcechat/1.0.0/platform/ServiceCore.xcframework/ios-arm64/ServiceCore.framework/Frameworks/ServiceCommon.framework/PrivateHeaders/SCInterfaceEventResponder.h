//
//  SCInterfaceEventResponder.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/24/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCSEvent;

NS_ASSUME_NONNULL_BEGIN

/**
 Protocol that an SCInterfaceStyle class can adopt to indicate it can respond to SCSEvent interface events.
 */
@protocol SCInterfaceEventResponder <NSObject>

/**
 Sends the given event to the receiver.
 
 @discussion
 If no interaction responder is available for the receiver, then the event will be silently ignored.
 
 @param event Event to send.
 @return `YES` if the event has been handled, otherwise `NO` to let the event pass to the next responder.
 */
- (BOOL)interactionReceivedWithEvent:(SCSEvent*)event;

@optional

/**
 Returns a view controller capable of handling the given event.
 
 May return `nil` if no view controller is relevant for the given event, in which case the system will fall back to using `interactionReceivedWithEvent:` directly.

 @param event Event being sent.
 @return View controller capable of handling the given event, or `nil` if no view controller is relevant.
 */
- (nullable __kindof UIViewController*)viewControllerForEvent:(SCSEvent*)event;

/**
 Controls whether or not events with the given name can be handled by the receiver.
 
 @param eventName Event name to check.
 
 @return `YES` if the receiver should be used to handle events with that name, otherwise return `NO` if the next responder should be asked.
 */
- (BOOL)supportsEventsWithName:(NSString*)eventName;

@end

NS_ASSUME_NONNULL_END
