//
//  SCAppearanceImageCollection.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/7/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SCCPrivateDefines.h"

#ifndef SCSAppearanceImageToken
typedef NSString * SCSAppearanceImageToken SCS_STRING_ENUM;
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the set of images assigned for a particular image token.  Multiple images may be assigned that apply to specific trait collections.
 */
@interface SCAppearanceImageCollection : NSObject <NSCopying>

/**
 Image token name.
 */
@property (nonatomic, copy, readonly) SCSAppearanceImageToken imageName;

/**
 Designated initializer.

 @param image Image token.
 @return Initialized collection.
 */
- (instancetype)initWithName:(SCSAppearanceImageToken)image NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/**
 Adds a new image for the given trait collection.

 @param image Image to add.
 @param traitCollection Trait collection to be applied to the image.
 */
- (void)addImage:(UIImage*)image compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

/**
 Returns an image for the given trait collection.

 @param traitCollection Trait collection to consider.
 @return Image that best matches the given trait collection, or `nil` if no image was found.
 */
- (nullable UIImage*)imageCompatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

NS_ASSUME_NONNULL_END
