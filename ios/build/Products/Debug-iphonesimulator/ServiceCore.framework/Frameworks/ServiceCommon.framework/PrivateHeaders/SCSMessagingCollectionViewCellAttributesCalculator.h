//
//  SCSMessagingCollectionViewCellSizeCalculator.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SCSMessagingCollectionViewFlowLayout;
@class SCSMessagingCollectionViewCellAttributes;

NS_ASSUME_NONNULL_BEGIN

/**
 Object responsible for calling the `SCSMessagingCollectionViewDelegateFlowLayout` and calculating
 the size of the message feed cells.
 */
@interface SCSMessagingCollectionViewCellAttributesCalculator : NSObject

/**
 Designated initializer that takes a layout object

 @param layout The layout for which the calculator is caching values
 @return SCSMessagingCollectionViewCellAttributesCalculator instance
 */
- (instancetype)initWithLayout:(SCSMessagingCollectionViewFlowLayout *)layout NS_DESIGNATED_INITIALIZER;

/**
 Computes and returns an instance of `SCSMessagingCollectionViewCellAttributes` containing the information
 acquired from the `SCSMessagingCollectionViewDelegateFlowLayout` instance set on the `SCSMessagingCollectionViewFlowLayout`

 @param hash The unique hash for the data at the specified indexPath
 @param indexPath The index path of the cell being laid out in the collection view
 @return SCSMessagingCollectionViewCellAttributes instance containing the calculated cell attributes
 */
- (SCSMessagingCollectionViewCellAttributes *)cellAttributesForItemWithHash:(NSUInteger)hash
                                                                atIndexPath:(NSIndexPath *)indexPath;

/**
 Notifies the cell calculator that the layout will be reset.
 This method is used to clear any cached layout information, if necessary.
 */
- (void)prepareForResetting;

/**
 Notifies the cell calculator that the layout will be reset for the given hash value.
 */
- (void)prepareForResettingForItemWithHash:(NSUInteger)hash;

/**
 The layout for which size calculations and caching are being performed.
 */
@property (nonatomic, weak, readonly) SCSMessagingCollectionViewFlowLayout *layout;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
