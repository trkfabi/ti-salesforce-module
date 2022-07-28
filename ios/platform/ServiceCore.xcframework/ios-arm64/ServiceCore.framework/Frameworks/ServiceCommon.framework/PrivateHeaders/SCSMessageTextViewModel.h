//
//  SCSMessageTextViewModel.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SCSMessageContentData.h"

@class SCSMessageActorViewModel;

@interface SCSMessageTextViewModel : NSObject <SCSMessageContentData>

@property (nonatomic, copy, readonly) NSString *text;
@property (nonatomic, strong, readonly) SCSMessageActorViewModel *actor;
@property (nonatomic, getter=isLocalUser, readonly) BOOL localUser;

- (instancetype)initWithMessageText:(NSString*)messageText itemId:(NSString*)itemId localUser:(BOOL)isLocaluser actor:(SCSMessageActorViewModel*)actor timestamp:(NSDate*)timestamp;

@end
