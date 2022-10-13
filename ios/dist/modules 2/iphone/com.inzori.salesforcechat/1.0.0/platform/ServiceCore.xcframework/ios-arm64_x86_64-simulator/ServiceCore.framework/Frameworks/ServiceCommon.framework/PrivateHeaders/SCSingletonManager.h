//
//  SCSingletonManager.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/12/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCManagedSingleton;

/**
 This class is used to manage a set of child objects that can be used as singletons.  This allows their lifecycle to be managed from a common shared resource, yet can internally be used and referenced strongly, allowing implementations to decouple themselves from the singleton.
 */
@interface SCSingletonManager : NSObject

/**
 Returns a list of all managed singletons currently stored in the singleton manager.
 */
@property (nonatomic, copy, readonly) NSArray<SCSingletonManager*> *allManagedSingletons;

/**
 Retrieves the manager instance with the provided name.  If the singleton has not yet been created, it will be implicitly constructed for you.
 
 @param name Unique name the SCManagedSingleton instance indicates.
 @return Managed singleton for the provided name, or `nil` if none found.
 @see SCManagedSingleton
 */
- (nullable NSObject<SCManagedSingleton>*)managedSingletonWithName:(NSString*)name;

/**
 Manually sets a managed singleton for the provided name.
 
 @warning If the values are invalid, or the singleton doesn't correspond to the name supplied, an assertion will be thrown
 @param managedSingleton Singleton instance to set.
 @param name             Name for the corresponding singleton.
 @see SCManagedSingleton
 */
- (void)setManagedSingleton:(NSObject<SCManagedSingleton>*)managedSingleton withName:(NSString*)name;

@end

@interface SCSingletonManager (KeyedSubscript)

- (nullable NSObject<SCManagedSingleton>*)objectForKeyedSubscript:(NSString*)key;
- (void)setObject:(NSObject<SCManagedSingleton>*)obj forKeyedSubscript:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
