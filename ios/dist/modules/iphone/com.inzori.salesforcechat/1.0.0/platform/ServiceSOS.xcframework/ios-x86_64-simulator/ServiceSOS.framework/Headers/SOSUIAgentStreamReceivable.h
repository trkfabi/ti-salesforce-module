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
 * The `SOSUIAgentStreamReceivable` protocol allows your view controller implementation to handle an agent video stream.
 */
@protocol SOSUIAgentStreamReceivable
@required

/**
 * Asks your delegate whether it can handle an agent video stream.
 *
 * @return `YES` if the class can handle agent streams.
 */
- (BOOL)willHandleAgentStream;

/**
 * Asks your delegate whether it can handle remote movement of the video stream.
 *
 * @return `YES` if the class can handle remote movement.
 */
- (BOOL)willHandleRemoteMovement;

/**
 * Asks your delegate whether it can handle audio level adjustments.
 *
 * @return `YES` if the class can handle audio levels.
 */
- (BOOL)willHandleAudioLevel;

@optional

/**
 * Tells your delegate when there is an agent video stream.
 *
 * @param agentStreamView The view containing the agent stream.
 */
- (void)didReceiveAgentStreamView:(__weak UIView *)agentStreamView;

/**
 * Tells your delegate the new location coordinates of an agent stream.
 *
 * @param coordinate The new location coordinates.
 */
- (void)didReceiveAgentStreamScreenCoordinate:(CGPoint)coordinate;

/**
 * Tells your delegate when the audio level has changed.
 *
 * @param audioLevel The new audio level.
 */
- (void)didReceiveAudioLevelUpdate:(CGFloat)audioLevel;


/**
 Tells your delegate when the recording of the session has changed.

 @param recording The recording value.
 */
- (void)didReceiveRecordingUpdate:(BOOL)recording;

@end

NS_ASSUME_NONNULL_END
