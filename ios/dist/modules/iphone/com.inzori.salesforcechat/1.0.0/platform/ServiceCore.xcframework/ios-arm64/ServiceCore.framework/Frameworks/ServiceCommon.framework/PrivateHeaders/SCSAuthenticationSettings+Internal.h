//
//  SCSAuthenticationSettings+Internal.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-12-05.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class SFCCredential, SFCSalesforceOAuth2Credential, SFCSalesforceUserIdentity, SCSAccountIdentityLoader;
@interface SCSAuthenticationSettings ()

@property (nonatomic, strong, readonly) SFCCredential *credential;
@property (nonatomic, copy, readonly) NSString *loggingOrganizationId;
@property (nullable, nonatomic, strong, readonly) NSString *userId;
@property (nullable, nonatomic, strong, readonly) NSString *organizationId;
@property (nullable, nonatomic, strong, readonly) NSURL *communityUrl;
@property (nullable, nonatomic, strong, readonly) NSString *communityId;
@property (nullable, nonatomic, strong, readonly) SCSAccountIdentityLoader *identityLoader;

@property (nullable, nonatomic, copy, readonly) SFCSalesforceOAuth2Credential *salesforceOAuthCredential;
@property (nullable, nonatomic, copy, readonly) SFCSalesforceUserIdentity *salesforceUserIdentity;

- (nullable instancetype)initWithCredential:(SFCCredential*)credential NS_DESIGNATED_INITIALIZER;

- (void)loadIdentityInformation:(dispatch_block_t)completion;

@end

NS_ASSUME_NONNULL_END
