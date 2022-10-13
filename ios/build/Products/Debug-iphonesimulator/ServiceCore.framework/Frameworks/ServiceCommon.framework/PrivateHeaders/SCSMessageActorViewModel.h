//
//  SCSMessageActorViewModel.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/28/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SCSContentData.h"

@interface SCSMessageActorViewModel : NSObject <SCSContentData>

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, strong, readonly) UIImage *avatarImage;

-(instancetype)initWithName:(NSString*)actorName actorId:(NSString*)actorId withImage:(UIImage*)actorImage;

@end
