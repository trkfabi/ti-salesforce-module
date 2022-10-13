//
//  SCSMessagingInputView.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-11-03.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCSMessagingInputView : UIView

/**
 Create custom UIButtons in this array for display to the leading
 side of the text input view. Facilitates file transfer button
 for chat.
 */
@property (nonatomic) NSArray<UIButton *> *accessoryButtons;

/**
 Placeholder string that displays above text input view when
 no text has been entered and the input is not first responder.
 */
@property (nonatomic) NSString *placeholderString;

/**
 View containing the touchable elements of the view
 */
@property (nonatomic, readonly) UIView *contentView;

/**
 View containing the text input, accessory buttons & send button.
 */
@property (nonatomic, readonly) UIView *inputBar;

/**
 UIAppearance selector for changing the image used for the send button.
 */
@property (nonatomic) UIImage *sendButtonImage UI_APPEARANCE_SELECTOR;

/**
 UIAppearance selector for changing the color of the text input bar.
 */
@property (nonatomic) UIColor *inputBarBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 A method to set the accessibility label for the text input view. This allows the SDK to customize this common code.
 */
- (void)setInputViewAccessibilityString:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
