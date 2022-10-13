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

/**
 *  Sets the starting view for the current SOS Session.
 *
 *  @see `SOSOptions`
 */
typedef NS_ENUM(NSInteger, SOSCameraType) {
    /**
     *  Screen sharing mode.
     *  This mode is for sharing the screen view with an agent.
     *  If you wish to use this as the starting camera you must ensure that `SOSOptions.featureClientScreenSharingEnabled`
     *  has been set to `YES`. If it is not, then the session will return a `SOSInvalidOptionsCameraSettings` error.
     */
    SOSCameraTypeScreenSharing,

    /**
     *  Camera on the front of the device (selfie camera).
     *  This mode is for sharing the front-facing camera with an agent.
     *  If you wish to use this as the starting camera you must ensure that `SOSOptions.featureClientFrontCameraEnabled`
     *  has been set to `YES`. If it is not, then the session will return a `SOSInvalidOptionsCameraSettings` error.
     */
    SOSCameraTypeFrontFacing,

    /**
     *  Camera on the back of the device.
     *  This mode is for sharing the back-facing camera with an agent.
     *  If you wish to use this as the starting camera you must ensure that `SOSOptions.featureClientBackCameraEnabled`
     *  has been set to `YES`. If it is not, then the session will return a `SOSInvalidOptionsCameraSettings` error.
     */
    SOSCameraTypeBackFacing
};

/**
 *  Sets the Phase of the UI that will be replaced by the user
 *
 *  @see `SOSOptions`
 */
typedef NS_ENUM(NSInteger, SOSUIPhase) {
    /**
     *  Onboarding Phase.
     *  This phase is used for showing the user information about the support system that is about to be activated.
     *  The options could be presented to the user to allow access to the camera or mic. How the SOS system functions
     *  could also be relayed to this user. The class associated with this phase must extend `SOSOnboardingBaseViewController`
     *  and implement the protocol `SOSOnboardingViewController`.
     */
    SOSUIPhaseOnboarding,
    /**
     *  Connecting Phase.
     *  This phase is used for showing the user information while the SOS system is connecting to the user. The class
     *  associated with this phase must extend `SOSConnectingBaseViewController` and implement the protocol `SOSConnectingViewController`.
     */
    SOSUIPhaseConnecting,
    /**
     *  ScreenSharing Phase.
     *  This phase is the UI shown to the user during the screen sharing phase. The class associated with this phase must
     *  extend `SOSSessionBaseViewController` and implement the protocols `SOSUILineDrawingReceivable` and `SOSUIAgentStreamReceivable`.
     */
    SOSUIPhaseScreenSharing,
    /**
     *  Camera Phase.
     *  This phase is the UI shown to the user when the camera is in use. The class associated with this phase must
     *  extend `SOSCameraBaseViewController` and implement the protocols `SOSUIAgentStreamReceivable` and `SOSUIDeviceCameraReceivable`.
     */
    SOSUIPhaseCamera,
};

/**
 *  The `SOSOptions` class allows you to configure the behavior of any `SOSSessionManager` session.
 *
 *  This object determines how an SOS session is routed, as well as the behavior of a session once established.
 */
@interface SOSOptions : NSObject

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Instantiates an `SOSOptions` object for use with `-[SOSSessionManager startSessionWithOptions:completion:]`.
 *
 *  @param liveAgentPod The hostname for the LiveAgent pod that your organization has been assigned. Also known as the Live Agent Endpoint.
 *  @param orgId        The Salesforce organization ID.
 *  @param deploymentId The unique ID of the deployment for this session.
 *
 *  @return An `SOSOptions` instance.
 *
 *  @see liveAgentPod
 *  @see orgId
 *  @see deploymentId
 */
+ (instancetype)optionsWithLiveAgentPod:(NSString *)liveAgentPod
                                  orgId:(NSString *)orgId
                           deploymentId:(NSString *)deploymentId;

/**
 *  Validates the current values of the `SOSOptions` properties.
 *  The `error` parameter is `nil` on success.
 *  Otherwise, it contains a list of invalid properties.
 *
 *  @param error An error object if there are invalid parameters.
 *  @return Whether the `SOSOptions` values are valid.
 */
- (BOOL)validate:(NSError * __autoreleasing *)error;

