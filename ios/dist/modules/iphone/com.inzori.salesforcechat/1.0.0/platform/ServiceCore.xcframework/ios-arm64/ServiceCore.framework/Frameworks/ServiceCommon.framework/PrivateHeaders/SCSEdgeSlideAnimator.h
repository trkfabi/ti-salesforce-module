//
//  SCSEdgeSlideAnimator.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 10/29/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Private implementation of an animated transition to present to/from an edge.

 @warning This class is meant to be private.
 */
@interface SCSEdgeSlideAnimator : NSObject <UIViewControllerAnimatedTransitioning>

/**
 The edge the animation should transition from.
 */
@property (nonatomic, assign, readonly) CGRectEdge edge;

/** Designated initializer.
 
 @param edge The edge the animation should transition from.
 */
- (instancetype)initWithEdge:(CGRectEdge)edge NS_DESIGNATED_INITIALIZER;

@end
