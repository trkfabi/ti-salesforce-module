//
// Created by florian on 25.03.13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <UIKit/UIKit.h>


FOUNDATION_EXTERN NSString * const SCV_FLKNoConstraint;

@interface UIView (SCV_FLKAutoLayout)

- (NSArray*)SCV_alignAttribute:(NSLayoutAttribute)attribute toAttribute:(NSLayoutAttribute)toAttribute ofView:(UIView*)view predicate:(NSString*)predicate;


- (NSArray*)SCV_alignToView:(UIView*)view;
- (NSArray*)SCV_alignTop:(NSString*)top leading:(NSString*)leading bottom:(NSString*)bottom trailing:(NSString*)trailing toView:(UIView*)view;
- (NSArray*)SCV_alignTop:(NSString*)top leading:(NSString*)leading toView:(UIView*)view;
- (NSArray*)SCV_alignBottom:(NSString*)bottom trailing:(NSString*)trailing toView:(UIView*)view;
- (NSArray*)SCV_alignTop:(NSString*)top bottom:(NSString*)bottom toView:(UIView*)view;
- (NSArray*)SCV_alignLeading:(NSString*)leading trailing:(NSString*)trailing toView:(UIView*)view;


- (NSArray*)SCV_alignLeadingEdgeWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignTrailingEdgeWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignTopEdgeWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignBottomEdgeWithView:(UIView*)view predicate:(NSString*)predicate;

- (NSArray*)SCV_alignBaselineWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignCenterXWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignCenterYWithView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_alignCenterWithView:(UIView*)view;


- (NSArray*)SCV_constrainWidth:(NSString*)widthPredicate height:(NSString*)heightPredicate;
- (NSArray*)SCV_constrainWidth:(NSString*)widthPredicate;
- (NSArray*)SCV_constrainHeight:(NSString*)heightPredicate;

- (NSArray*)SCV_constrainWidthToView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_constrainHeightToView:(UIView*)view predicate:(NSString*)predicate;

- (NSArray*)SCV_constrainAspectRatio:(NSString*)predicate;

- (NSArray*)SCV_constrainLeadingSpaceToView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray *)SCV_constrainTrailingSpaceToView:(UIView *)view predicate:(NSString *)predicate;
- (NSArray*)SCV_constrainTopSpaceToView:(UIView*)view predicate:(NSString*)predicate;
- (NSArray*)SCV_constrainBottomSpaceToView:(UIView*)view predicate:(NSString*)predicate;


+ (NSArray*)SCV_alignAttribute:(NSLayoutAttribute)attribute ofViews:(NSArray*)ofViews toViews:(NSArray*)toViews predicate:(NSString*)predicate;
+ (NSArray*)SCV_alignAttribute:(NSLayoutAttribute)attribute ofViews:(NSArray*)views toAttribute:(NSLayoutAttribute)toAttribute ofViews:(NSArray*)toViews predicate:(NSString*)predicate;


+ (NSArray*)SCV_equalWidthForViews:(NSArray*)views;
+ (NSArray*)SCV_equalHeightForViews:(NSArray*)views;


+ (NSArray*)SCV_alignLeadingEdgesOfViews:(NSArray*)views;
+ (NSArray*)SCV_alignTrailingEdgesOfViews:(NSArray*)views;
+ (NSArray*)SCV_alignTopEdgesOfViews:(NSArray*)views;
+ (NSArray*)SCV_alignBottomEdgesOfViews:(NSArray*)views;
+ (NSArray*)SCV_alignLeadingAndTrailingEdgesOfViews:(NSArray*)views;
+ (NSArray*)SCV_alignTopAndBottomEdgesOfViews:(NSArray*)views;


+ (NSArray*)SCV_spaceOutViewsHorizontally:(NSArray*)views predicate:(NSString*)predicate;
+ (NSArray*)SCV_spaceOutViewsVertically:(NSArray*)views predicate:(NSString*)predicate;

+ (NSArray*)SCV_distributeCenterXOfViews:(NSArray*)views inView:(UIView*)view;
+ (NSArray*)SCV_distributeCenterYOfViews:(NSArray*)views inView:(UIView*)inView;

@end

#include "FLKNamespace.h"
