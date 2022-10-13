//
//  SCSBadgeView.h
//  CaseUI
//
//  Created by Amisha Goyal on 1/18/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSBadgeView : UIView

@property (nonatomic, strong, readonly) UILabel *textLabel;

@property (nonatomic, strong) UIImage *badgeImage UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIColor *badgeColor UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIColor *labelTextColor UI_APPEARANCE_SELECTOR;

@end
