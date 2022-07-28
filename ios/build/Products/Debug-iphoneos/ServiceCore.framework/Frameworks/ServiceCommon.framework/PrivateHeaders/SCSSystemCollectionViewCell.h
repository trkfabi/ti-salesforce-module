//
//  SCSSystemCollectionViewCell.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-08-04.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSSystemCollectionViewCell : UICollectionViewCell

@property (nonatomic, weak, readonly) UITextView *textView;

@property (nonatomic, strong) UIColor *separatorColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *textViewFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *textViewTextColor UI_APPEARANCE_SELECTOR;

@end
