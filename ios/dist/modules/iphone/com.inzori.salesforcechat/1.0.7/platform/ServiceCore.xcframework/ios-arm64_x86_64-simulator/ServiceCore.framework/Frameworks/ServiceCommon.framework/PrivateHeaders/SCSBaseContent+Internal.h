//
//  SCSBaseContent+Internal.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSBaseContent.h"

extern const void * const kSCBaseContentRecursiveKey;

@interface SCSBaseContent () {
@protected
    BOOL _deferDelegateUpdateCalls;
}

@property (atomic, getter=isOnUnderlyingQueue, readonly) BOOL onUnderlyingQueue;

- (void)sendDeferredBeginUpdatesIfNeeded;

- (void)delegate_contentWillLoadContent;
- (void)delegate_contentDidLoadContent;
- (void)delegate_contentDidReceiveError:(NSError*)error;
- (void)delegate_contentWillBeginUpdates;
- (void)delegate_contentDidEndUpdates;
- (void)delegate_contentBecameInvalidWithError:(NSError*)error;

@end
