//
//  SCCPrivateDefines.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-12-04.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef __SCCPrivateDefines_h__
#define __SCCPrivateDefines_h__

#ifndef SCS_EXTERN
#ifdef __cplusplus
#define SCS_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SCS_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#ifndef NS_STRING_ENUM
#define NS_STRING_ENUM
#endif

#ifndef SCS_STRING_ENUM
#ifdef NS_TYPED_EXTENSIBLE_ENUM
#define SCS_EXTENSIBLE_STRING_ENUM NS_TYPED_EXTENSIBLE_ENUM
#define SCS_STRING_ENUM NS_TYPED_ENUM
#else
#define SCS_EXTENSIBLE_STRING_ENUM NS_EXTENSIBLE_STRING_ENUM
#define SCS_STRING_ENUM NS_STRING_ENUM
#endif
#endif

// NOTE: These strings are not marked as `const` because their values need to be
//       calculated at runtime.  Just please don't overwrite them.
SCS_EXTERN NSString * SCSNavigationControllerWillShowViewControllerNotification;
SCS_EXTERN NSString * SCSNavigationControllerDidShowViewControllerNotification;
SCS_EXTERN NSString * SCSViewControllerShowDetailTargetDidChangeNotification;
SCS_EXTERN NSString * SCSNavigationControllerLastVisibleKey;
SCS_EXTERN NSString * SCSNavigationControllerNextVisibleKey;
SCS_EXTERN NSString * SCSNavigationControllerIsAnimatedKey;

/// Notifications
SCS_EXTERN NSString * const SCSViewControllerWillShowNotification;
SCS_EXTERN NSString * const SCSViewControllerDidShowNotification;
SCS_EXTERN NSString * const SCInterfaceStyleChangedNotification;
SCS_EXTERN NSString * const SCSActionItemDidShowNotification;
SCS_EXTERN NSString * const SCSActionItemDidHideNotification;
SCS_EXTERN NSString * const SCSServiceConfigurationChangedNotification;
SCS_EXTERN NSString * const SCSLoggingSessionDidEndNotification;

SCS_EXTERN NSString * const SCSViewControllerAnimatedKey;
SCS_EXTERN NSString * const SCSViewControllerTransitionKey;
SCS_EXTERN NSString * const SCSViewControllerLastControllerKey;
SCS_EXTERN NSString * const SCSViewControllerAuthoritativeContextControllerKey;
SCS_EXTERN NSString * const SCSViewControllerWindowKey;
SCS_EXTERN NSString * const SCSViewControllerOriginatingNotificationKey;

/**
 Notification sent when the appearance configuration is changed.
 
 The object included in the notification is the SCAppearanceConfiguration object.
 */
SCS_EXTERN NSString * const SCAppearanceConfigurationChangedNotification;

/**
 Notification sent when the appearance configuration is applied.  This may be dispatched multiple times if the appearance configuration changes.
 
 The object included in the notification is the SCAppearanceConfiguration object.
 */
SCS_EXTERN NSString * const SCAppearanceConfigurationAppliedNotification;

SCS_EXTERN NSString * const SCSActionButtonAttachment;

/// Interaction Events

// KnowledgeUI
SCS_EXTERN NSString * const SCUServiceEventExternalLink;
SCS_EXTERN NSString * const SCUServiceEventCategoryListItem;
SCS_EXTERN NSString * const SCUServiceEventArticleListItem;
SCS_EXTERN NSString * const SCUServiceEventArticleSmartLink;
SCS_EXTERN NSString * const SCUServiceEventSupportHomeShowMore;
SCS_EXTERN NSString * const SCUServiceEventArticleList;
SCS_EXTERN NSString * const SCUServiceEventShowSearch;
SCS_EXTERN NSString * const SCUServiceEventRelevantArticles;
SCS_EXTERN NSString * const SCUServiceEventArticlePreview;
SCS_EXTERN NSString * const SCUServiceEventArticlePreviewViewController;

// Case Interface
SCS_EXTERN NSString * const SCUServiceEventShowCaseInterface;

// CaseUI
SCS_EXTERN NSString * const SCUServiceEventShowCasePublisher;

// CaseList
SCS_EXTERN NSString * const SCUServiceEventShowCaseList;

// CaseDetail
SCS_EXTERN NSString * const SCUServiceEventShowCaseDetail;

// CaseDeflectionResult
SCS_EXTERN NSString * const SCUServiceEventShowRelevantArticlesSearchResult;

// Chat Interface
SCS_EXTERN NSString * const SCUServiceEventShowChatInterface;

SCS_EXTERN id SCUNibInstanceFromClass(Class callerClass);

typedef NS_ENUM(NSUInteger, SCAnimationType) {
    SCAnimationTypePresent,
    SCAnimationTypeDismiss,
};

SCS_EXTERN NSString * const SFCMockNetworkInstanceURL;

typedef dispatch_queue_t sc_dispatch_recursive_queue_t;
SCS_EXTERN void sc_dispatch_set_recursive_queue(const void * const key, sc_dispatch_recursive_queue_t queue);
SCS_EXTERN void sc_dispatch_sync_recursive(const void * const key, sc_dispatch_recursive_queue_t queue, dispatch_block_t block);

SCS_EXTERN CGSize const SCDefaultSpinnerSize;
SCS_EXTERN CGSize const SCSmallSpinnerSize;
SCS_EXTERN NSString * SCSRandomString(NSUInteger length);

#ifndef SCServiceType
typedef NSString * SCServiceType SCS_STRING_ENUM;
#endif

SCS_EXTERN NSSet<SCServiceType> * const SCAvailableServiceTypes(void);

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"
#define executeAndDeleteBlock(block, args...) safeBlock(block, args); \
block = nil

#define safeBlock(block, args...) if (block) { \
    block(args); \
}
#pragma GCC diagnostic pop

#endif
