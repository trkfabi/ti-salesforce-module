//
//  DelegateRecorder.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/26/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#ifdef DEBUG
#import <objc/runtime.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Object that represents an individual call to the delegate recorder.
 */
@interface SCSDelegateCall : NSObject

/**
 Timestamp when the call was made.
 */
@property (nonatomic, readonly) NSTimeInterval timestamp;

/**
 Selector used when invoking the call.
 */
@property (nonatomic, readonly) SEL selector;

/**
 Array of arguments supplied to the delegate.  Primitive values are wrapped in their appropriate object types (NSNumber, NSValue, etc), and `nil` is represented as `NSNull` instances.
 */
@property (nonatomic, strong, readonly) NSArray *arguments;

/**
 Constructs a call with an NSInvocation instance.

 @param invocation Invocation to use.
 @return Initialized call object.
 */
- (instancetype)initWithInvocation:(NSInvocation*)invocation NS_DESIGNATED_INITIALIZER;

/**
 Constructs a call using the supplied selector and nil-terminated arguments.

 @param selector Selector.
 @param arguments Arguments.
 @return Initialized call object.
 */
- (instancetype)initWithSelector:(SEL)selector arguments:(nullable id)arguments, ... NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

/**
 Testing class for recording the results of delegate calls to an object.
 */
@interface SCSDelegateRecorder : NSObject

/**
 Array of `SCSDelegateCall` instances representing the ordered list of method invocations against this recorder.
 */
@property (nonatomic, strong, readonly) NSArray<SCSDelegateCall*> *calls;

/**
 The protocol this delegate recorder will emulate.  If not specified, this class will record all calls.
 */
@property (nullable, nonatomic, assign, readonly) Protocol *delegateProtocol;

/**
 Indicates whether or not all optional selectors should be implemented.
 */
@property (nonatomic, assign, getter=shouldImplementAllOptionalSelectors) BOOL implementAllOptionalSelectors;

/**
 Initializer for creating an instance of SCSDelegateRecorder to behave like an instance of the given protocol.

 @param delegateProtocol Protocol to conform to
 @return Initialized delegate recorder.
 */
- (instancetype)initWithProtocol:(Protocol*)delegateProtocol;

/**
 Indicates whether or not the given optional protocol selector is implemented.
 
 Optional protocol methods aren't implemented by default, unless either a return block is associated with it, or if it is overridden using setOptionalSelector:implemented:.

 @param selector Selector
 @return `YES` if the method is implemented.  The default is `NO`.
 */
- (BOOL)isOptionalSelectorImplemented:(SEL)selector;

/**
 Overrides whether or not an optional protocol selector should be implemented.

 @param selector Selector to implement
 @param implemented `YES` if the delegate recorder should implement this method.
 */
- (void)setOptionalSelector:(SEL)selector implemented:(BOOL)implemented;

/**
 Method used to record an instance of SCSDelegateCall.

 @param call Call to record.
 */
- (void)recordCall:(SCSDelegateCall*)call;

/**
 Resets the array of calls to an initial state.
 */
- (void)reset;

/**
 Associates a block that can be fired when an invocation is fired for the given selector.  This can allow a return value, for example, to be returned to a selector.

 @param selector Selector to associate the block with.
 @param block Block to be called when an invocation is made for the given selector.
 */
- (void)invocationForSelector:(SEL)selector block:(void(^)(SCSDelegateCall *call, NSInvocation *invocation))block;

@end

NS_ASSUME_NONNULL_END
#endif
