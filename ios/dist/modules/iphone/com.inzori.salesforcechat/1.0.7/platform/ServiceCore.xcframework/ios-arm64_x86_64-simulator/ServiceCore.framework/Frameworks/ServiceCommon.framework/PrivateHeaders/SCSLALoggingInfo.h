//
//  SCSLALoggingInfo.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 9/23/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 SCSLALoggingInfo class definition.
 Private class to pass the required logging parameters to the SCSLiveAgentLogger Class.
 
 */
@interface SCSLALoggingInfo : NSObject
/*
 SDK specific orgId to be used for logging.
 */
@property (nonatomic, strong) NSString *orgId;
/*
 Version of the SDK to be used for logging.
 */
@property (nonatomic, strong) NSString *frameworkVersion;
/*
 The LiveAgent endpoint to be used for logging.
 */
@property (nonatomic, strong) NSString *liveAgentPod;
/*
 The name of the sdk that is using logging.
 */
@property (nonatomic, strong) NSString *serviceName;

@end
