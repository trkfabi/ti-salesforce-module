//
//  SCSTableViewCell.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 12/30/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Container view used to wrap the -[SCSTableViewCell thumbnailImageView] view.  This allows appearance selectors to be applied to the appropriate subview.
 */
@interface SCSTableViewImageContentView : UIView @end

/**
 Container view used to wrap the -[SCSTableViewCell titleTextLabel] view.  This allows appearance selectors to be applied to the appropriate label.
 */
@interface SCSTableViewTitleContentView : UIView @end

/**
 Container view used to wrap the -[SCSTableViewCell subtitleTextLabel] view.  This allows appearance selectors to be applied to the appropriate label.
 */
@interface SCSTableViewSubtitleContentView : UIView @end

/**
 Base table cell class that provides UIAppearance properties for styling label fonts and colors, as well as image sizes.
 */
@interface SCSTableViewCell : UITableViewCell

/**
 Thumbnail image view.
 */
@property (nonatomic, strong, readonly) UIImageView *thumbnailImageView;

/**
 Title text label.
 */
@property (nonatomic, strong, readonly) UILabel *titleTextLabel;

/**
 Subtitle text label.
 */
@property (nonatomic, strong, readonly) UILabel *subtitleTextLabel;

@end

@interface SCSTableViewCell (UIAppearance)

/**
 Image size to constrain the image to, when an image is provided.
 */
@property (nonatomic, assign) IBInspectable CGSize thumbnailSize UI_APPEARANCE_SELECTOR;

/**
 Indicates whether or not the title should be vertically centered when there is no subtitle text.
 */
@property (nonatomic, assign, getter=shouldVerticallyCenterTitleWithoutSubtitle) IBInspectable BOOL verticallyCenterTitleWithoutSubtitle UI_APPEARANCE_SELECTOR;

/**
 Padding between the thumbnail image and the text labels.
 */
@property (nonatomic, assign) IBInspectable CGFloat thumbnailPadding UI_APPEARANCE_SELECTOR;

/**
 Edge insets from the outside edge of the cell to the contents.
 */
@property (nonatomic, assign) IBInspectable UIEdgeInsets outerInsets UI_APPEARANCE_SELECTOR;

/**
 Minimum height for the cell content.
 */
@property (nonatomic, assign) IBInspectable CGFloat minimumHeight UI_APPEARANCE_SELECTOR;

@end

@interface SCSTableViewCell (Deprecated)

@property (nonatomic, readonly, strong, nullable) UIImageView *imageView __attribute__((unavailable("Use thumbnailImageView instead")));
@property (nonatomic, readonly, strong, nullable) UILabel *textLabel  __attribute__((unavailable("Use titleTextLabel instead")));
@property (nonatomic, readonly, strong, nullable) UILabel *detailTextLabel  __attribute__((unavailable("Use subtitleTextLabel instead")));

@end

NS_ASSUME_NONNULL_END
