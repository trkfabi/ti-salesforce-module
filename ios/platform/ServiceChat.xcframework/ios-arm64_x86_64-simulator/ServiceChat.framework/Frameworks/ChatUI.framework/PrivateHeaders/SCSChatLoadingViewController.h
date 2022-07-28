//
//  SCSChatLoadingViewController.h
//  ChatUI
//
//  Created by Thomas Myrden on 2016-08-08.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SCSChatInterfaceFlow;
@interface SCSChatLoadingViewController : UIViewController

- (instancetype)initWithInterfaceFlow:(NSObject<SCSChatInterfaceFlow>*)interfaceFlow;

@end
