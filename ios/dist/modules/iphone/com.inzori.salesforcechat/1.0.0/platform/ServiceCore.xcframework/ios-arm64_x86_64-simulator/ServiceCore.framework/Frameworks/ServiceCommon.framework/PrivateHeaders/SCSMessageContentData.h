//
//  SCSMessageContentData.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/28/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSContentData.h"
/**
 Protocol defining content that can be returned from classes conforming to SCSContent.
 */
@protocol SCSMessageContentData <SCSContentData>

/**
 Timestamp that  identifies the time and date of whent he message was generated.
 */
@property (nonatomic, copy, readonly) NSDate *timestamp;

@end
