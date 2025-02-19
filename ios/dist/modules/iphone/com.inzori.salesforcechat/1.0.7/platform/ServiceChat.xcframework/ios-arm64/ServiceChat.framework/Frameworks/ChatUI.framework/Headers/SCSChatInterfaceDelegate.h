//
//  SCSChatInterfaceDelegate.h
//  ChatUI
//
//  Created by Jeremy Wright on 2021-11-23.
//  Copyright © 2021 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCSChatInterface;

@protocol SCSChatInterfaceDelegate <NSObject>
@required

/**
 Tells the delegate when a user interacts with a chat element representing an app event.

 @param interface The Chat Interface instance corresponding to this event.
 @param URL the configured URL associated with the App Event.
 */
- (void)interface:(__weak SCSChatInterface *)interface didReceiveAppEventWithURL:(NSURL *)URL;
@end
