/*
 * Copyright 2017 salesforce.com, inc.
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
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Delegate protocol to listen to SOS network traffic events.
 */
@protocol SOSNetworkReporterDelegate <NSObject>


/**
 * This method will return network traffic information relating to video traffic in SOS.
 * This method should be fired every 30 seconds during an active session. All traffic info
 * relates to incoming video traffic. The network reporting will only start once an SOS
 * session has been fully negotiated.
 *
 * @param sessionId The SOS Session Id which correlates to the data being provided.
 * @param bytesReceived The number of bytes received for video traffic since the last update.
 * @param packetsReceived The number of packets received for video traffic since the last update.
 * @param packetsLost The number of packets lost for video traffic since the last update.
 * @param videoDimensions The size in pixels of the incoming video stream.
 * @param timeStamp The timestamp in millisecond epoch format.
 */
- (void)videoNetworkStatsDidUpdateWithSessionId:(NSString *)sessionId
                                  bytesReceived:(NSNumber *)bytesReceived
                                packetsReceived:(NSNumber *)packetsReceived
                                    packetsLost:(NSNumber *)packetsLost
                                videoDimensions:(CGSize *)videoDimensions
                                      timeStamp:(NSNumber *)timeStamp;


/**
 * This method will return network traffic information relating to video traffic in SOS.
 * This method should be fired every 30 seconds during an active session. All traffic info
 * relates to incoming audio traffic. The network reporting will only start once an SOS
 * session has been fully negotiated.
 *
 * @param sessionId The SOS Session Id which correlates to the data being provided.
 * @param bytesReceived The number of bytes received for audio traffic since the last update.
 * @param packetsReceived The number of packets received for audio traffic since the last update.
 * @param packetsLost The number of packets lost for audio traffic since the last update.
 * @param timeStamp The timestamp in millisecond epoch format.
 */
- (void)audioNetworkStatsDidUpdateWithSessionId:(NSString *)sessionId
                                  bytesReceived:(NSNumber *)bytesReceived
                                packetsReceived:(NSNumber *)packetsReceived
                                    packetsLost:(NSNumber *)packetsLost
                                      timeStamp:(NSNumber *)timeStamp;

@end

NS_ASSUME_NONNULL_END
