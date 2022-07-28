//
//  SSCAppearance.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 10/28/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCPrivateDefines.h"

@class SCInterfaceRouter;

/**
 Abstract protocol defining the centralized way the application interface is constructed and managed.
 
 An interface style is identified by a common name, and represents a set of classes that are responsible for the various events and logic to provide an interface's unique style.  This is different from appearance, or branding, in that interface styles are intended to be used to declare how a UI's navigation flows, how controllers are presented visually, and how transition or presentation controllers are assigned.
 */
@protocol SCInterfaceStyle <NSObject>

@required

/**
 Designated initializer for classes conforming to SCInterfaceStyle.
 @param router The parent router instance that has constructed the receiver.
 @param style  String style name to initialize the interface with.
 */
- (instancetype)initWithRouter:(SCInterfaceRouter*)router interfaceStyle:(NSString*)style;

@optional

/**
 If the receiver is capable of supporting multiple interface styles, it may be asked at runtime to adopt a new style.  If the receiver can change to the supplied style, it should update the value it returns from the `style` property, and should return `YES`.
 
 There may be instances where a given interface handler class can only handle one interface style.  In that event, it should either not implement this method, or should return `NO` when it is asked to adopt a style it doesn't support, in which case a new handler will be constructed in its place.
 @param style The new style to adopt.
 @return `YES` if this interface style instance has successfully adopted the new interface, or `NO` if this instance must be replaced.
 */
- (BOOL)adoptInterfaceStyle:(NSString*)style;

@end
