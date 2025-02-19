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

  NSString *cpf = [TiUtils stringValue:@"cpf" properties:args def:@""];
  NSString *firstName = [TiUtils stringValue:@"firstName" properties:args def:@""];
  NSString *channel = [TiUtils stringValue:@"channel" properties:args def:@""];
  NSString *contactOrigin = [TiUtils stringValue:@"contactOrigin" properties:args def:@""];
  NSString *chatOrigin = [TiUtils stringValue:@"chatOrigin" properties:args def:@""];
  NSString *originQueue = [TiUtils stringValue:@"originQueue" properties:args def:@""];
  NSString *product = [TiUtils stringValue:@"product" properties:args def:@""];
  NSString *customerId = [TiUtils stringValue:@"customerId" properties:args def:@""];
  NSString *customerDoc = [TiUtils stringValue:@"customerDoc" properties:args def:@""];
    
  BOOL defaultToMinimized = [TiUtils boolValue:@"defaultToMinimized" properties:args def:YES];
  BOOL allowMinimization = [TiUtils boolValue:@"allowMinimization" properties:args def:YES];
  BOOL allowURLPreview = [TiUtils boolValue:@"allowURLPreview" properties:args def:YES];
  BOOL showPrechatFields = [TiUtils boolValue:@"showPrechatFields" properties:args def:NO];
  BOOL debug = [TiUtils boolValue:@"debug" properties:args def:NO];
  
   NSLog(@"[WARN] %@", args);
//  NSLog(@"[WARN] FirstName: %@ - LastName: %@ - Email: %@ - Phone: %@ - Subject: %@ - Origin: %@",
//        firstName, lastName, email, phone, subject, caseOrigin);
    
    if (debug) {
       // NSLog(@"[INFO] enable livechat logger");
        [SCServiceLogger sharedLogger].level = SCSLoggerLevelDebug;
    }
    
  SCSChatConfiguration *config =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod:podName
                                                orgId:orgId
                                          deploymentId:deploymentId
                                              buttonId:buttonId
    ];

  config.visitorName = [NSString stringWithFormat:@"%@", firstName];                                  
  config.defaultToMinimized = defaultToMinimized;
  config.allowURLPreview = allowURLPreview;
  config.allowMinimization = allowMinimization;
  // Change from queue position to estimated wait time
  //config.queueStyle = SCSChatConfigurationQueueStyleEstimatedWaitTime;

  // Create pre-chat fields
  SCSPrechatObject* cpfField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"CPF"
                                    value:cpf];
  SCSPrechatObject* channelField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"Channel"
                                    value:channel];                                    
  SCSPrechatObject* contactOriginField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"ContactOrigin"
                                    value:contactOrigin];
  SCSPrechatObject* chatOriginField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"ChatOrigin"
                                    value:chatOrigin];
  SCSPrechatObject* originQueueField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"OriginQueue"
                                    value:originQueue];                                    
  SCSPrechatObject* productField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"BU"
                                    value:product];
  SCSPrechatObject* customerIdField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"CustomerId"
                                    value:customerId];
  SCSPrechatObject* customerDocField = [[SCSPrechatObject alloc] 
                                    initWithLabel:@"CustomerDoc"
                                    value:customerDoc];

  // Create entity fields
  SCSPrechatEntityField* cpfEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"Numdoc__c" label:@"CPF"];
  cpfEntityField.doFind = YES;
  cpfEntityField.isExactMatch = YES;
  cpfEntityField.doCreate = NO;

  SCSPrechatEntityField* channelEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"Channel__c" label:@"Channel"];
  channelEntityField.doFind = NO;
  channelEntityField.isExactMatch = NO;
  channelEntityField.doCreate = YES;

  SCSPrechatEntityField* contactOriginEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"ContactOrigin__c" label:@"ContactOrigin"];
  contactOriginEntityField.doFind = NO;
  contactOriginEntityField.isExactMatch = NO;
  contactOriginEntityField.doCreate = YES;

  SCSPrechatEntityField* chatOriginEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"ChatOrigin__c" label:@"ChatOrigin"];
  chatOriginEntityField.doFind = NO;
  chatOriginEntityField.isExactMatch = NO;
  chatOriginEntityField.doCreate = YES;

  SCSPrechatEntityField* originQueueEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"OriginQueue__c" label:@"OriginQueue"];
  originQueueEntityField.doFind = NO;
  originQueueEntityField.isExactMatch = NO;
  originQueueEntityField.doCreate = YES;

  SCSPrechatEntityField* productEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"BU__c" label:@"BU"];
  productEntityField.doFind = NO;
  productEntityField.isExactMatch = NO;
  productEntityField.doCreate = YES;

  SCSPrechatEntityField* customerIdEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"Customer__c" label:@"CustomerId"];
  customerIdEntityField.doFind = NO;
  customerIdEntityField.isExactMatch = NO;
  customerIdEntityField.doCreate = YES;

  SCSPrechatEntityField* customerDocEntityField = [[SCSPrechatEntityField alloc]
    initWithFieldName:@"NumeroDocumento__c" label:@"CustomerDoc"];
  customerDocEntityField.doFind = NO;
  customerDocEntityField.isExactMatch = NO;
  customerDocEntityField.doCreate = YES;

  // Create an entity object
  SCSPrechatEntity* accountEntity = [[SCSPrechatEntity alloc]
                                    initWithEntityName:@"Account"];
  accountEntity.saveToTranscript = @"AccountId";

  // Create an entity mapping for a Account record type
  [accountEntity.entityFieldsMaps addObject:cpfEntityField];

  // Create an entity object
  SCSPrechatEntity* protocolEntity = [[SCSPrechatEntity alloc]
                                    initWithEntityName:@"Protocolo__c"];
  protocolEntity.saveToTranscript = @"Protocol__c";                           
  protocolEntity.showOnCreate = YES;

  // Create an entity mapping for a Protocol record type
  [protocolEntity.entityFieldsMaps addObject:channelEntityField];
  [protocolEntity.entityFieldsMaps addObject:contactOriginEntityField];
  [protocolEntity.entityFieldsMaps addObject:chatOriginEntityField];
  [protocolEntity.entityFieldsMaps addObject:originQueueEntityField];
  [protocolEntity.entityFieldsMaps addObject:productEntityField];
  [protocolEntity.entityFieldsMaps addObject:customerIdEntityField];
  [protocolEntity.entityFieldsMaps addObject:customerDocEntityField];

  // Update config object with the entity mappings
  config.prechatEntities = @[accountEntity, protocolEntity];

  // Update config object with the pre-chat fields
  NSMutableArray<SCSPrechatObject *> *preChatFields = [NSMutableArray new];
  [preChatFields addObject:cpfField];
  [preChatFields addObject:channelField];
  [preChatFields addObject:contactOriginField];
  [preChatFields addObject:chatOriginField];
  [preChatFields addObject:originQueueField];
  [preChatFields addObject:productField];
  [preChatFields addObject:customerIdField];
  [preChatFields addObject:customerDocField];
  config.prechatFields = preChatFields;

  //config.prechatFields = @[cpfField, channelField, contactOriginField, chatOriginField, originQueueField, productField, customerIdField];

  //NSLog(@"[WARN] config: %@", config.prechatFields);em
    
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

- (void)dismissChat:(id)args {
    [[SCServiceCloud sharedInstance].chatUI dismissChat];
}
- (void)maximize:(id)args {
    [[SCServiceCloud sharedInstance].chatUI maximize];
}
- (void)minimize:(id)args {
    [[SCServiceCloud sharedInstance].chatUI minimize];
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
