//
//  SCSMessagingCollectionViewFlowLayout.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSMessagingCollectionViewCellAttributesCalculator.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCSMessagingCollectionViewDelegateFlowLayout <UICollectionViewDelegateFlowLayout>

/**
 Required delegate method returning the minimum necessary size of the text view to contain the text for the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @param width The maximum width the text view will be allowed to be inside the layout
 @return CGSize representing the text view bounds
 */
- (CGSize)collectionView:(UICollectionView *)collectionView sizeForTextAtIndexPath:(NSIndexPath *)indexPath withMaxWidth:(CGFloat)width;

/**
 Required delegate method returning the necessary size of the custom view for the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @param width The maximum width the custom view will be allowed to be inside the layout
 @return CGSize representing the custom view dimensions
 */
- (CGSize)collectionView:(UICollectionView *)collectionView sizeForCustomViewAtIndexPath:(NSIndexPath *)indexPath withWidth:(CGFloat)width;

/**
 Required delegate method returning the unique hash for the item at the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @return NSUInteger representing the unique hash for the data at the specified indexPath
 */
- (NSUInteger)collectionView:(UICollectionView *)collectionView hashForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

/**
 Optional delegate method returning the height of the timestamp for the cell at the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view

 @return CGFloat height value for the text view (0.0f will be assumed)
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView heightForTimestampAtIndexPath:(NSIndexPath *)indexPath;

/**
 Optional delegate method returning the height of the upper info label for the cell at the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @param width The maximum width the image will be allowed to be inside the layout
 @return CGFloat height value for the text view (0.0f will be assumed)
 */
- (CGSize)collectionView:(UICollectionView *)collectionView sizeForUpperInfoLabelAtIndexPath:(NSIndexPath *)indexPath withWidth:(CGFloat)width;

/**
 Optional delegate method returning the height of the lower info label for the cell at the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @param width The maximum width the image will be allowed to be inside the layout
 @return CGFloat height value for the text view (0.0f will be assumed)
 */
- (CGSize)collectionView:(UICollectionView *)collectionView sizeForLowerInfoLabelAtIndexPath:(NSIndexPath *)indexPath withWidth:(CGFloat)width;

- (CGSize)collectionView:(UICollectionView *)collectionView sizeForActionableSystemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Optional delegate method returning a determination of whether the cell at the given index path supports an avatar.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @return BOOL value determining if the cell supports an avatar (NO will be assumed)
 */
- (BOOL)collectionView:(UICollectionView *)collectionView supportsAvatarForCellAtIndexPath:(nullable NSIndexPath *)indexPath;

/**
 Optional delegate method returning the visibility of the image to be used as the avatar for the cell at the given index path.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @return CGFloat alpha of the avatar for use at the index path (0.0f will be assumed)
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView avatarAlphaAtIndexPath:(NSIndexPath *)indexPath;

/**
 Optional delegate method for modifying the cell insets on a per cell basis instead of using the layout defaults.

 @param collectionView The collection view the delegate is requesting information for
 @param indexPath The index path of the cell being laid out in the collection view
 @return UIEdgeInsets of the cell at the index path (Layout's cellInsets value will be assumed)
 */
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView cellInsetsAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface SCSMessagingCollectionViewFlowLayout : UICollectionViewFlowLayout

/**
 The object that the layout uses to calculate bubble sizes.
 Default: Instance of `SCSMessagingCollectionViewCellAttributesCalculator`
 */
@property (nonatomic, strong, readonly) SCSMessagingCollectionViewCellAttributesCalculator *cellAttributesCalculator;

/**
 Returns the width of items in the collection view layout.
 */
@property (readonly, nonatomic) CGFloat itemWidth;

/**
 Ratio of the message bubble width to screen width.
 Default: (2.0f / 3.0f)
 */
@property (nonatomic, assign) CGFloat bubbleWidthRatio;

/**
 Text container insets for the text inside of the message bubble.
 Default: {8, 6, 8, 6}
 */
@property (nonatomic, assign) UIEdgeInsets bubbleTextInsets;

/**
 Cell insets for the distance between individual collection view cells and screen edge.
 Default: {5, 5, 5, 5}
 */
@property (nonatomic, assign) UIEdgeInsets cellInsets;

/**
 Timestamp text insets for providing distance between top of the cell and the next item in the cell.
 Default: {0, 0, 0, 0}
 */
@property (nonatomic, assign) UIEdgeInsets timestampInsets;

/**
 Upper info text insets for providing distance between top of the cell or timestamp and the next item in the cell.
 Default: {0, 0, 2, 0}
 */
@property (nonatomic, assign) UIEdgeInsets upperInfoInsets;

/**
 Lower info text insets for providing distance between bottom of the bubble and the bottom of the cell.
 Default: {2, 0, 0, 0}
 */
@property (nonatomic, assign) UIEdgeInsets lowerInfoInsets;

/**
 Avatar insets for providing spacing for the avatar between the edge of the cell and the message bubble.
 Default: {0, 5, 0, 8}
 */
@property (nonatomic, assign) UIEdgeInsets avatarInsets;

/**
 Avatar image size, if image is supported for the cell.
 Default: {35.0f, 35.0f}
 */
@property (nonatomic, assign) CGSize avatarSize;

/**
 Height of the system message separator bar.
 Default: 1.0f
 */
@property (nonatomic, assign) CGFloat separatorHeight;

/**
 Height of the outgoing message progress bar.
 Default: 2.0f
 */
@property (nonatomic, assign) CGFloat progressHeight;

@property (nonatomic, assign) CGSize actionableSystemSize;

/**
 Computes and returns the size of the item at the specified indexPath.

 @param indexPath The index path of the cell being laid out in the collection view
 @return CGSize representing the overall cell dimensions
 */
- (CGSize)sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)resetLayoutAtIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
