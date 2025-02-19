//
//  NSAttributedString+ServiceCommon.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@class UIFont;
@interface NSAttributedString (ServiceCommon)

/**
 Method that mimics `UITextView sizeThatFits:` without requiring the creating of an empty UITextView for calculations.

 @param size The size that the text must be bound within for rendering purposes
 @return CGSize representing the minimum size to fit the provided text
 */
- (CGSize)sizeForBoundingSize:(CGSize)size;

/**
 Convenience initializer to perform "NSOriginalFont" workaround for miscalculated NSAttributedString sizes.

 @param str NSString having font applied
 @param font UIFont used for string customization
 @return instance of NSAttributedString with correct attributes for size calculation
 */
- (instancetype)initWithString:(NSString *)str font:(UIFont *)font;


/**
 Secondary convenience initializer to perform "NSOriginalFont" workaround for miscalculated NSAttributedString sizes.
 Allows for an attributes dictionary for more complex uses.

 @param str NSString having font & additional attributes applied
 @param font UIFont used for string customization
 @param additionalAttributes Additional attributes for string customization
 @return instance of NSAttributedString with correct attributes for size calculation
 */
- (instancetype)initWithString:(NSString *)str font:(UIFont *)font additionalAttributes:(nullable NSDictionary<NSAttributedStringKey, id> *)additionalAttributes;

@end

NS_ASSUME_NONNULL_END
