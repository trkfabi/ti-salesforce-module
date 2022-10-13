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

/**
 *  SOS ErrorCode definitions.
 *
 *  Errors fall into one of several groups (or series) of errors.
 *
 *  If there is an error thrown by a library dependency it will be included as metadata
 *  in the userInfo of the error which is returned to the application code.
 */
typedef NS_ENUM(NSInteger, SOSErrorCode) {
    ///--------------------------------
    /// @name General Errors (1000-series)
    ///--------------------------------

    /**
     *  Unclassified error. This results from an unknown or unexpected error state.
     *
     *  Any other un-grouped errors will be added to the 0-99 series error group.
     */
    SOSGenericError = 1000,

    /**
     * Returned from <[SOSSessionManager startSessionWithOptions:completion:]> if the SOSOptions provided is `nil` or invalid.
     */
    SOSInvalidOptions = 1001,

    /**
     * Returned from <[SOSSessionManager startSessionWithOptions:completion:]> if SOSOptions contains invalid camera options.
     * (e.g. initialCameraType = `SOSCameraTypeBackFacing` && <[SOSOptions featureClientBackCameraEnabled]> == `NO`)
     */
    SOSInvalidOptionsCameraSettings = 1002,

    ///--------------------------------
    /// @name Connection Errors (2000-series)
    ///--------------------------------

    /**
     * Standard connection error. This can be thrown from any part of the SOS Session connection flow.
     *
     * All connection related errors will be found in the 100-199 series error group.
     */
    SOSConnectionError = 2000,

    /**
     *  Returned from <[SOSSessionManager startSessionWithOptions:completion:]> if there is a session already active or in progress.
     */
    SOSSessionIsActiveError = 2001,

    /**
     *  Returned from <[SOSSessionManager stopSessionWithCompletion:]> if there is no active session to stop.
     */
    SOSNoActiveSessionError = 2002,

    /**
     *  Returned if the network becomes unavailable.
     */
    SOSNetworkUnavailableError = 2003,

    ///--------------------------------
    /// @name Server Errors (3000-series)
    ///--------------------------------

    /**
     *  Standard server error. This can be returned from operations made to the SOS server.
     *
     *  All server related errors will be found in the 200-299 series error group.
     */
    SOSServerError = 3000,

    /**
     * Server metadata error.  This can be returned from operations attempting to update
     * the state of the session.
     */
    SOSServerMetaDataError = 3001,

    /**
     * Error returned when the session creation request is not successful.
     */
    SOSServerSessionCreationError = 3002,

    /**
     * Error returned when agent availability API encounters a problem.
     */
    SOSAgentAvailabilityError = 3003,

    /**
     * Error occured when attempting to disconnect a session after a switch server occurred.
     */
    SOSSwitchServerSessionDisconnectError = 3004,

    /**
     * Error returned when the session end request is not successful.
     */
    SOSServerSessionEndError = 3005,

    ///--------------------------------
    /// @name Communication Errors (4000-series)
    ///--------------------------------

    /**
     *  Standard communication error. This can be returned from operations dependent on communication
     *  between SOS or any other remote system.
     *
     *  All communication related errors will be found in the 300-399 series error group.
     */
    SOSCommunicationError = 4000,

    /**
     *  Returned by the framework if there are no agents available to serve a session attempt.
     */
    SOSNoAgentsAvailableError = 4001,

    /**
     *  Returned by the framework if the network test has failed to start.
     */
    SOSNetworkTestError = 4002,

    /**
     *  Returned by the framework if the network test has determined that the environment cannot support an SOS session.
     */
    SOSInsufficientNetworkError = 4003,

    ///--------------------------------
    /// @name Application Errors (5000-series)
    ///--------------------------------

    /**
     *  Standard internal framework error. This can be returned from operations performed within the SOS framework.
     *
     *  All internal errors will be found in the 400-499 series error group.
     */
    SOSInternalError = 5000,

    ///--------------------------------
    /// @name RTC Provider Errors (6000-series)
    ///--------------------------------

    /**
     *  Standard RTC Provider error. This can be returned as a result of operations performed by the RTC provider.
     *
     *  Since the RTC provider is a separate library, error specifics will be wrapped and included in the userInfo of
     *  errors returned with this code.
     */
    SOSRTCProviderError = 6000,
    
    /**
     *  Error returned if there is a problem creating an authentication token with the
     *  WebRTC provider.
     */
    SOSRTCProviderAuthenticationError = 6001,
};
