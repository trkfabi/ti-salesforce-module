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

#import "SOSSessionManager.h"
#import "SOSMaskable.h"

/**
 *  The `SOSMasking` class is responsible for managing the field masking applied during an SOS
 *  session. Sensitive fields or sections of the application may be masked to prevent them from
 *  appearing to the customer service agent in the video feed.
 *
 *  You can retrieve a reference to this class from the `SOSSessionManager` instance, and then
 *  use the APIs provided below to add or remove parts of your application to be masked on an
 *  as-needed basis.
 *
 * @see `SOSSessionManager`
 * @see `SOSDelegate`
 */
@interface SOSMasking : NSObject<SOSDelegate>

- (id)initWithSOS:(__weak SOSSessionManager *)sos;

///---------------------------------
/// @name KVO-compliant properties
///---------------------------------

/**
 *  The current state of the masks. This state is driven by the state of the SOS session and SOS
 *  screen sharing.
 */
@property (readonly, atomic) SOSMaskState state;


///---------------------------------
/// @name Adding Masks
///---------------------------------

/**
 *  Register an object conforming to the `SOSMaskable` protocol to receive messages regarding the
 *  current masking state.
 *
 *  This object is *not* retained by the `SOSMasking` class.
 *
 *  @param view The maskable object.
 */
- (void)registerView:(id<SOSMaskable>)view;

///---------------------------------
/// @name Removing Masks
///---------------------------------

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
