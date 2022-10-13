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

@import ServiceCore.ServiceCommon.SCCDefines;
@import ServiceCore.ServiceCommon.SCAppearanceConfiguration;

///---------------------------------
/// @name Controls Icons
///---------------------------------
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSCancel;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSConfirmIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSEndIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSPauseIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSResumeIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSMicrophoneIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSMicrophoneMutedIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSAgentMutedIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSCameraIcon;

// Deprecated mappings
SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSCancel")
SCS_EXTERN NSString *const kSCAppearanceSOSCancelIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSConfirmIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSConfirmIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSEndIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSEndIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSPauseIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSPauseIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSResumeIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSResumeIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSMicrophoneIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSMicrophoneIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSMicrophoneMutedIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSMicrophoneMutedIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSAgentMutedIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSAgentMutedIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSCameraIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSCameraIcon;

///---------------------------------
/// @name Agent Stream
///---------------------------------
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSAgentPlaceHolderIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSAgentPlaceHolderIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSAgentPlaceHolderIcon;

///---------------------------------
/// @name Camera
///---------------------------------
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSExpandIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSFlashlightIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSInfoIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSExpandIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSExpandIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSFlashlightIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSFlashlightIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSInfoIcon")
SCS_EXTERN NSString *const kSCAppearanceSOSInfoIcon;

///---------------------------------
/// @name Masking
///---------------------------------
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSOSMasking;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSOSMasking")
SCS_EXTERN NSString *const kSCAppearanceSOSMasking;
