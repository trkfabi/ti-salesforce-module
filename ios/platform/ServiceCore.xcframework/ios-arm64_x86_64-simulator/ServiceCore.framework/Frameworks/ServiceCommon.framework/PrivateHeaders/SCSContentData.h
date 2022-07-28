//
//  SCSContentData.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Protocol defining content that can be returned from classes conforming to SCSContent.
 */
@protocol SCSContentData <NSObject>

/**
 ID that uniquely identifies a given instance of data that can be returned from SCSContent.
 */
@property (nonatomic, copy, readonly) NSString *contentDataId;

@end
