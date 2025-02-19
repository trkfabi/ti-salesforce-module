//
//  SCSLoading.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 3/16/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Generic protocol for defining loading indicators.
 */
@protocol SCSLoading <NSObject>

@property (nonatomic) BOOL hidesWhenStopped;

- (void)startAnimating;
- (void)stopAnimating;

@end

@interface UIActivityIndicatorView () <SCSLoading>
@end