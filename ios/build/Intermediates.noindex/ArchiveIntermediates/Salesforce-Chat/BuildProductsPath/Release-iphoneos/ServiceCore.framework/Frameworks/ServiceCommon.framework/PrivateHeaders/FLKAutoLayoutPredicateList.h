//
// Created by florian on 25.03.13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import "UIView+FLKAutoLayoutPredicate.h"


typedef NSLayoutConstraint* (^SCV_predicateBlock)(SCV_FLKAutoLayoutPredicate predicate);


@interface SCV_FLKAutoLayoutPredicateList : NSObject

+ (id)SCV_predicateListFromString:(NSString*)string;
- (NSArray*)SCV_iteratePredicatesUsingBlock:(SCV_predicateBlock)block;

@end
