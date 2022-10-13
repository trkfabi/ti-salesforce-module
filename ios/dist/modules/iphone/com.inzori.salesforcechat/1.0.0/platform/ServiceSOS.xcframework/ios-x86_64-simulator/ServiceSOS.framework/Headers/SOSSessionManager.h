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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class SOSScreenAnnotations;
@class SOSScreenSharing;
@class SOSSessionManager;
@class SOSOptions;
@class SOSMasking;
@class SOSAgentAvailability;
@class SOSNetworkReporter;

/**
 *  SOSCompletionHandler block definition
 *
 *  @param error The error that occurred in the block.
 *  @param sos   The instance of the `SOSSessionManager` the block is acting on.
 */
typedef void (^SOSCompletionHandler)(NSError *error, SOSSessionManager *sos);

/**
 * Full list of Session states the SOS framework can exhibit.
 *
 *  @see `SOSDelegate`
 *  @see `SOSSessionManager`
 */
typedef NS_ENUM(NSInteger, SOSSessionState) {
    /**
     *  No active session. There will be no outgoing/incoming SOS traffic.
     */
    SOSSessionStateInactive = 0,

    /**
     *  Session is doing pre-initialization configuration steps, such as network testing.
     */
    SOSSessionStateConfiguring = 1,

    /**
     *  Session state is initializing and preparing to connect.
     */
    SOSSessionStateInitializing = 2,

    /**
     *  Session is attempting a connection to a live agent.
     */
    SOSSessionStateConnecting = 3,

    /**
     *  Live agent has connected and the session is fully active.
     */
    SOSSessionStateActive = 4
};

/**
 *  Reasons provided to the `-[SOSDelegate sos:didStopWithReason:error:]` event.
 *
 *  @see `SOSDelegate`
 *  @see `SOSSessionManager`
 */
typedef NS_ENUM(NSInteger, SOSStopReason) {
    /**
     *  User disconnected the session.
     */
    SOSStopReasonUserDisconnected = 1,

    /**
     *  Agent disconnected the session.
     */
    SOSStopReasonAgentDisconnected = 2,

    /**
     *  Session ended due to an error.
     */
    SOSStopReasonSessionError = 3,

    /**
     *  Session was ended in response to the application attempting to terminate.
     */
    SOSStopReasonExternalUnknown = 4,

    /**
     *  Session failed due to timeout.
     */
    SOSStopReasonSessionTimeout = 5,

    /**
     *  Session ended because the app was backgrounded before the connection completed.
     */
    SOSStopReasonBackgroundedBeforeConnected = 6,

    /**
     *  Reset the cause for session disconnection.
     */
    SOSStopReasonInvalid = -1,
};

/**
 *  The `SOSDelegate` protocol provides information about the SOS session.
 *
 *  @see `SOSSessionManager`
 */
@protocol SOSDelegate<NSObject>
@optional

/**
 *  Tells the delegate that an SOS session has started.
 *
 *  This method is executed once the SOS Session has begun to initialize a connection.
 *
 *  @param sos `SOSSessionManager` instance that invoked the delegate method.
 *  @see `SOSSessionManager`
 */
- (void)sosDidStart:(SOSSessionManager *)sos;

/**
 *  Tells the delegate that an SOS session is stopping.
 *
 *  This event is invoked when the session is entering its cleanup phase.
 *
 *  @param sos    `SOSSessionManager` instance that invoked the delegate method.
 *  @param reason `SOSStopReason` enum for why the session ended.
 *  @param error  `NSError` instance returned if the session ended as the result of an error.
 *                Compare the error code to `SOSErrorCode` for details about the error.
 *                Error is `nil` if the session ended cleanly.
 *  @see `SOSSessionManager`
 *  @see `SOSStopReason`
 *  @see `SOSErrorCode`
 */
- (void)sos:(SOSSessionManager *)sos didStopWithReason:(SOSStopReason)reason error:(NSError *)error;

/**
 *  Tells the delegate that an attempt is being made to reconnect to an SOS session.
 *
 *  This is executed if the SOS session needs to reconnect.
 *
 *  @param sos `SOSSessionManager` instance that invoked the delegate method.
 *  @see `SOSSessionManager`
 */
- (void)sosWillReconnect:(SOSSessionManager *)sos;

/**
 *  Calls the delegate when the SOS session has connected. The session is now fully active.
 *
 *  @param sos `SOSSessionManager` instance that invoked the delegate method.
 *  @see `SOSSessionManager`
 */
- (void)sosDidConnect:(SOSSessionManager *)sos;

/**
 *  Calls the delegate when the SOS session has been created.
 *
 *  @param sos `SOSSessionManager` instance that invoked the delegate method.
 *  @param sessionId `NSString` of the sessionId for the session that has just started.
 *  @see `SOSSessionManager`
 */
- (void)sos:(SOSSessionManager *)sos didCreateSession:(NSString *)sessionId;

/**
 *  Tells the delegate that an error occurred during an active SOS session.
 *
 *  @param sos   `SOSSessionManager` instance that invoked the delegate method.
 *  @param error `NSError` instance describing the error. 
 *               Compare the error code to `SOSErrorCode` for details about the error.
 *  @see `SOSSessionManager`
 *  @see `SOSErrorCode`

 */
- (void)sos:(SOSSessionManager *)sos didError:(NSError*)error;

