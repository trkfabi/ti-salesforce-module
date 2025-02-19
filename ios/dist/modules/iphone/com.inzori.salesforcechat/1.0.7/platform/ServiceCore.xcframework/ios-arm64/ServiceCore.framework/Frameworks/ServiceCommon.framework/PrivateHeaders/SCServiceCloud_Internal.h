//
//  SCServiceCloud_Internal.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/12/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

// IMPORTANT: Do not `#import "SCServiceCloud.h"` in this file.  This causes Private/Public header
//            import problems when consuming this in other SDKs.  Instead, every place where
//            SCServiceCloud_Internal.h is imported, you must first import SCServiceCloud.h before.

NS_ASSUME_NONNULL_BEGIN

@class SCSingletonManager, SCInterfaceRouter, SCSAttachmentWindow, SFCContainer;

/**
 ## Subproject Extensions
 
 This class is intended to be extended by sub-projects through the use of categories.  Each subproject can add whichever properties or methods to SCServiceCloud as needed for their various libraries.  Since these properties and methods will be exposed to developers consuming this SDK, it's important to ensure APIs that are exposed are clean and consistent with the rest of the project.
 
 The recommended approach for project-specific configurations would be to expose a sub-project's `SCManagedSingleton` public header to SCServiceCloud via a separate property.  For example, the Knowledge-specific user options are exposed through a property called `knowledge` on SCServiceCloud.
 
        - (SCKnowledgeInterface *)knowledge {
            SCKnowledgeInterface *result = nil;
            NSObject\<SCManagedSingleton\> *managedSingleton = self.manager[SCKnowledgeInterfaceManagerKey];
            if ([managedSingleton isKindOfClass:[SCKnowledgeInterface class]]) {
                result = (SCKnowledgeInterface*)managedSingleton;
            }
            return result;
        }

 Another option for settings that may be more universal than that would be to add the properties or methods directly to SCServiceCloud.
 */
@interface SCServiceCloud ()

/**
 Singleton manager for storing strong references, and initializing singleton instances, for various components that are included as part of Service Cloud Kit.
 
 @see SCSingletonManager
 @see SCManagedSingleton
 */
@property (atomic, strong, readonly) SCSingletonManager *manager;

/**
 Current interface style instance to manage navigation events and presentation controller configuration.
 @see SCInterfaceRouter
 */
@property (atomic, strong, readonly) SCInterfaceRouter *interfaceRouter;

@property (null_resettable, nonatomic, weak, readonly) SFCContainer *container;

/**
 Asks the Delegate whether the calling service should be authenticated.
 You can assign the authenticated user account property to the sdk from this method.
 
 @note If `YES` is returned, the caller should take steps to ensure the user is informed that some sort of authentication is occurring, such as activity indicators or the like. 

 @param service The name of the service (Knowledge or Case).
 @param completion The block to be invoked when the response is received.
 @return `YES` if the service should be authenticated; 'NO' to proceed as a guest user.
 */
- (BOOL)shouldAuthenticateServiceType:(SCServiceType)service completion:(void(^)(SCSAuthenticationSettings * _Nullable settings))completion;

- (BOOL)shouldReauthenticateWithError:(NSError*)error forServiceType:(SCServiceType)service;

@end

@interface SCServiceCloud (CacheManagementPrivate)

/**
 The duration (specified in seconds) after which the core data is deleted. The default value is 24 hours.
 */
@property (nonatomic, assign) NSTimeInterval cacheRetentionTimeInterval;

@property (nonatomic, getter=shouldClearCacheOnAppStartup) BOOL clearCacheOnAppStartup;

@end

@interface SCServiceCloud (Attachments)

@property (nonatomic, strong, readonly) SCSAttachmentWindow *attachmentWindow;
@property (nonatomic, assign, readonly) BOOL hasAttachmentWindow;

- (void)setUpAttachmentHandling;
- (void)tearDownAttachmentHandling;

@end

NS_ASSUME_NONNULL_END
