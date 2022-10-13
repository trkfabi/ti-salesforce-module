//
//  SCSLiveAgentHandoverDelegate.h
//  ServiceCommon
//
//  Created by Jeremy Wright on 5/10/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SCSLiveAgentHandoverDelegate <NSObject>

- (void)liveAgentHandoverDidCompleteWithAffinity:(NSString *)affinity resetSequence:(BOOL)resetSequence;

@end
