/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <UIKit/UIKit.h>
#import "SOSMaskable.h"

/**
 *  Custom UITextField that auto-masks itself when screen sharing is enabled during an SOS session.
 *  Otherwise identical to the default `UITextField`.
 *
 *  @see `SOSMaskable`
 */
@interface SOSMaskedTextField : UITextField<SOSMaskable>

/**
 *
 *  Initializes and returns a newly allocated `SOSMaskedTextField` object with the specified frame rectangle.
 *
 *  @param aRect The frame rectangle for the view, measured in points. The origin of the frame is relative to
 *  the superview in which you plan to add it. This method uses the frame rectangle to set the center and bounds
 *  properties accordingly.
 *
 *  @return An initialized `SOSMaskedTextField` object or nil if the object couldn't be created.
 *
 *  @note Create a `SOSMaskedTextField` in the given frame. This UIElement will be masked when the screen is shared
 *  with the agent view. When the user touches a `SOSMaskedTextField` while their screen is being shared, the
 *  mask will be removed and the screen will not be shared while the masked is removed.
 *
 *  @note If you used Interface Builder to design your interface, this method is not called when your view objects are loaded from
 *  the nib file. To add a `SOSMaskedTextField` in your nib just change the class of the `UITextField` to `SOSMaskedTextField`.
 *
 */
- (id)initWithFrame:(CGRect)aRect;

/**
 *  Initializes and returns a newly allocated `SOSMaskedTextField` object with the specified frame rectangle, maskPattern
 *  and borderColor.
 *
 *  @param aRect       The frame rectangle for the view, measured in points. The origin of the frame is relative to
 *  the superview in which you plan to add it. This method uses the frame rectangle to set the center and bounds
 *  properties accordingly.
 *  @param maskPattern The file name for the mask color that will be created for the view. The image will to be used to
 *  create a UIColor using colorWithPatternImage:. If the value is nil the default mask pattern will be used.
 *  @param borderColor A `UIColor` that will create a border color around your `SOSMaskedTextView`. This is a highlight to the
 *  maskPattern image that will hid the contents of the `SOSMaskedTextView`. In the middle of the view will be a the word
 *  "Hidden" the back ground of this image will also be changed with the border color. If the value is nil the default mask
 *  pattern will be used.
 *  @param text        The text that will be displayed in the middle of the masked text field. If this text needs to be localized
 *  ensure a localize string is passed in to this variable. If this variable is set to nil the default localized value of "Hidden"
 *  will be passed in.
 *  @param textColor   The color of the text in the middle of the masked text field. If this variable is set to nil the default
 *  color will be white.
 *
 *  @return An initialized `SOSMaskedTextField` object or nil if the object couldn't be created.
 *
 *  @discussion Create a `SOSMaskedTextField` in the given frame with a custom masked image string, borderColor, text, and textColor.
 *  The UIElement will be masked when the screen is shared with the agent view. When the user touches a `SOSMaskedTextField` while
 *  their screen is being shared, the mask will be removed and the screen will not be shared while the masked is removed.
 *
 *  If you used Interface Builder to design your interface, this method is not called when your view objects are loaded from
 *  the nib file. To add a `SOSMaskedTextField` in your nib just change the class of the UITextField to `SOSMaskedTextField`.
 *
 *  Setting the MaskPattern, BorderColor, Text, and TextColor will adjust the look of the mask, this can be done to adjust the mask
 *  to the look and feel of the app. If you are using Interface Builder add following RunTime Attributes in the nib Identity Inspector
 *  maskingPattern, borderColor, maskText, and maskTextColor.
 *
 */
- (id)initWithFrame:(CGRect)aRect maskPattern:(NSString *)maskPattern borderColor:(UIColor *)borderColor text:(NSString*)text textColor:(UIColor*)textColor;

@end
