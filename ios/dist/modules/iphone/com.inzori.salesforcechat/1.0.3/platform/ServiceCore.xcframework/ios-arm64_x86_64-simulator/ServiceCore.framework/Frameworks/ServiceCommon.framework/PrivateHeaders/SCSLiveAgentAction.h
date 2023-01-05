//
//  SCSLiveAgentAction.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2018-01-26.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

@import SalesforceCore.SalesforceNetwork;

#import "SCSLiveAgentHandoverDelegate.h"

NS_ASSUME_NONNULL_BEGIN

#undef DEBUG_LIVE_AGENT_BODY_CONTENT

@interface SCSLiveAgentAction : SFCAction <NSCopying>

@property (null_resettable, nonatomic, copy) NSString *apiVersion;
@property (nullable, nonatomic, copy) NSString *sessionId;
@property (nullable, nonatomic, copy) NSString *sessionKey;
@property (nullable, nonatomic, copy) NSString *affinityToken;
@property (nonatomic, assign) NSUInteger sequence;
@property (nonatomic, assign) unsigned long offset;
@property (nonatomic, readwrite, weak) id<SCSLiveAgentHandoverDelegate> handoverDelegate;

+ (instancetype)actionToEstablishSessionWithPod:(NSString*)pod
                                         offset:(unsigned long)offset
                              withResponseBlock:(nullable SFCActionResponseBlock)block;

+ (instancetype)actionToEndSessionWithPod:(NSString*)pod
                                   offset:(unsigned long)offset
                            affinityToken:(NSString*)affinityToken
                               sessionKey:(NSString*)sessionKey
                        withResponseBlock:(nullable SFCActionResponseBlock)block;

+ (instancetype)actionToPollLiveAgentWithPod:(NSString*)pod
                                      offset:(unsigned long)offset
                               affinityToken:(NSString*)affinityToken
                                  sessionKey:(NSString*)sessionKey
                           withResponseBlock:(nullable SFCActionResponseBlock)block;

+ (instancetype)actionToSendBatchDataWithPod:(NSString*)pod
                                      offset:(unsigned long)offset
                               affinityToken:(NSString*)affinityToken
                                  sessionKey:(NSString*)sessionKey
                               batchedEvents:(NSDictionary *)batchedEvents
                           withResponseBlock:(nullable SFCActionResponseBlock)responseBlock;

- (instancetype)initWithPod:(NSString *)pod
                     offset:(unsigned long)offset
          withResponseBlock:(nullable SFCActionResponseBlock)responseBlock;

@end

NS_ASSUME_NONNULL_END

