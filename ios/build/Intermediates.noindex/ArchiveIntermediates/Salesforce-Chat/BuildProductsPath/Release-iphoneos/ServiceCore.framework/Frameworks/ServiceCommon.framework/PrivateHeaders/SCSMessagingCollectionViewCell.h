//
//  SCSMessagingCollectionViewCell.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-08-10.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCSMessageTextView;
@interface SCSMessagingCollectionViewCell : UICollectionViewCell

@property (nonatomic, readonly) UIView *bubbleView;
@property (nonatomic, readwrite) UIView *customView;
@property (nonatomic, readonly) SCSMessageTextView *bubbleTextView;
@property (nonatomic, readonly) UITextView *timestampTextView;
@property (nonatomic, readonly) UITextView *upperInfoTextView;
@property (nonatomic, readonly) UITextView *lowerInfoTextView;
@property (nonatomic, readonly) UIImageView *avatarView;
@property (nonatomic, readonly) UIView *avatarWrapperView;

@property (nonatomic, strong) UIColor *bubbleColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *bubbleColorAlternate UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *timestampFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *timestampTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *upperInfoFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *upperInfoTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *lowerInfoFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *lowerInfoTextColor UI_APPEARANCE_SELECTOR;

- (void)setupViews NS_REQUIRES_SUPER;
- (void)setCellAlternateMessageColor;
- (void)setCellDefaultMessageColor;

@end
