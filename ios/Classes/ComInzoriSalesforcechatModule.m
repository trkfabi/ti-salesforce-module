/**
 * Salesforce-Chat
 *
 * Created by Your Name
 * Copyright (c) 2022 Your Company. All rights reserved.
 */

#import "ComInzoriSalesforcechatModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"
//#import <ServiceCore/ServiceCore.h>
//#import <ServiceChat/ServiceChat.h>
@import ServiceCore;
@import ServiceChat;

@implementation ComInzoriSalesforcechatModule

#pragma mark Internal

// This is generated for your module, please do not change it
- (id)moduleGUID
{
  return @"c5f08867-d3c7-470a-9ecc-dad3853fefcf";
}

// This is generated for your module, please do not change it
- (NSString *)moduleId
{
  return @"com.inzori.salesforcechat";
}

#pragma mark Lifecycle

- (void)startup
{
  // This method is called when the module is first loaded
  // You *must* call the superclass
  [super startup];
  DebugLog(@"[DEBUG] %@ loaded", self);
}

#pragma Public APIs


- (void)launchChat:(id)args
{
  ENSURE_SINGLE_ARG(args, NSDictionary);

  NSString *podName;
  NSString *orgId;
  NSString *deploymentId;
  NSString *buttonId;
  NSString *visitorName;
  BOOL defaultToMinimized;
  BOOL allowMinimization;
  BOOL allowURLPreview;

  ENSURE_ARG_OR_NIL_FOR_KEY(podName, args, @"podName", NSString);
  ENSURE_ARG_OR_NIL_FOR_KEY(orgId, args, @"orgId", NSString);
  ENSURE_ARG_OR_NIL_FOR_KEY(deploymentId, args, @"deploymentId", NSString);
  ENSURE_ARG_OR_NIL_FOR_KEY(buttonId, args, @"buttonId", NSString);    
  ENSURE_ARG_OR_NIL_FOR_KEY(visitorName, args, @"visitorName", NSString);    
  ENSURE_INT_OR_NIL_FOR_KEY(defaultToMinimized, args, @"defaultToMinimized", defaultToMinimized);    
  ENSURE_INT_OR_NIL_FOR_KEY(allowURLPreview, args, @"allowURLPreview", allowURLPreview);    
  ENSURE_INT_OR_NIL_FOR_KEY(allowMinimization, args, @"allowMinimization", allowMinimization);    

  SCSChatConfiguration *config =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod:podName
                                                orgId:orgId
                                          deploymentId:deploymentId
                                              buttonId:buttonId
    ];

  config.visitorName = visitorName;                                              
  config.defaultToMinimized = defaultToMinimized ? @"YES": @"NO";
  config.allowURLPreview = allowURLPreview ? @"YES": @"NO";
  config.allowMinimization = allowMinimization ? @"YES": @"NO";

  // Add delegates
  [[SCServiceCloud sharedInstance].chatCore addDelegate:self];
    
  // Start the session
  [[SCServiceCloud sharedInstance].chatUI showChatWithConfiguration:config];
}


#pragma mark - SCSChatSessionDelegate
  
- (void)session:(id<SCSChatSession>)session didTransitionFromState:(SCSChatSessionState)previous toState:(SCSChatSessionState)current {
    NSString *code = @"UNKNOWN";
    switch(current) {
      case SCSChatSessionStateInactive:
        code = @"INACTIVE";
        break;
      case SCSChatSessionStateConnecting:
        code = @"CONNECTING";
        break;        
      case SCSChatSessionStateQueued:
        code = @"QUEUED";
        break;      
      case SCSChatSessionStateConnected:
        code = @"CONNECTED";
        break;      
      case SCSChatSessionStateEnding:
        code = @"ENDING";
        break;             
                        
    }
    NSDictionary *event = [NSDictionary dictionaryWithObjectsAndKeys:
                            code,@"state",
                            nil];    
    [self fireEvent:@"salesforce_chat:session_state" withObject:event];
}

- (void)session:(id<SCSChatSession>)session didEnd:(SCSChatSessionEndEvent *)endEvent {
    NSString *code = @"UNKNOWN";
    switch(endEvent.reason) {
      case SCSChatEndReasonUser:
        NSLog(@"[INFO] Session was ended due to user interaction.");
        code = @"USER";
        break;
      case SCSChatEndReasonAgent:
        NSLog(@"[INFO] Session was ended remotely by the agent.");
        code = @"AGENT";
        break;
      case SCSChatEndReasonNoAgentsAvailable:
        NSLog(@"[INFO] Session was ended as a result of no agents being available.");
        code = @"NOAGENTSAVAILABLE";
        break;
      case SCSChatEndReasonTimeout:
        NSLog(@"[INFO] Session was ended due to a network disruption resulting in a timeout.");
        code = @"TIMEOUT";
        break;
      case SCSChatEndReasonSessionError:
        NSLog(@"[INFO] Session was ended as the result of a fatal error.");
        code = @"ERROR";
        break;
                        
    }
    NSDictionary *event = [NSDictionary dictionaryWithObjectsAndKeys:
                            code,@"reason",
                            nil];    
    [self fireEvent:@"salesforce_chat:session_end" withObject:event];    
}

- (void)session:(id<SCSChatSession>)session didError:(NSError *)error fatal:(BOOL)fatal {
    NSLog(@"[INFO] didError: %@", error.localizedDescription);
    NSDictionary *event = [NSDictionary dictionaryWithObjectsAndKeys:
                            error.localizedDescription,@"error", 
                            nil];    
    [self fireEvent:@"salesforce_chat:session_error" withObject:event];     
}

- (void)session:(id<SCSChatSession>)session
    didUpdateQueuePosition:(NSNumber *)position
         estimatedWaitTime:(NSNumber *)waitTime {

    NSLog(@"[INFO] didUpdateQueuePosition: %d estimatedWaitTime: %d", [position intValue], [waitTime intValue]);
    

};

- (void)session:(id<SCSChatSession>)session didUpdateQueuePosition:(NSNumber *)position {
          NSLog(@"[INFO] didUpdateQueuePosition: %d", [position intValue]);
  
};

@end
