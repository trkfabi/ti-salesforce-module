//
//  SCSTextView.h
//  CaseUI
//
//  Created by Amisha Goyal on 5/18/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSTextView : UITextView

@property (strong, nonatomic) UIFont *textViewFont UI_APPEARANCE_SELECTOR;

// This property is needed, setting the background colour with the standard apperance selector is not working on iOS 9 & 10.
// This can be removed and updated in the ViewController setting the background colour once iOS 9 & 10 are no longer supported.
// In SCSMessagingCollectionViewController change:
// [SCSTextView appearanceWhenContainedInInstancesOfClasses:@[[SCSMessagingInputView class]]].textViewBackgroundColor = [UIColor clearColor];
//   to:
//[SCSTextView appearanceWhenContainedInInstancesOfClasses:@[[SCSMessagingInputView class]]].backgroundColor = [UIColor clearColor];
@property (strong, nonatomic) UIColor *textViewBackgroundColor UI_APPEARANCE_SELECTOR;

@end
