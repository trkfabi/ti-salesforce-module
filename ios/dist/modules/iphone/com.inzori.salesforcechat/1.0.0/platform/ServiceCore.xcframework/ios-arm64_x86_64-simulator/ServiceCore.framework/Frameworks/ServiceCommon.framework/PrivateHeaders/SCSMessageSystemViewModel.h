//
//  SCSMessageSystemViewModel.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SCSMessageContentData.h"

@interface SCSMessageSystemViewModel : NSObject <SCSMessageContentData>

@property (nonatomic, copy, readonly) NSString *text;

-(instancetype)initWithMessageText:(NSString*)messageText itemId:(NSString*)itemId timestamp:(NSDate*)messageTimestamp;

@end
