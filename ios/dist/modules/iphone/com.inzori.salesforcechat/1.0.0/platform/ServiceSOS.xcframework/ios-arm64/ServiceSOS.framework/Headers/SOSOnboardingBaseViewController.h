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
 *  @see `SOSOnboardingBaseViewController`
 */
@protocol SOSOnboardingViewController <NSObject>

///---------------------------------
/// @name Alerts
///---------------------------------

/**
 *  This method determines whether this view controller will handle a connection request prompt. Default is `YES`.
 *  If this method returns `NO` then the SOS backend will directly proceed to the connection phase.
 *
 *  Return `NO` if you do not wish to display a pre-connection onboarding screen for SOS sessions. If this method returns `NO`
 *  your class will not receive a `-[SOSOnboardingViewController connectionPromptRequested]` call.
 *
 *  @return Whether this view controller will handle a connection prompt.
 */
- (BOOL)willHandleConnectionPrompt;

/**
 *  This method will be executed on the `SOSOnboardingViewController` when the SOS backend has requested a user response.
 *  At this point it is appropriate to display a UI element which will allow a user to confirm or cancel.
 *
 *  The SOS backend will wait until it receives an appropriate response. Your UI element must trigger either:
 *  `-[SOSOnboardingBaseViewController handleStartSession:]` or
 *  `-[SOSOnboardingBaseViewController handleCancel:]`.
 *
 *  @see `-[SOSOnboardingViewController willHandleConnectionPrompt]`
 */
- (void)connectionPromptRequested;

@end

/**
 *  The `SOSOnboardingBaseViewController` serves as the base controller which manages interactions between the UI and SOS backend
 *  for the onboarding phase of SOS.
 *
 *  If you wish to replace the onboarding UI, your class must implement this base class.
 *
 *  All method overrides require a call back to super for SOS to function properly.
 *
 *  @see `SOSOnboardingViewController`
 */
@interface SOSOnboardingBaseViewController : UIViewController<SOSOnboardingViewController>

///---------------------------------
/// @name UI Actions
///---------------------------------

/**
 *  Action performed when confirming a start session.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleStartSession:(id)sender NS_REQUIRES_SUPER;

/**
 *  Action performed when cancelling a session.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleCancel:(id)sender NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
