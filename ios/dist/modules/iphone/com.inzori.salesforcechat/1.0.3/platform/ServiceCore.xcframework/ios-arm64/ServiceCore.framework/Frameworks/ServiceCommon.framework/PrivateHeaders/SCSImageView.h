//
//  SCSImageView.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/6/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCAppearanceImageCollection;

/**
 Custom image view that adapts its contents based on changes to trait collections.
 */
@interface SCSImageView : UIImageView

/**
 Assigns an image to this image view based on the current appearance configuration's state.

 Behind the scenes the appropriate image will be identified and populated within the image view.  If the trait collections for the view change, and alternative images are provided that match the new traits, the image will automatically be updated.  Furthermore if the image is reassigned within the configuration, the image will automatically update.
 */
@property (nullable, nonatomic, weak) SCAppearanceImageCollection *imageCollection UI_APPEARANCE_SELECTOR;

/**
 Desired image rendering mode when using appearance proxies.
 */
@property (nonatomic, assign) UIImageRenderingMode renderingMode UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
