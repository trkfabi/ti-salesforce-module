//
//  UILabel+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 1/18/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (ServiceCommon)

@property (null_resettable, nonatomic, strong) UIFont *appearanceFont UI_APPEARANCE_SELECTOR;
@property (null_resettable, nonatomic, strong) UIColor *appearanceTextColor UI_APPEARANCE_SELECTOR;

@end