/**
 *  Tells the delegate that the SOS state changed.
 *
 *  @param sos      `SOSSessionManager` instance that executed the delegate.
 *  @param current  The new `SOSSessionState` that has been set on the `SOSSessionManager` instance.
 *  @param previous The previous `SOSSessionState`.
 *  @see `SOSSessionManager`
 *  @see `SOSSessionState`
 */
- (void)sos:(SOSSessionManager *)sos stateDidChange:(SOSSessionState)current previous:(SOSSessionState)previous;
@end

/**
 *  The `SOSSessionManager` class is the main interface to the SOS framework.
 *
 *  This object manages the flow of SOS sessions throughout the lifetime of the app.
 *  Configuration and customization of the SOS framework is handled through the public 
 *  properties on the `SOSSessionManager` instance.
 *
 *  `SOSSessionManager` conforms to a multicast delegate model for messaging. Any class
 *  which implements the `SOSDelegate` protocol can be added to a list of delegates to
 *  receive messages asynchronously.
 *
 *  To get an instance of this class, use the `SCServiceCloud.sos` property
 *  on `+[SCServiceCloud sharedInstance]`.
 */
@interface SOSSessionManager: NSObject

///---------------------------------
/// @name SOS Management Objects
///---------------------------------

/**
 *  Public reference to the `SOSScreenAnnotations` instance used by the SOS framework.
 */
@property (readonly, atomic) SOSScreenAnnotations *annotations;

/**
 *  Public reference to the `SOSMasking` instance used by the SOS framework.
 */
@property (readonly, atomic) SOSMasking *masking;

/**
 *  Public reference to the `SOSAgentAvailability` object used for checking availability of SOS agents.
 */
@property (readonly, atomic) SOSAgentAvailability *agentAvailability;


/**
 *  Public reference to the `SOSNetworkReporter` object. This object will accept delegates to listen to audio and video
 *  network traffic events.
 *
 *  @see SOSNetworkReportDelegate
 */
@property (readonly, atomic) SOSNetworkReporter *networkReporter;

///---------------------------------
/// @name Other Properties
///---------------------------------

/**
 *  The current `SOSSessionState`.
 */
@property (readonly, atomic) SOSSessionState state;

///---------------------------------
/// @name Session Management
///---------------------------------

/**
 *  Starts the process for creating an SOS session.
 *
 *  Equivalent to invoking `-startSessionWithOptions:completion:` and providing a `nil` block.
 *
 *  @param options `SOSOptions` object that determines the behavior of this session.
 *
 *  @see `-startSessionWithOptions:completion:`
 *  @see `SOSOptions`
 */
- (void)startSessionWithOptions:(SOSOptions *)options;

/**
 Starts the process for creating an SOS session.
 
 By default, the user is asked if they would like to initiate an SOS session.
 Delegate methods:
 
 - `-[SOSDelegate sosDidConnect:]` -- Invoked when all session handshakes and negotiations have completed. The session is fully connected now.
 - `-[SOSDelegate sosDidStart:]` -- Invoked when the session has begun negotiating with required services.
 - `-[SOSDelegate sos:stateDidChange:previous:]` -- Invoked at each state change.
 - `-[SOSDelegate sos:didError:]` -- Invoked if there is an error at any point during the lifetime of a session.
 
 @note The `NSError` returned in the block is `nil` on success.

 @see `SOSDelegate`
 @see `SOSOptions`

 @param options `SOSOptions` object that determines the behavior of this session.
 @param block Completion block which is executed when the session has been fully connected to all services.
              At this point the session is active and waiting for an agent to join.
 */
- (void)startSessionWithOptions:(SOSOptions *)options completion:(SOSCompletionHandler)block;

/**
 *  Begins a teardown of an SOS Session.
 *
 *  Equivalent to invoking `-stopSessionWithCompletion:` and providing a `nil` block.
 *
 *  @see `-stopSessionWithCompletion:`
 */
- (void)stopSession;

/**
 Begins a teardown of an SOS Session.

 By default, the user is asked if they would like to stop the SOS session.
 Delegate Methods:
 
 - `-[SOSDelegate sos:didStopWithReason:error:]` -- Invoked when the session has been fully torn down.
 - `-[SOSDelegate sos:stateDidChange:previous:]` -- Invoked at each state change.
 - `-[SOSDelegate sos:didError:]` -- Invoked if there is an error at any point during the lifetime of a session.

 @note The `NSError` returned in the block is `nil` on success.

 @see `SOSDelegate`
 @param block Completion block which is executed when the session has fully stopped, and all connected services have been torn down.
 */
- (void)stopSessionWithCompletion:(SOSCompletionHandler)block;

/**
 *  Provides a reference to an instance of the `SOSScreenSharing` class.
 */
@property (readonly, atomic) SOSScreenSharing *screenSharing;

///---------------------------------
/// @name Delegate Management
///---------------------------------

/**
 *  Adds an instance of an `NSObject` implementing the `SOSDelegate` protocol to the list of delegates to notify.
 *
 *  @param delegate `NSObject` instance to add.
 */
- (void)addDelegate:(id<SOSDelegate>)delegate;

/**
 *  Removes an instance of an `NSObject` implementing the `SOSDelegate` protocol to the list of delegates to notify.
 *
 *  @param delegate `NSObject` instance to remove.
 */
- (void)removeDelegate:(id<SOSDelegate>)delegate;

///---------------------------------
/// @name Class Methods
///---------------------------------

/**
 Returns the `NSString` containing the current version of the framework.

 @return An `NSString` containing the framework version.
 */
+ (NSString *)frameworkVersion;

@end
