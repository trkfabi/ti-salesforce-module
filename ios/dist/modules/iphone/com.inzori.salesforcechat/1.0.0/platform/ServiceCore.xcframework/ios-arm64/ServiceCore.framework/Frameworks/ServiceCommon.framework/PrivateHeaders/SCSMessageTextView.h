//
//  SCSMessageTextView.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2016-10-06.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSMessageTextView : UITextView

@property (strong, nonatomic) UIFont *textViewFont UI_APPEARANCE_SELECTOR;

@property (strong, nonatomic) UIColor *textViewFontColor UI_APPEARANCE_SELECTOR;

@property (strong, nonatomic) UIColor *textViewLinkColor UI_APPEARANCE_SELECTOR;

@end
