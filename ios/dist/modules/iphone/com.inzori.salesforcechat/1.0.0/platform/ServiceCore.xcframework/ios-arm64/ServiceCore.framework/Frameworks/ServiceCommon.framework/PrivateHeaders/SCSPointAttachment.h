//
//  SCSPointAttachment.h
//  ServiceCommon
//
//  Created by Amit Gosar on 3/9/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSAttachment.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Instance of an SCSAttachment that is bound to a specific point on the screen.  It supports user interaction for dragging it across the screen.
 */
@interface SCSPointAttachment : SCSAttachment

/**
 The current center point for the view.  Auto layout constraints prevents it from exceeding the edges of the screen.
 
 If the `positionAbsolute` property is set to `NO`, this center point is assumed to contain coordinates between `0.0` and `1.0` to indicate relative coordinates to the screen.
 */
@property (nonatomic, assign) CGPoint centerPoint;

/**
 Indicates whether or not the position is given in absolute points, or if the location is a percent value relative to the edges of the screen.
 
 @note If this value is `NO`, and the centerPoint value contains values greater than 1.0, it will automatically be assumed those input values are still absolute, and the value will be converted as needed.
 */
@property (nonatomic, assign, getter=isPositionAbsolute) BOOL positionAbsolute;

/**
 Controls whether or not this attachment can be dragged by the user.  Default `YES`.
 */
@property (nonatomic, assign, getter=isDraggable) BOOL draggable;

/**
 Pan gesture recognizer, if the `draggable` property is set to `YES`.
 */
@property (nullable, nonatomic, strong, readonly) UIPanGestureRecognizer *panGestureRecognizer;

/**
 Insets from the outside edge of the screen where the view is allowed to overlap.
 */
@property (nonatomic, assign) UIEdgeInsets edgeInsets;

/**
 Designated initializer.
 
 @param controller Attachment content controller.
 @param centerPoint Initial center point.
 */
- (instancetype)initWithController:(UIViewController<SCSAttachmentController> *)controller centerPoint:(CGPoint)centerPoint;

@end

NS_ASSUME_NONNULL_END
