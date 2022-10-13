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

#import "SOSUIAgentStreamReceivable.h"
#import "SOSUILineDrawingReceivable.h"
#import "SOSSessionBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The `SOSScreenSharingBaseViewController` serves as the base controller which manages interactions between the UI and SOS backend
 *  for the screen sharing phase of SOS.
 *
 *  If you wish to replace the screen sharing UI, your class must implement this base class.
 *
 *  All method overrides require a call back to super for SOS to function properly.
 *
 *  @see `SOSSessionBaseViewController`
 *  @see `SOSUIAgentStreamReceivable`
 *  @see `SOSUILineDrawingReceivable`
 */
@interface SOSScreenSharingBaseViewController : SOSSessionBaseViewController<SOSUIAgentStreamReceivable, SOSUILineDrawingReceivable>

/**
 *  This will trigger a transition to the camera view, and mark the SOS Session as being
 *  in the camera phase. At this point the screen sharing phase is ending, and the view controller will
 *  attempt to clean up.
 *
 *  @warning Please ensure that your view controller cleans up entirely. Any reference cycles will result
 *  in additional instances of this view controller in memory when returning to the screen sharing phase.
 *
 *  This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleCameraTransition:(id)sender NS_REQUIRES_SUPER;

///---------------------------------
/// @name Session State Management
///---------------------------------

/**
 *  Required method to call if you wish to wish to have the agent stream container on the service 
 *  cloud widget move as a response to changes in your UI. The center point you provide will be used to update
 *  the agent container position in the service cloud widget.
 *
 *  @warning Each time you call this method it will result in a status update on the session. For that reason
 *  it is recommended that you do not call this method during a drag gesture, but rather update the position
 *  once the position has been determined.
 *
 *  This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param center The new center point of the agent container in the service cloud widget.
 */
- (void)setAgentStreamCenter:(CGPoint)center NS_REQUIRES_SUPER;


/**
 Required method to call if you wish to have a UI indicator that informs the user of changes to the screen sharing state.
 This method will be called when the screenSharing state changes.

 @param sharing The current sharing state of the session.
 */
- (void)screenSharingStateDidChange:(BOOL)sharing NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
