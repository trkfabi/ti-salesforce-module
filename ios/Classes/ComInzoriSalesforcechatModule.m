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

  NSString *podName = [TiUtils stringValue:@"podName" properties:args];
  NSString *orgId = [TiUtils stringValue:@"orgId" properties:args];
  NSString *deploymentId = [TiUtils stringValue:@"deploymentId" properties:args];
  NSString *buttonId = [TiUtils stringValue:@"buttonId" properties:args];

  NSString *firstName = [TiUtils stringValue:@"firstName" properties:args def:@""];
  NSString *lastName = [TiUtils stringValue:@"lastName" properties:args def:@""];
  NSString *email = [TiUtils stringValue:@"email" properties:args def:@""];
  NSString *subject = [TiUtils stringValue:@"subject" properties:args def:@""];
  NSString *phone = [TiUtils stringValue:@"phone" properties:args def:@""];
  NSString *caseOrigin = [TiUtils stringValue:@"caseOrigin" properties:args def:@""];
    
  BOOL defaultToMinimized = [TiUtils boolValue:@"defaultToMinimized" properties:args def:YES];
  BOOL allowMinimization = [TiUtils boolValue:@"allowMinimization" properties:args def:YES];
  BOOL allowURLPreview = [TiUtils boolValue:@"allowURLPreview" properties:args def:YES];
  BOOL showPrechatFields = [TiUtils boolValue:@"showPrechatFields" properties:args def:NO];
  BOOL createSalesforceCase = [TiUtils boolValue:@"createSalesforceCase" properties:args def:NO];

  SCSChatConfiguration *config =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod:podName
                                                orgId:orgId
                                          deploymentId:deploymentId
                                              buttonId:buttonId
    ];

  config.visitorName = [NSString stringWithFormat:@"%@ %@", firstName, lastName];                                  
  config.defaultToMinimized = defaultToMinimized;
  config.allowURLPreview = allowURLPreview;
  config.allowMinimization = allowMinimization;
  // Change from queue position to estimated wait time
  //config.queueStyle = SCSChatConfigurationQueueStyleEstimatedWaitTime;

  // Create pre-chat fields
  SCSPrechatObject* firstNameField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"First Name"
                                    value:firstName];
  SCSPrechatObject* lastNameField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"Last Name"
                                    value:lastName];                                    
  SCSPrechatObject* emailField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"Email"
                                    value:email];
  SCSPrechatObject* subjectField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"Subject"
                                    value:subject];
  SCSPrechatObject* phoneField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"Phone"
                                    value:phone];
  SCSPrechatObject* originField = [[SCSPrechatObject alloc]
                                      initWithLabel:@"Case Origin"
                                      value:caseOrigin];
  // Create entity fields
  SCSPrechatEntityField* firstNameEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"FirstName" label:@"First Name"];
  firstNameEntityField.doFind = YES;
  firstNameEntityField.doCreate = YES;
  firstNameEntityField.isExactMatch = YES;

  SCSPrechatEntityField* lastNameEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"LastName" label:@"Last Name"];
  lastNameEntityField.doFind = YES;
  lastNameEntityField.doCreate = YES;
  lastNameEntityField.isExactMatch = YES;

  SCSPrechatEntityField* emailEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"Email" label:@"Email"];
  emailEntityField.doFind = YES;
  emailEntityField.doCreate = YES;
  emailEntityField.isExactMatch = YES;

  SCSPrechatEntityField* phoneEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"Phone" label:@"Phone"];
  phoneEntityField.doFind = YES;
  phoneEntityField.doCreate = YES;
  phoneEntityField.isExactMatch = YES;
    
  // Create an entity object
  SCSPrechatEntity* contactEntity = [[SCSPrechatEntity alloc]
                                    initWithEntityName:@"Contact"];
  contactEntity.saveToTranscript = @"Contact";
  contactEntity.linkToEntityName = @"Case";
  contactEntity.linkToEntityField = @"ContactId";                                  
  contactEntity.showOnCreate = YES;

  // Create an entity mapping for a Contact record type
  [contactEntity.entityFieldsMaps addObject:firstNameEntityField];
  [contactEntity.entityFieldsMaps addObject:lastNameEntityField];
  [contactEntity.entityFieldsMaps addObject:emailEntityField];
  [contactEntity.entityFieldsMaps addObject:phoneEntityField];

  if (createSalesforceCase) {
      // Create an entity mapping for a Case record type
      SCSPrechatEntity* caseEntity = [[SCSPrechatEntity alloc]
                                      initWithEntityName:@"Case"];
      caseEntity.saveToTranscript = @"Case";
      caseEntity.showOnCreate = YES;
      
      // Add one field mappings to our Case entity
      SCSPrechatEntityField* subjectEntityField = [[SCSPrechatEntityField alloc]
                                                   initWithFieldName:@"Subject" label:@"Subject"];
      subjectEntityField.doCreate = YES;
      [caseEntity.entityFieldsMaps addObject:subjectEntityField];
      
      SCSPrechatEntityField* originEntityField = [[SCSPrechatEntityField alloc]
                                                  initWithFieldName:@"Origin" label:@"Case Origin"];
      originEntityField.doCreate = YES;
      [caseEntity.entityFieldsMaps addObject:originEntityField];
      
      // Update config object with the entity mappings
      config.prechatEntities = @[contactEntity, caseEntity];

  } else {
    // Update config object with the entity mappings
    config.prechatEntities = @[contactEntity];
  }

  // Update config object with the pre-chat fields
  config.prechatFields = @[firstNameField, lastNameField, emailField, phoneField, subjectField, originField];

  SCAppearanceConfiguration *appearance = [SCAppearanceConfiguration new];
  [appearance setColor:[self colorFromHexString:@"#FFFFFF"]
              forName:SCSAppearanceColorTokenNavbarBackground];

  [appearance setColor:[self colorFromHexString:@"#02B3E4"]
              forName:SCSAppearanceColorTokenNavbarInverted];

  [appearance setColor:[self colorFromHexString:@"#02B3E4"]
              forName:SCSAppearanceColorTokenBrandPrimary];

  // Add delegates
  [[SCServiceCloud sharedInstance].chatCore addDelegate:self];
  [SCServiceCloud sharedInstance].appearanceConfiguration = appearance;

// Start the session

  if (showPrechatFields) {
    NSLog(@"[INFO] show with PreChat fields");
    [[SCServiceCloud sharedInstance].chatUI showChatWithConfiguration:config showPrechat: YES];
  } else {
    NSLog(@"[INFO] show without PreChat fields");
    [[SCServiceCloud sharedInstance].chatUI showChatWithConfiguration:config];
  }
}

// Assumes input like "#00FF00" (#RRGGBB).
- (UIColor *)colorFromHexString:(NSString *)hexString {
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:hexString];
    [scanner setScanLocation:1]; // bypass '#' character
    [scanner scanHexInt:&rgbValue];
    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16)/255.0 green:((rgbValue & 0xFF00) >> 8)/255.0 blue:(rgbValue & 0xFF)/255.0 alpha:1.0];
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
