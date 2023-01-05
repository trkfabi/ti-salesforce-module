//
//  SCSMultilineTableViewCell.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 12/30/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import "SCSTableViewCell.h"

/**
 Table cell that implements a multiline set of text labels that size to a maximum number of total lines.
 
 @note This only respects labels that use the `attributedText` property.
 */
@interface SCSMultilineTableViewCell : SCSTableViewCell

/**
 Maximum number of lines of text, across both titleLabel and subtitleLabel fields.  If this value is set to `0` then text wrapping will not be limited.
 */
@property (nonatomic, assign) IBInspectable NSInteger maximumLineCount UI_APPEARANCE_SELECTOR;

/**
 Minimum number of lines to display in the subtitleLabel field.
 
 When the titleLabel field has a large amount of text, it may occupy the total number of maximumLineCount lines, meaning none of the subtitleLabel text will be displayed.  Setting this value to non-zero will ensure at least that number of lines of subtitle text will be displayed.
 */
@property (nonatomic, assign) IBInspectable NSInteger minimumSubtitleLineCount UI_APPEARANCE_SELECTOR;

@end
