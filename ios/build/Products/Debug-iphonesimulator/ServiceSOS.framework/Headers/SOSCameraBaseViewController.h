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

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ServiceSOS/SOSUIAgentStreamReceivable.h>
#import <ServiceSOS/SOSSessionBaseViewController.h>
#import <ServiceSOS/SOSUIDeviceCameraReceivable.h>

/**
 *  The SOSCameraBaseViewController serves as the base controller which manages interactions between the UI and SOS backend
 *  for the camera phase of SOS.
 *
 *  If you wish to replace the camera UI, your class must implement this base class.
 *
 *  All method overrides require a call back to super for SOS to function properly.
 */
@interface SOSCameraBaseViewController : SOSSessionBaseViewController<SOSUIAgentStreamReceivable, SOSUIDeviceCameraReceivable>

///---------------------------------
/// @name UI Action Handlers
///---------------------------------

/**
 *  This will trigger a transition to the <SOSScreenSharingBaseViewController>, and mark the SOS Session as being
 *  in the screen sharing phase. At this point the camera phase is ending, and the view controller will
 *  attempt to clean up.
 *
 *  @warning Please ensure that your view controller cleans up entirely. Any reference cycles will result
 *  in additional instances of this view controller in memory when returning to the camera phase.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleScreenSharingTransition:(id)sender NS_REQUIRES_SUPER;

/**
 *  Action performed when switching the current device capture position.
 *
 *  This method will automatically call <[SOSCameraBaseViewController setDevicePosition:]> with the opposite camera
 *  value; for example, switching from front to back. If the SOS session has only been configured with one available camera
 *  this method will have no effect.
 *
 *  If you wish to handle the device position in a different way, you can ignore this action and use
 *  <[SOSCameraBaseViewController setDevicePosition:]> directly instead.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param sender The object which triggered the action.
 */
- (IBAction)handleToggleDevicePosition:(id)sender NS_REQUIRES_SUPER;

///---------------------------------
/// @name Session State Management
///---------------------------------

/**
 *  Required method to instruct the backend to toggle the current AVDeviceCapturePosition used for transmitting the device camera.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @param position The current desired camera capture position.
 */
- (void)setDevicePosition:(AVCaptureDevicePosition)position NS_REQUIRES_SUPER;

/**
 *  Required method to call to get the current AVCaptureDevicePosition state of the SOS Session.
 *
 *  @warning This method is used to communicate between the UI API and the SOS backend. If you wish to
 *  override this method you can do so safely; however you must call this method on `super`. Failure to do
 *  so will result in undefined and likely broken behavior from SOS.
 *
 *  @return The current AVCaptureDevicePosition state of the SOS Session.
 */
- (AVCaptureDevicePosition)currentDevicePosition NS_REQUIRES_SUPER;

/**
 *  Returns the proper initial camera position for the 2-way capture device. (Front or Back)
 *
 *  This is determined by several factors, including device availability and the configuration
 *  in the <SOSOptions> object.
 *
 *  You can optionally choose to override this method to return whatever device position you choose,
 *  however it is recommended that you continue to use the <SOSOptions> object to define session behavior.
 *
 *  @warning If no camera is available this will return AVCaptureDevicePositionUnspecified.
 *
 *  @return The initial device position.
 */
- (AVCaptureDevicePosition)resolveInitialDevicePosition;

/**
 *  Determines whether or not the provided position is configured to be available for an SOS Session.
 *
 *  @param position The position you wish to check.
 *
 *  This will allow you to easily check whether the current SOS session is configured to allow the provided position.
 *  You can optionally choose to override this method to allow any position. However, we recommend that you continue
 *  to use the <SOSOptions> object to define session behavior.
 *
 *  @return Whether the provided position is valid for the current session.
 */
- (BOOL)devicePositionAvailable:(AVCaptureDevicePosition)position;

@end
