//
//  SCSMessagingCollectionViewCellAttributes.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Class used for caching values returned by the SCSMessagingCollectionViewDelegateFlowLayout
 */
@interface SCSMessagingCollectionViewCellAttributes : NSObject

/**
 Cell insets for the distance between individual collection view cells and screen edge.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:cellInsetsAtIndexPath:`
 */
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 Size of the text view inside of the cell.
 
 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:sizeForTextAtIndexPath:withMaxWidth:`
 */
@property (nonatomic, assign) CGSize textViewSize;

/**
 Size of the custom view inside of the cell.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:sizeForCustomViewAtIndexPath:withWidth:`
 */
@property (nonatomic, assign) CGSize customViewSize;

/**
 Height of the timestamp view inside of the cell.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:heightForTimestampAtIndexPath:`
 */
@property (nonatomic, assign) CGFloat timestampHeight;

/**
 Size of the upper info text view inside of the cell.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:sizeForUpperInfoTextViewAtIndexPath:withWidth:`
 */
@property (nonatomic, assign) CGSize upperInfoTextSize;

/**
 Size of the lower info text view inside of the cell.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:sizeForLowerInfoTextViewAtIndexPath:withWidth:`
 */
@property (nonatomic, assign) CGSize lowerInfoTextSize;

/**
 Flag determining if the cell supports an avatar image.

 Acquired via `SCSMessagingCollectionViewDelegateFlowLayout collectionView:supportsAvatarForCellAtIndexPath:`
 */
@property (nonatomic, assign) BOOL supportsAvatarImage;


@property (nonatomic, assign) CGSize actionableSystemSize;

@end
