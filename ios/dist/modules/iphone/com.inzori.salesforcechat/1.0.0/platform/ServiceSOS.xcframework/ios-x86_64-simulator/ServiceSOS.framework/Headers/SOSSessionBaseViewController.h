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

#import "SOSNetworkStatus.h"
#import "SOSUIAgentStreamReceivable.h"
#import "SOSUILineDrawingReceivable.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Protocol which defines properties and methods which are required for all view controllers which
 *  will accommodate the role for screen sharing in SOS.
 */
@protocol SOSSessionViewController <NSObject>
@optional

///---------------------------------
/// @name Notifications
///---------------------------------

/**
 *  Message from the backend that the session is attempting to reconnect.
 *  You may receive this message in the event that the session is attempting to recover from a network disconnection or
 *  in the event of backgrounding the application or after receiving a phone call.
 *
 *  This method allows your implementation to present a custom message for this event.
 *  This is entirely optional as no input is required from the user.
 */
- (void)reconnectingNotification;

/**
 *  Message from the backend that the session has successfully reconnected.
 *
 *  This method allows your implementation to present a custom message for this event.
 *  This is entirely optional as no input is required from the user.
 */
- (void)reconnectionCompleteNotification;

/**
 *  Message from the backend that the agent has paused/unpaused their connection.
 *  This method will be executed any time the agent pause state has changed.
 *
 *  @param paused The current agent paused state. `YES` means that the agent is currently pausing their connection.
 */
- (void)agentPausedConnectionNotification:(BOOL)paused;

/**
 *  Message from the backend that the network connection status has changed.
 *  The status is determined by bandwidth tests which are conducted during an SOS session.
 *  When the status changes you will receive this method with the current network status.
 *
 *  @param networkStatus The current network status.
 */
- (void)networkStatusUpdateNotification:(SOSNetworkStatus)networkStatus;


/**
 Message from the backend that the WebRTC provider has changed the reconnect status.
 The status message is determined by signals from the WebRTC provider.
 When the status changes, you will receive this method with the current reconnect status.

 @param reconnectStatus The current network reconnect status.
 */
- (void)reconectStatusUpdateNotification:(SOSReconnectStatus)reconnectStatus;

@end

/**
 *  The `SOSScreenSharingBaseViewController` serves as the base controller which manages interactions between the UI and SOS backend
 *  for the screen sharing phase of SOS.
 *
 *  If you wish to replace the screen sharing UI, your class must implement this base class.
 *
 *  All method overrides require a call back to super for SOS to function properly.
 *
 *  @see `SOSSessionViewController`
 */
@interface SOSSessionBaseViewController : UIViewController<SOSSessionViewController>

///---------------------------------
/// @name UI Action Handlers
///---------------------------------

/**
 *  Action performed when pausing or unpausing an SOS Session.
 *
 *  This method will automatically call `-setSOSPaused:`.
 *  The value will be derived from the negation of `-isSOSPaused`.
 *  If you wish to handle the muted state in a different way, you can ignore this action and use
 *  `-setSOSPaused:` directly instead.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handlePause:(id)sender NS_REQUIRES_SUPER;

/**
 *  Action performed when muting or unmuting the audio for an SOS Session.
 *
 *  This method will automatically call `-setSOSMuted:`.
 *  The value will be derived from the negation of `-isSOSMuted`.
 *  If you wish to handle the muted state in a different way, you can ignore this action and use
 *  `-setSOSMuted:` directly instead.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleMute:(id)sender NS_REQUIRES_SUPER;

/**
 *  Action performed when confirming an end session.
 *
 *  @warning Executing this action will immediately trigger the end session cleanup. The responsibility of
 *  handling user confirmation remains as an implementation detail for the view controller.
 *
 *  This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleEndSession:(id)sender NS_REQUIRES_SUPER;

///---------------------------------
/// @name Session State Management
///---------------------------------

/**
 *  Call this (required) method when informing the SOS backend that you wish to mute outgoing audio.
 *  This method will instruct the backend to continue/discontinue transmitting audio from the device.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param isMuted Whether the outgoing audio stream has been muted.
 */
- (void)setSOSMuted:(BOOL)isMuted NS_REQUIRES_SUPER;

/**
 *  Call this (required) method to get the current muted state of the SOS Session.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @return The current muted state of the SOS Session.
 */
- (BOOL)isSOSMuted NS_REQUIRES_SUPER;

/**
 *  Call this (required) method when informing the SOS backend that you wish to pause the session.
 *  This method will instruct the backend to continue/discontinue all audio and video traffic from the device.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param isPaused Whether the outgoing audio/video traffic has been paused.
 */
- (void)setSOSPaused:(BOOL)isPaused NS_REQUIRES_SUPER;

/**
 *  Call this (required) method to get the current local paused state of the SOS Session.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @return The current paused state of the SOS Session.
 */
- (BOOL)isSOSPaused NS_REQUIRES_SUPER;

/**
 *  This value is set on the service cloud integration. It should not change during the lifetime of a session.
 *  You can use this method to determine if you wish to display a recording status in your UI.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @return Whether the session is being recorded.
 */
- (BOOL)isRecording NS_REQUIRES_SUPER;

///---------------------------------
/// @name Session Information
///---------------------------------

/**
 *  Call this (required) method to get the agent name.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @return The agent name.
 */

- (NSString *)agentName NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
