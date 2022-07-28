//
//  SCSDAteTimeViewCell.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/24/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Container view to wrap [SCSDateTimeViewCell dateTimeLabel]. This allows appearance selectors to be applied to the appropriate subview.
 */
@interface SCSDateTimeLabelContentView: UIView @end

@interface SCSDateTimeViewCell : UITableViewCell

/**
 Label for the Date/Time string.
 */
@property (nonatomic, strong, readonly) UILabel *dateTimeLabel;

@end

@interface SCSDateTimeViewCell (UIAppearance)

/**
 Edge insets from the outside edge of the cell to the contents.
 */
@property (nonatomic, assign) IBInspectable UIEdgeInsets outerInsets UI_APPEARANCE_SELECTOR;

/**
 Minimum height for the cell content.
 */
@property (nonatomic, assign) IBInspectable CGFloat minimumHeight UI_APPEARANCE_SELECTOR;

@end