//
//  SCSAgentMessageCell.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 3/16/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
@interface SCSAgentMessageCellContentView: UIView @end
@interface SCSAgentMessageAgentNameContentView: UIView @end
@interface SCSAgentMessageAgentImageContentView: UIView @end
@interface SCSAgentMessageTextViewContentView: UIView @end
@interface SCSAgentMessageBackgroundImageContentView: UIView @end
@interface SCSAgentMessageTimeStampContainerView: UIView @end

extern UIEdgeInsets const kDefaultAgentOuterInsets;
extern UIEdgeInsets const kDefaultAgentTextInsets;
extern UIEdgeInsets const kDefaultAgentBackgroundImageInsets;
extern CGSize const kDefaultAgentImageSize;

@interface SCSAgentMessageViewCell : UITableViewCell

@property (nonatomic, strong) NSLayoutConstraint *messageLabelHeightConstraint;
@property (nonatomic, strong) NSLayoutConstraint *messageLabelWidthConstraint;

/**
 Imageview for the agent image
 */
@property (nonatomic, strong, readonly) UIImageView *agentImageView;

/**
Imageview for the background speech bubble image
*/
@property (nonatomic, strong, readonly) UIImageView *backgroundImageView;

/**
 Message label
 */
@property (nonatomic, strong, readonly) UITextView *messageTextView;

/**
 Time stamp label.
 */
@property (nonatomic, strong, readonly) UILabel *timeStampLabel;

/**
 Agent name label.
 */
@property (nonatomic, strong, readonly) UILabel *agentNameLabel;

@end

@interface SCSAgentMessageViewCell (UIAppearance)

/**
 Padding between the agent Image and Background Image.
 */
@property (nonatomic, assign) CGFloat backgroundImagePadding;

/**
 Edge insets for the cell
 */
@property (nonatomic, assign) UIEdgeInsets outerInsets;

/**
 Edge insets for the message label
 */
@property (nonatomic, assign) UIEdgeInsets labelInsets;

/**
 Padding insets for the agent name label
 */
@property (nonatomic, assign) CGFloat agentNameLabelPadding;

/**
Size for the Agent image.
 */
@property (nonatomic, assign) CGSize agentImageSize;

/**
 Minimum height for the cell content.
 */
@property (nonatomic, assign) IBInspectable CGFloat minimumHeight UI_APPEARANCE_SELECTOR;

/**
 BackgroundImage tint color.
 */
@property (nonatomic, strong) UIColor *backgroundImageViewTintColor UI_APPEARANCE_SELECTOR;

/**
 BackgroundImageView Image.
 */
@property (nonatomic, strong) UIImage *backgroundImage UI_APPEARANCE_SELECTOR;

@end
