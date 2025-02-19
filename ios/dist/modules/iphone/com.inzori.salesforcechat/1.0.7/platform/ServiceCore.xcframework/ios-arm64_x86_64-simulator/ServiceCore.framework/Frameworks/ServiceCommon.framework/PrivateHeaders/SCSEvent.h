//
//  SCSEvent.h
//  CoreSalesforce
//
//  Created by Michael Nachbaur on 3/11/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Class used to represent events which are influenced by a user, or that may influence a user interface.
 
 @discussion
 The properties on these objects are readonly and are intended for informational purposes.  New intents
 of these events can be created by assigning different `name` values that have special meanings.  For example,
 SalesforceChatter uses these to describe user actions performed on the feed, such as taping a "Like" button or
 tapping on a feed item itself.  The result of such an action is determined by the consumer of these events.
 
 @see SCInterfaceEventResponder
 */
@interface SCSEvent : NSObject <NSCopying, NSSecureCoding>

/**
 Timestamp for when this event was generated.
 */
@property (nonatomic, readonly) NSTimeInterval timestamp;

/**
 Name describing this event.
 
 @discussion
 It is advisable that `static const` values be used for these names to allow for convenient value checking.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 A context object describing the event.
 */
@property (nonatomic, strong, readonly) id object;

/**
 The sender for this event, either a UI view or controller of some sort.
 */
@property (nonatomic, strong, readonly) id sender;

/**
 A dictionary of arbitrary values that provide additional context to the event.
 */
@property (nonatomic, strong, readonly) NSDictionary *userInfo;

/**
 Designated initializer.

 @param name     Name for the event.
 @param object   Context object.
 @param sender   Sender object.
 @param userInfo User info dictionary.

 @return Initialized event.
 */
- (instancetype)initWithName:(NSString *)name object:(id)object sender:(id)sender userInfo:(NSDictionary *)userInfo NS_DESIGNATED_INITIALIZER;

@end

@interface SCSEvent (SCSEventCreation)

/**
 Creates a new event with just a name and object.

 @param name     Name for the event.
 @param object   Context object.

 @return Initialized event.
 */
+ (instancetype)eventWithName:(NSString *)name object:(id)object;

/**
 Creates a new event with a name, object and sender.

 @param name     Name for the event.
 @param object   Context object.
 @param sender   Sender object.

 @return Initialized event.
 */
+ (instancetype)eventWithName:(NSString *)name object:(id)object sender:(id)sender;

/**
 Creates a new event with a name, object, sender and userInfo dictionary.

 @param name     Name for the event.
 @param object   Context object.
 @param sender   Sender object.
 @param userInfo User info dictionary.

 @return Initialized event.
 */
+ (instancetype)eventWithName:(NSString *)name object:(id)object sender:(id)sender userInfo:(NSDictionary *)userInfo;

@end
