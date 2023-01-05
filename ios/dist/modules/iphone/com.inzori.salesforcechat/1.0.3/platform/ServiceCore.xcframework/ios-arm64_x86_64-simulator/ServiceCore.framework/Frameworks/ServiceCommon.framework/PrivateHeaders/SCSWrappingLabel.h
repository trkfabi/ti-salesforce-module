//
//  SCSWrappingLabel.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-09-12.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Custom UILabel subclass that ensures the content will never be sized smaller than the longest word.
 */
@interface SCSWrappingLabel : UILabel

/**
 The minimum width this label has determined it is capable to be.  If no width constraints are specified, this value will be `0`.
 */
@property (nonatomic, assign, readonly) CGFloat minimumWrappedWidth;

@end

NS_ASSUME_NONNULL_END
