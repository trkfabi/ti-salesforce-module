//
//  SCAppearanceApplicator.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/13/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCAppearanceConfiguration;

/**
 Protocol that a class should conform to if it wants to be consulted when appearance styles should be applied.
 
 When appearance configuration is initially set, or when it changes, various classes may need to be consulted to cause it to apply updates to UIAppearance selectors.  This decentralizes the way appearance styles are applied, allowing a variety of classes throughout the project to be responsible for their own styling rules.
 
     + (void)applyAppearanceForConfiguration:(SCAppearanceConfiguration *)configuration {
         UIColor *primaryBrandColor = [configuration colorForName:SCSAppearancePrimaryBrandColor];
         UIColor *primaryTextColor = [configuration colorForName:SCSAppearanceContrastPrimaryColor];
         
         [SCPicklistInputView appearance].labelColor = primaryTextColor;
         [SCPicklistInputView appearance].highlightedViewColor = primaryBrandColor;
     }
 */
@protocol SCAppearanceApplicator <NSObject>

/**
 Called when appearance configuration should be applied.

 If the receiver doesn't need to make any updates, it should be smart enough to skip any configurations it doesn't care about.  Furthermore, it should be conservative in which appearance selectors to apply.  All UIAppearance setters that are applied will apply to the application as a whole, so try to ensure your appearance settings are specific enough to only target the views that concern the particular applicator.
 @param configuration The configuration instance that should be applied.
 */
+ (void)applyAppearanceForConfiguration:(SCAppearanceConfiguration*)configuration;

@end