/**
 *  Sets the replacement viewControllers for a phase of the UI interaction.
 *
 *  @param class A ViewController class that will replace the default ViewController UI.
 *  @param phase The Phase of the SOS session UI that is being replaced.
 *  @see `SOSUIPhase`
 */
- (void)setViewControllerClass:(Class)class for:(SOSUIPhase)phase;

///---------------------------------
/// @name SFDC Service Cloud / Live Agent Configuration
///---------------------------------

/**
 *  The hostname for the LiveAgent pod that your organization has been assigned.
 *
 *  To get this value, from Setup, search for `Live Agent Settings` and copy the hostname from the `Live Agent API Endpoint`.
 */

@property (nonatomic) NSString *liveAgentPod;

/**
 *  Salesforce organization ID.
 *
 *  To get this value, from Setup, search for `Company Information` and copy the `Salesforce Organization ID`.
 */
@property (nonatomic) NSString *orgId;

/**
 * The unique ID of the deployment for this session.
 *
 * A new deployment ID can be created in the Setup tab under `SOS Deployments`.
 * The deployment ID is used to route specific types of support requests to any number of agents.
 * You can set up any number of deployment IDs for your application to accommodate any routing model you choose.
 * To get this value, from Setup, search for `SOS Deployments`, click the correct deployment and copy the `Deployment ID`.
 */
@property (nonatomic) NSString *deploymentId;


///---------------------------------
/// @name Session Management
///---------------------------------

/**
 *  The length of time (in seconds) before SOS prompts the user to retry or cancel.
 */
@property (nonatomic) NSTimeInterval sessionRetryTime;

/**
 *  By default, we send along the bundle version with session requests.
 *  If you wish to override this explicitly, you can use this property.
 *
 *  @warning Note that only __64 MAX character strings__ are supported.
 */
@property (nonatomic) NSString *applicationVersion;

/**
 *  The initial `SOSCameraType` setting to be streamed upon starting a session.
 *
 *  Default: `SOSCameraTypeScreenSharing`
 *
 * @see `SOSCameraType`
 */
@property (nonatomic) SOSCameraType initialCameraType;

/**
 *  Determines whether session logs are sent for collection.
 *  Logs sent remotely do not collect personal information. Unique IDs are created for tying logs to sessions,
 *  and those IDs cannot be correlated back to specific users.
 *
 *  Default: `YES`
 */
@property (nonatomic) BOOL remoteLoggingEnabled;

/**
 *  Whether the agent video stream is active upon starting a session.
 *
 *  Default: `YES`
 */
@property (nonatomic) BOOL initialAgentVideoStreamActive;

/**
 *  Whether the agent video stream is enabled for the session.
 *
 *  Default: `YES`
 */
@property (nonatomic) BOOL featureAgentVideoStreamEnabled;

/**
 *  Whether screen sharing is enabled for the session.
 *
 *  Default: `YES`
 */
@property (nonatomic) BOOL featureClientScreenSharingEnabled;

/**
 *  Whether the front-facing (selfie) camera is enabled for the session.
 *
 *  Default: `NO`
 */
@property (nonatomic) BOOL featureClientFrontCameraEnabled;

/**
 *  Whether the back-facing camera is enabled for the session.
 *
 *  Default: `NO`
 */
@property (nonatomic) BOOL featureClientBackCameraEnabled;

/**
 *  Whether the agent stream is visible in the camera view.
 *
 *  If this is disabled then only the device camera is visible in the camera view.
 *
 *  Default: 'YES'
 */
@property (nonatomic) BOOL agentSteamEnabledInCameraView;

/**
 *  Whether the network test is enabled before and during a session.
 *
 *  Default: `YES`
 */
@property (nonatomic) BOOL featureNetworkTestEnabled;

/**
 * NSMutableDictionary that can be used to send custom data.
 */
@property (nonatomic) NSMutableDictionary *customFieldData;

/**
 *  NSDictionary that contains the registered viewControllers that will override the internal user interfaces
 */
@property (retain, nonatomic) NSDictionary *viewControllerClasses;

/**
 *  CGPoint that contains the starting center location of the session controls view. If using replacement UI, this functionality needs to be implemented in the replacement UI code.
 */
@property (assign, nonatomic) CGPoint initialAgentStreamPosition;

@end
