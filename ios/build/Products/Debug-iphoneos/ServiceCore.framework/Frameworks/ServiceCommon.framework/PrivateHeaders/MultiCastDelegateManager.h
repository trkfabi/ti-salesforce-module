/*
 * Copyright © salesforce.com, inc. 2015
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of the {organization} nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MultiCastDelegateWrapper: NSObject<NSCopying>

@property (nonatomic, weak, readonly) id delegate;

@property (nonatomic, weak, readonly) dispatch_queue_t queue;

@end

@protocol MulticastDelegateListener <NSObject>

/**
 *  Register the delegates required for the session.
 *
 */
- (void)registerDelegates;

/**
 *  Remove the delegates required for the session.
 *
 */
- (void)removeDelegates;

@end

@interface MultiCastDelegateManager : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<MultiCastDelegateWrapper *> *delegates;

/**
 *  Returns an instance of the MultiCastDelegateManager
 *
 *  @return a new MultiCastDelegateManager
 */
+ (instancetype)manager;

///---------------------------------
/// @name Delegate Handlers
///---------------------------------

/**
 *  Add an instance of an NSObject to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to add.
 */
- (void)add:(id)delegate;

/**
 *  Add an instance of an NSObject to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to add.
 *  @param queue the dispatch_queue_t to which all events will be dispatchted to asynchronously.
 */
- (void)add:(id)delegate queue:(nullable dispatch_queue_t)queue;

/**
 *  Remove an instance of an NSObject from the list of delegates to notify.
 *
 *  @param delegate NSObject instance to remove.
 */
- (void)remove:(id)delegate;

/**
 *  Remove all delegates.
 */
- (void)removeAll;

///---------------------------------
/// @name Delegate Handlers
///---------------------------------

/**
 *  Registers an event with the delegate manager. This holds a map of named keys to selectors.
 *
 *  @param eventId  The name of the event to register.
 *  @param protocol The Protocol which is used to derive the method signature of the method.
 *  @param selector The selector to invoke against the current list of delegates.
 */
- (void)registerEvent:(NSInteger)eventId protocol:(Protocol *)protocol selector:(SEL)selector;

/**
 *  Deregisters an event with the delegate manager.
 *
 *  @param eventId The name id the event to derigester.
 */
- (void)deregisterEvent:(NSInteger)eventId;

/**
 *  The given name is used to look up the selector to invoke against the current list of delegates.
 *  If a matching selector is found it is fired against all delegates which conform to the method signature.
 *
 *  @param eventId The id of the event to attempt to send accross all delegates.
 */
- (void)sendEvent:(NSInteger)eventId;

/**
 *  The given name is used to look up the selector to invoke against the current list of delegates.
 *  If a matching selector is found it is fired against all delegates which conform to the method signature.
 *
 *  @warning this requires a nil terminated list of arguments.
 *
 *  @param eventId The id of the event to attempt to send accross all delegates.
 *  @param first   The first of a nil terminated variadic list of a NSObjects.
 */
- (void)sendEvent:(NSInteger)eventId args:(nullable void *)first, ...;
@end


#define DEFINE_DELEGATE_WRAPPERS(protocol, delegateManager)                 \
- (void)addDelegate:(id<protocol>)delegate {                                \
    [[self delegateManager] add:delegate];                                  \
}                                                                           \
                                                                            \
- (void)addDelegate:(id<protocol>)delegate queue:(dispatch_queue_t)queue {  \
    [[self delegateManager] add:delegate queue:queue];                      \
}                                                                           \
                                                                            \
- (void)removeDelegate:(id<protocol>)delegate {                             \
    [[self delegateManager] remove:delegate];                               \
}

NS_ASSUME_NONNULL_END
