/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import "SCSLogger.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SCSLiveAgentLoggerSDK) {
    SCSLiveAgentLoggerSDKKnowledge,
    SCSLiveAgentLoggerSDKCase,
    SCSLiveAgentLoggerSDKChat,
    SCSLiveAgentLoggerSDKSOS,
    SCSLiveAgentLoggerUnknown,
};

extern NSString * const kSCSLiveAgentLogDateFormatter;

extern NSString * const kSCSResultField;
extern NSString * const kSCSPacketLossRatioField;
extern NSString * const kSCSBandwidthField;
extern NSString * const kSCSTestTypeField;
extern NSString * const kSCSOpenTokNetworkTestValue;
extern NSString * const kSCSStatusField;

extern NSString * const kSCSOrientationField;
extern NSString * const kSCSCallStateField;
extern NSString * const kSCSDescriptionField;
extern NSString * const kSCSRecording;
extern NSString * const kSCSDeviceField;
extern NSString * const kSCSApplicationField;
extern NSString * const kSCSSDKField;
extern NSString * const kSCSOSField;
extern NSString * const kSCSSessionIdField;
extern NSString * const kSCSDeploymentIdField;

extern NSString * const kSCSServiceValue;
extern NSString * const kSCSPlatformValue;
extern NSString * const kSCSLiveAgentPod;
extern NSString * const kSCSDefaultLiveAgentAPIVersion;

@class SCSLALoggingInfo;
@interface SCSLiveAgentLogger : NSObject

@property (retain, nonatomic) NSString *loggingId;
@property (strong, nonatomic) SCSLALoggingInfo *logginginfo;

+ (instancetype)sharedSession;
- (void)initializeLoggingSession:(SCSLiveAgentLoggerSDK)sdk completion:(nullable void (^)(BOOL ready))completion;
- (void)endLoggingSession:(SCSLiveAgentLoggerSDK)sdk;
- (void)cleanUpLoggingSession;
- (void)flushLogsWithCompletion:(nullable void(^)(NSError *error))completion;

- (void)logObject:(NSArray *)object forBatchType:(NSString *)type;

@end
NS_ASSUME_NONNULL_END
