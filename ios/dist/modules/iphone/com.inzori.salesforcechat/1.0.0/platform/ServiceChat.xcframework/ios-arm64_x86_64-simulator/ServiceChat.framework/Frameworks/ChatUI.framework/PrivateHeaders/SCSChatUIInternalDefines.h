//
//  SCSChatInternalDefines.h
//  ChatUI
//
//  Created by Michael Nachbaur on 2/24/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <os/log.h>
#import <os/activity.h>

@import SalesforceCore.SalesforceCrypto.Private;
@import ServiceCore.ServiceCommon;
@import ServiceCore.ServiceCommon.Private;

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#ifndef SCChatLocalizedString
#undef SCChatLocalizedString
#endif

#ifdef safeBlock
#undef safeBlock
#endif

#ifdef safeReference
#undef safeReference
#endif

#ifdef executeAndDeleteBlock
#undef executeAndDeleteBlock
#endif

#define safeReference(value) value ?: [NSNull null]
#define safeReferenceWithString(value) value ?: @""

#define executeAndDeleteBlock(block, args...) safeBlock(block, args); \
block = nil

#pragma GCC diagnostic ignored "-Wvariadic-macros"
#define safeBlock(block, args...) if (block) { \
block(args); \
}

#define SCChatLocalizedString(key) [NSString overridableLocalizedStringForKey:key table:@"ChatUI" bundleIdentifier:@"com.salesforce.ServiceSDK.Chat"]

SC_EXTERN NSString * const SCSChatInterfaceManagerKey;

SC_EXTERN SFCLogger SCSChatUILogger;

typedef enum : NSUInteger {
    SCSChatEstimateStateEstimated,
    SCSChatEstimateStateUnknown,
    SCSChatEstimateStateExcessive,
} SCSChatEstimateState;

SC_EXTERN SCSChatEstimateState SCSChatEstimatedWaitState(NSTimeInterval minimumWaitTime, NSTimeInterval maximumWaitTime, NSInteger queuePosition, NSTimeInterval estimatedWaitTime);
SC_EXTERN NSString * SCSChatEstimatedWaitTimeString(NSTimeInterval minimumWaitTime, NSTimeInterval maximumWaitTime, NSTimeInterval estimatedWaitTime);

#define ChatUILogDefault(frmt, ...)  SFCLoggerLogDefault(SCSChatUILogger, frmt, ##__VA_ARGS__)
#define ChatUILogInfo(frmt, ...)     SFCLoggerLogInfo(SCSChatUILogger, frmt, ##__VA_ARGS__)
#define ChatUILogDebug(frmt, ...)    SFCLoggerLogDebug(SCSChatUILogger, frmt, ##__VA_ARGS__)
#define ChatUILogError(frmt, ...)    SFCLoggerLogError(SCSChatUILogger, frmt, ##__VA_ARGS__)
#define ChatUILogFault(frmt, ...)    SFCLoggerLogFault(SCSChatUILogger, frmt, ##__VA_ARGS__)
