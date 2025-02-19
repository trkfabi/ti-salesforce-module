//
//  SCSMessagingCollectionViewFlowLayoutInvalidationContext.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCSMessagingCollectionViewFlowLayoutInvalidationContext : UICollectionViewFlowLayoutInvalidationContext

/**
 Value indicating whether to empty the messages layout cache for items and views in the layout.

 Default: NO
 */
@property (nonatomic, assign) BOOL invalidateMessagesCache;

/**
 Creates and returns a new `SCSMessagingCollectionViewFlowLayoutInvalidationContext` object.

 @return SCSMessagingCollectionViewFlowLayoutInvalidationContext instance
 */
+ (instancetype)context;

@end

NS_ASSUME_NONNULL_END
