//
//  SCTestItem.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 1/11/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifdef DEBUG
NS_ASSUME_NONNULL_BEGIN
/**
 Convenience class for representing rows of testable actions within a test view controller.
 */
@interface SCTestItem<__covariant ObjectType> : NSObject

/**
 Title to display for this item.
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 Designated initializer to construct a test item.

 @param title Title to display in the table.
 @param testBlock Block to invoke when this action is selected.
 @return Initialized item.
 */
- (instancetype)initWithTitle:(NSString*)title block:(ObjectType(^)(NSIndexPath *indexPath))testBlock;

/**
 Method invoked when this item is selected to return an optional view controller to present.

 @param indexPath Index path selected.
 @return Item to present, or `nil` to not display anything.
 */
- (nullable __kindof ObjectType)objectAtIndexPath:(NSIndexPath*)indexPath;
- (nullable __kindof ObjectType)viewControllerAtIndexPath:(NSIndexPath*)indexPath __deprecated_msg("Use objectAtIndexPath");

@end
NS_ASSUME_NONNULL_END
#endif
