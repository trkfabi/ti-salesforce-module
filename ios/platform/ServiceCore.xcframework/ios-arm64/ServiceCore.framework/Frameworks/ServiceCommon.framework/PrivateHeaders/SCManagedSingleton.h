//
//  SCManagedSingleton.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/12/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SCSAuthenticationSettings, SCSingletonManager, SCAppearanceConfiguration, SCSServiceConfiguration, SCFloatingRootWindow, SCInterfaceRouter;

/**
 This protocol defines classes that should be managed as if it were a singleton, within a shared instance.
 
 The SCSingletonManager class functions as an abstract container to create instances of managed singletons on-demand.  It allows each of these classes to be stored in a common container so that access to these resources can be centralized through a common manager.
 
 The goal of this protocol is to allow public client access to these resources as a singleton, but private implementations can still treat the classes as retained resources, without the inherent risks involved in dealing with singletons.
 */
@protocol SCManagedSingleton <NSObject>

@required

/**
 Required method that indicates a unique name to identify this manager by.  This string is later used to access your service within the manager using its [SCSingletonManager managerWithName:] method.
 @param manager The manager instance this service is being initialized within.
 @return Returns the name for the receiver, relative to the given manager.
 @see SCSingletonManager
 */
+ (NSString*)nameForServiceInManager:(SCSingletonManager*)manager;

@optional

/**
 Optional method controlling when the receiver's service is initialized.  If this method is not implemented, or it returns `NO`, this service will be lazily constructed.  If this method returns `YES`, the receiver service will be constructed immediately when the parent manager is created.
 */
+ (BOOL)requiresImmediateInitialization;

/**
 If the managed singleton needs to access appearance configuration information, it can implement this method to have
 the appearance configuration object assigned automatically when the singleton is created, as well as when the appearance configuration changes.
 @param appearanceConfiguration The new appearance configuration object.
 @see SCAppearanceConfiguration
 */
- (void)setAppearanceConfiguration:(SCAppearanceConfiguration*)appearanceConfiguration;

/**
 If the managed singleton needs to access service configuration information, it can implement this method to have
 the SCSServiceConfiguration object assigned automatically when the singleton is created, as well as when the service configuration changes.
 @param serviceConfiguration The new service configuration object.
 @see SCSServiceConfiguration
 */
- (void)setServiceConfiguration:(SCSServiceConfiguration*)serviceConfiguration;

/**
 If the managed singleton needs to access the interface style factory, it can implement this method to have it automatically populated when the singleton is created, as well as when the interface factory changes.
 @param interfaceRouter The interface style router instance.
 @see SCInterfaceRouter
 */
- (void)setInterfaceRouter:(SCInterfaceRouter*)interfaceRouter;

- (void)authenticationSettingsChanged:(nullable SCSAuthenticationSettings*)settings forServiceType:(SCServiceType)serviceType;

/**
 If the managed singleton needs to be made aware of user accounts, and changes to user accounts, implementing this method will allow it to automatically be populated.
 
 @param account User account.
 */
// TODO: Remove when this facility is handled in the new SDK
//- (void)setAccount:(SFUserAccount *)account;

/**
 If the managed singleton needs to be made aware of user account logouts, implenting this will allow it to be notified immediately before the user account is logged out.
 
 @param account User account that is about to be logged out.
 */
//- (void)userAccountWillLogOut:(nullable SFUserAccount*)account;

@end

NS_ASSUME_NONNULL_END
