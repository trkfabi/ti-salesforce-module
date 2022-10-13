//
//  SCSAccountIdentityLoader.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 4/5/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SCCPrivateDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class SCSAuthenticationSettings;

/**
 Asynchronous account identity loading class that implements all the logic necessary to pre-fetch and validate a user account.
 */
@interface SCSAccountIdentityLoader : NSObject

@property (nonatomic, weak, readonly) SCSAuthenticationSettings *settings;

- (instancetype)initWithAuthenticationSettings:(SCSAuthenticationSettings*)settings;

- (void)addCompletionBlock:(void(^)(dispatch_block_t finishedBlock))completion;
- (void)loadIdentityInformationWithCompletionBlock:(nullable dispatch_block_t)completion;

@end

NS_ASSUME_NONNULL_END
