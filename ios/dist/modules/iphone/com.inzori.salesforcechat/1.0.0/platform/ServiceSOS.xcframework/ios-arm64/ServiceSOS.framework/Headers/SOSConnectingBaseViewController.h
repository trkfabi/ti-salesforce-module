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

NS_ASSUME_NONNULL_BEGIN

/**
 *  Protocol which defines properties and methods which are required for all view controllers which
 *  will accommodate the role for onboarding in SOS.
 *
 *  @see `SOSConnectingBaseViewController`

 */
@protocol SOSConnectingViewController <NSObject>
@optional

///---------------------------------
/// @name Notifications
///---------------------------------

/**
 *  Message from the backend which indicates that the session is initializing.
 *
 *  This method allows your implementation to present a custom message for this event.
 *  This is entirely optional as no input is required from the user.
 */
- (void)initializingNotification;

/**
 *  Message from the backend which indicates that the session has been placed in a queue
 *  and we are waiting for an agent to connect.
 *
 *  This method allows your implementation to present a custom message for this event.
 *  This is entirely optional as no input is required from the user.
 */
- (void)waitingForAgentNotification;

/**
 *  Message from the backend which indicates that an agent is connecting to the session.
 *  Once the session has been fully established the session will move on to the next phase.
 *
 *  This method allows your implementation to present a custom message for this event.
 *  This is entirely optional as no input is required from the user.
 */
- (void)agentJoinedNotification;

/**
 *  Message from the backend which provides the agent name and indicates that it is available.
 *
 *  @param agentName the name of the agent
 */
- (void)agentNameDidChange:(NSString * _Nullable)agentName;

@end

/**
 *  The `SOSConnectingBaseViewController` serves as the base controller which manages interactions between the UI and SOS backend
 *  for the connecting phase of SOS.
 *
 *  If you wish to replace the onboarding UI, your class must implement this base class.
 *
 *  All method overrides require a call back to super for SOS to function properly.
 *
 *  @see `SOSConnectingViewController`
 */
@interface SOSConnectingBaseViewController : UIViewController <SOSConnectingViewController>

/**
 *  Action performed when confirming an end session.
 *
 *  @warning Executing this action will immediately trigger the end session cleanup. The responsibility of
 *  handling user confirmation remains as an implementation detail for the view controller.
 *
 *  @param sender the object which triggered the action.
 */
- (IBAction)handleEndSession:(id)sender NS_REQUIRES_SUPER;


@end

NS_ASSUME_NONNULL_END
