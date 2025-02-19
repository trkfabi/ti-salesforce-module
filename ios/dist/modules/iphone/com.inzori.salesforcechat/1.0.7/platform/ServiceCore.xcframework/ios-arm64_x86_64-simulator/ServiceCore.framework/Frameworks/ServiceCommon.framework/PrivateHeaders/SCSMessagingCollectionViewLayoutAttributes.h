//
//  SCSMessagingCollectionViewLayoutAttributes.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-08-02.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SCSMessagingCollectionViewLayoutAttributes : UICollectionViewLayoutAttributes

@property (nonatomic, assign) UIEdgeInsets bubbleTextInsets;
@property (nonatomic, assign) UIEdgeInsets cellInsets;

@property (nonatomic, assign) CGFloat bubbleWidth;
@property (nonatomic, assign) CGFloat textViewHeight;
@property (nonatomic, assign) CGFloat customViewHeight;

@property (nonatomic, assign) CGFloat timestampHeight;
@property (nonatomic, assign) UIEdgeInsets timestampInsets;
@property (nonatomic, assign) CGSize upperInfoSize;
@property (nonatomic, assign) UIEdgeInsets upperInfoInsets;
@property (nonatomic, assign) CGSize lowerInfoSize;
@property (nonatomic, assign) UIEdgeInsets lowerInfoInsets;
@property (nonatomic, assign) CGFloat avatarAlpha;
@property (nonatomic, assign) UIEdgeInsets avatarInsets;
@property (nonatomic, assign) CGSize avatarSize;
@property (nonatomic, assign) CGFloat separatorHeight;
@property (nonatomic, assign) CGFloat progressHeight;
@property (nonatomic, assign) CGSize actionableSystemSize;

@end
