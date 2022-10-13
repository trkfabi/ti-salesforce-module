//
// Created by florian on 26.03.13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <UIKit/UIKit.h>

typedef struct {
    NSLayoutRelation relation;
    CGFloat multiplier;
    CGFloat constant;
    UILayoutPriority priority;
} SCV_FLKAutoLayoutPredicate;

FOUNDATION_EXTERN SCV_FLKAutoLayoutPredicate SCV_FLKAutoLayoutPredicateMake(NSLayoutRelation relation, CGFloat multiplier, CGFloat constant, UILayoutPriority priority);

@interface UIView (SCV_FLKAutoLayoutPredicate)

- (NSLayoutConstraint*)SCV_applyPredicate:(SCV_FLKAutoLayoutPredicate)predicate toView:(UIView*)toView attribute:(NSLayoutAttribute)attribute;
- (NSLayoutConstraint*)SCV_applyPredicate:(SCV_FLKAutoLayoutPredicate)predicate toView:(UIView*)view fromAttribute:(NSLayoutAttribute)fromAttribute toAttribute:(NSLayoutAttribute)toAttribute;

@end
