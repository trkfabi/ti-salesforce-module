//
//  SCSInsetConstraint.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/5/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SCSInsetConstraintActive) {
    SCSInsetConstraintActiveNone     = 0,
    SCSInsetConstraintActiveTop      = 1 << 0,
    SCSInsetConstraintActiveLeading  = 1 << 1,
    SCSInsetConstraintActiveBottom   = 1 << 2,
    SCSInsetConstraintActiveTrailing = 1 << 3,
    SCSInsetConstraintActiveAll      = (SCSInsetConstraintActiveTop |
                                        SCSInsetConstraintActiveLeading |
                                        SCSInsetConstraintActiveBottom |
                                        SCSInsetConstraintActiveTrailing),
};

/**
 Constraint helper that assigns UIEdgeInsets to a set of constraints automatically.
 
 This can be useful for managing padding UI_APPEARANCE_SELECTOR properties easily without a lot of boilerplate code.
 */
@interface SCSInsetConstraint : NSObject

/**
 The inset constants to apply to the constraints.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 The set of constraints supplied to the initializer.
 */
@property (nonatomic, copy, readonly) NSArray<NSLayoutConstraint*> *constraints;

/**
 Bitmask of which constraints should be active, and which should be deactivated.
 */
@property (nonatomic, assign) SCSInsetConstraintActive active;

/**
 Designated initializer for constructing the inset handler.
 
 If any properties are null, that edge will be ignored when assigning edge insets.

 @param topConstraint The constraint used for the top edge.
 @param leadingConstraint The constraint used for the leading edge.
 @param bottomConstraint The constraint used for the bottom edge.
 @param trailingConstraint The constraint used for the trailing edge.
 @return The initialized instance.
 */
- (instancetype)initWithTop:(nullable NSLayoutConstraint*)topConstraint
                    leading:(nullable NSLayoutConstraint*)leadingConstraint
                     bottom:(nullable NSLayoutConstraint*)bottomConstraint
                   trailing:(nullable NSLayoutConstraint*)trailingConstraint NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer that takes a varg set of constraints.

 This initializer will select the constraints based on the first attribute's dimension. For the leading and trailing constraints, left and right attributes are also accepted.
 
 @warning
 If you are experiencing layout problems with this method, ensure the first attribute on the constraint is the dimension you wish to have controlled.

 @param constraints The varg list of constraints.
 @return Initialized instance.
 */
- (instancetype)initWithConstraints:(NSLayoutConstraint*)constraints, ...;

/**
 Convenience initializer that accepts an array of constraints.

 This initializer will select the constraints based on the first attribute's dimension. For the leading and trailing constraints, left and right attributes are also accepted.

 @note
 This initializer may be useful when used in conjunction with FLKAutoLayout's methods, since they return an array of constraints.

 @warning
 If you are experiencing layout problems with this method, ensure the first attribute on the constraint is the dimension you wish to have controlled.

 @param constraints The array of constraints.
 @return Initialized instance.
 */
- (instancetype)initWithConstraintsArray:(NSArray<NSLayoutConstraint*>*)constraints;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
