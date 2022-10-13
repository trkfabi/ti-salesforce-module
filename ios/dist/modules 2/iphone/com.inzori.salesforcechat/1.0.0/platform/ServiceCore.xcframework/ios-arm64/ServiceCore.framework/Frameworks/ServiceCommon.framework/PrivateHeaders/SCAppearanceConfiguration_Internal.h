//
//  SCUApperanceConfiguration_Internal.h
//  ServiceSDK
//
//  Created by Amit Gosar on 9/1/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nullable SCStringValueForFontWeight(NSInteger type);
extern NSInteger SCFontWeightTypeForFontWeightName(NSString *name);

/* Accessibility font types are used with dynamic text and are set by the user. If the device changes the font size,
 the accessibility font types change too. */
typedef NS_ENUM(NSUInteger, SCSAccessibilityFontTypes) {
    /** The ServiceSDK accessibility identifier for Section. */
    SCSAccessibilitySection = 0,
    /** The ServiceSDK accessibility identifier for Title. */
    SCSAccessibilityTitle,
    /** The ServiceSDK accessibility identifier for Body. */
    SCSAccessibilityBody,
    /** The ServiceSDK accessibility identifier for Label. */
    SCSAccessibilityLabel,
    /** The ServiceSDK accessibility identifier for Caption. */
    SCSAccessibilityCaption,
    /** The ServiceSDK accessibility identifier for Small. */
    SCSAccessibilitySmall
};

@protocol SCAppearanceTraitStorage <NSObject>

@property (nonatomic, strong, nullable) UITraitCollection *traitCollection;

@end

@class SCAppearanceImageCollection, SCAppearanceFontObject, SCAppearanceTextAttributesObject;
@interface SCAppearanceConfiguration () {
@protected
    NSMutableDictionary<NSString*, UIColor*> *_colors;
    NSMutableDictionary<NSString*, SCAppearanceImageCollection*> *_images;
    NSMutableDictionary<NSString*, SCAppearanceFontObject*> *_fonts;
    NSDictionary<NSString*, NSDictionary*> *_accessibilityTypeSizes;
    NSMutableDictionary<NSString*, NSMutableArray<SCAppearanceTextAttributesObject*>*> *_textAttributes;
}

- (BOOL)canApplyAppearanceUpdates;

@end

@interface SCAppearanceConfiguration (FontsInternal)

// These methods are for dynamic text
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight accessibiltyFontType:(SCSAccessibilityFontTypes)fontType;;
- (UIFont*)fontForWeight:(NSInteger)weight accessibilityFontType:(SCSAccessibilityFontTypes)fontType;
- (CGFloat)sizeForAccessibilityFontType:(SCSAccessibilityFontTypes)fontType;

// TODO: These methods will go away one I have an opportunity to clean up the CSS/font handling of articles
- (nullable UIFont*)fontForWeight:(NSInteger)weight pointSize:(CGFloat)size;
- (nullable NSString*)getDefaultFontFamily;
- (NSString*)getStringFromAccessibilityFontType:(SCSAccessibilityFontTypes)fontType;

@end

@interface SCAppearanceConfiguration (TraitCollection)

+ (nullable NSPredicate*)predicateForTraitCollection:(UITraitCollection*)traitCollection;

@end

/**
 Attributed text appearance handling.

 @warning This logic is hidden from the public APIs currently, but they're designed to be potentially user-facing in the future.
 */
@interface SCAppearanceConfiguration (AttributedTextInternal)

- (nullable NSAttributedString*)attributedStringWithString:(nullable NSString*)string compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forLabelName:(nonnull NSString*)name;

@end

@interface SCAppearanceConfiguration (ImagesInternal)

/**
 Returns the image collection instance associated with the given token name.
 
 The returned value can be used to query for multiple images as trait collections change, without needing to call out to the SCAppearanceConfiguration instance each time.

 @param name Image token name.
 @return Image collection, or `nil` if none could be found or created.
 */
- (nullable SCAppearanceImageCollection*)imageCollectionForName:(SCSAppearanceImageToken)name;

@end

@interface SCAppearanceFontObject : NSObject <NSCopying>

@property (nonatomic, strong) UIFontDescriptor *fontDescriptor;
@property (nullable, nonatomic, strong) NSString *filename;

@end


NS_ASSUME_NONNULL_END
