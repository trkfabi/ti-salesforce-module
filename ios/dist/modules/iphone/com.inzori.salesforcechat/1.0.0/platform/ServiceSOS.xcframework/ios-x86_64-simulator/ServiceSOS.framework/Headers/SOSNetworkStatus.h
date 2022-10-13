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
 *  Defines the discrete network conditions which can occur within an SOS Session.
 */
typedef NS_ENUM(NSUInteger, SOSNetworkStatus) {
    /**
     *  The network and bandwidth tests run during a session have determined that the
     *  network is capable of sustaining a healthy SOS session.
     */
    SOSNetworkStatusOk,
    /**
     *  The network and bandwidth tests run during a session have indicated that the
     *  network may not be able to fully support an SOS session. Audio and video artifacts
     *  may appear during the session. In the wost case the session itself could timeout.
     */
    SOSNetworkStatusPoor
};

/**
 Defines the discrete network reconnect status which can occur within an SOS Session.
 */
typedef NS_ENUM(NSUInteger, SOSReconnectStatus) {
    /**
     * The network reconnect implemented by the WebRTC provider has signaled a reconnect
     * has started.
     */
    SOSNetworkReconnectStarted,
    /**
     * The network reconnect implemented by the WebRTC provider has signaled a reconnect
     * has finished.
     */
    SOSNetworkReconnectFinished
};
