//
//  SCUWeakObjectContainer.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 9/17/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Container class that holds a weak reference to another object.  This is useful for encapsulating a weak reference to another object while still utilizing objc_setAssociatedObject.  The Objective-C associated object methods only retain or assign values, and weak references don't auto-zero their pointers.  Using this approach allows us to retain a reference to the object container, while allowing the weak object to go away.
 */
@interface SCWeakObjectContainer : NSObject

@property (nonatomic, readonly, weak) id object;

- (instancetype)initWithObject:(id)object NS_DESIGNATED_INITIALIZER;

@end
