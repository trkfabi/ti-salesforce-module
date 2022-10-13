//
//  UIImageView+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/16/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCAppearanceConfiguration;
/**
 ServiceCommon additions to UIImageView to simplify the assignment of brandable images to a view.
 */
@interface UIImageView (ServiceCommon)

/**
 Appearance configuration assigned to this view.  This configuration object will be consulted for images when the appearanceImageName changes, or when the trait collections change.
 */
@property (nonatomic, weak) SCAppearanceConfiguration *appearanceConfiguration;

/**
 Assigns an image to this image view based on the current appearance configuration's state.
 
 Behind the scenes the appropriate image will be identified and populated within the image view.  If the trait collections for the view change, and alternative images are provided that match the new traits, the image will automatically be updated.  Furthermore if the image is reassigned within the configuration, the image will automatically update.
 */
@property (nonatomic, copy) NSString *imageName UI_APPEARANCE_SELECTOR;

@end
