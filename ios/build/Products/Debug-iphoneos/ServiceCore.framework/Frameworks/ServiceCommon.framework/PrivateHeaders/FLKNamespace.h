
// Namespaced Header

#ifndef __NS_SYMBOL
// We need to have multiple levels of macros here so that __NAMESPACE_PREFIX_ is
// properly replaced by the time we concatenate the namespace prefix.
#define __NS_REWRITE(ns, symbol) ns ## _ ## symbol
#define __NS_BRIDGE(ns, symbol) __NS_REWRITE(ns, symbol)
#define __NS_SYMBOL(symbol) __NS_BRIDGE(SCV, symbol)
#endif

/**
 * UIView+FLKAutoLayoutPredicate.h
 */
#ifndef FLKAutoLayoutPredicate
#define FLKAutoLayoutPredicate __NS_SYMBOL(FLKAutoLayoutPredicate)
#endif

#ifndef FLKAutoLayoutPredicateMake
#define FLKAutoLayoutPredicateMake __NS_SYMBOL(FLKAutoLayoutPredicateMake)
#endif

#ifndef applyPredicate
#define applyPredicate __NS_SYMBOL(applyPredicate)
#endif


/**
 * FLKAutoLayoutPredicateList.h
 */
#ifndef predicateBlock
#define predicateBlock __NS_SYMBOL(predicateBlock)
#endif

#ifndef FLKAutoLayoutPredicateList
#define FLKAutoLayoutPredicateList __NS_SYMBOL(FLKAutoLayoutPredicateList)
#endif

#ifndef predicateListFromString
#define predicateListFromString __NS_SYMBOL(predicateListFromString)
#endif

#ifndef iteratePredicatesUsingBlock
#define iteratePredicatesUsingBlock __NS_SYMBOL(iteratePredicatesUsingBlock)
#endif

/**
 * NSLayoutConstraint+FLKAutoLayoutDebug.h
 */
#ifndef FLKAutoLayoutDebug
#define FLKAutoLayoutDebug __NS_SYMBOL(FLKAutoLayoutDebug)
#endif

/**
 * UIView+FLKAutoLayout.h
 */
#ifndef FLKNoConstraint
#define FLKNoConstraint __NS_SYMBOL(FLKNoConstraint)
#endif

#ifndef FLKAutoLayout
#define FLKAutoLayout __NS_SYMBOL(FLKAutoLayout)
#endif

#ifndef alignAttribute
#define alignAttribute __NS_SYMBOL(alignAttribute)
#endif

#ifndef alignToView
#define alignToView __NS_SYMBOL(alignToView)
#endif

#ifndef alignTop
#define alignTop __NS_SYMBOL(alignTop)
#endif

#ifndef alignBottom
#define alignBottom __NS_SYMBOL(alignBottom)
#endif

#ifndef alignTop
#define alignTop __NS_SYMBOL(alignTop)
#endif

#ifndef alignLeading
#define alignLeading __NS_SYMBOL(alignLeading)
#endif

#ifndef alignLeadingEdgeWithView
#define alignLeadingEdgeWithView __NS_SYMBOL(alignLeadingEdgeWithView)
#endif

#ifndef alignTrailingEdgeWithView
#define alignTrailingEdgeWithView __NS_SYMBOL(alignTrailingEdgeWithView)
#endif

#ifndef alignTopEdgeWithView
#define alignTopEdgeWithView __NS_SYMBOL(alignTopEdgeWithView)
#endif

#ifndef alignBottomEdgeWithView
#define alignBottomEdgeWithView __NS_SYMBOL(alignBottomEdgeWithView)
#endif

#ifndef alignBaselineWithView
#define alignBaselineWithView __NS_SYMBOL(alignBaselineWithView)
#endif

#ifndef alignCenterXWithView
#define alignCenterXWithView __NS_SYMBOL(alignCenterXWithView)
#endif

#ifndef alignCenterYWithView
#define alignCenterYWithView __NS_SYMBOL(alignCenterYWithView)
#endif

#ifndef alignCenterWithView
#define alignCenterWithView __NS_SYMBOL(alignCenterWithView)
#endif

#ifndef constrainWidth
#define constrainWidth __NS_SYMBOL(constrainWidth)
#endif

#ifndef constrainHeight
#define constrainHeight __NS_SYMBOL(constrainHeight)
#endif

#ifndef constrainWidthToView
#define constrainWidthToView __NS_SYMBOL(constrainWidthToView)
#endif

#ifndef constrainHeightToView
#define constrainHeightToView __NS_SYMBOL(constrainHeightToView)
#endif

#ifndef constrainAspectRatio
#define constrainAspectRatio __NS_SYMBOL(constrainAspectRatio)
#endif

#ifndef constrainLeadingSpaceToView
#define constrainLeadingSpaceToView __NS_SYMBOL(constrainLeadingSpaceToView)
#endif

#ifndef constrainTrailingSpaceToView
#define constrainTrailingSpaceToView __NS_SYMBOL(constrainTrailingSpaceToView)
#endif

#ifndef constrainTopSpaceToView
#define constrainTopSpaceToView __NS_SYMBOL(constrainTopSpaceToView)
#endif

#ifndef constrainBottomSpaceToView
#define constrainBottomSpaceToView __NS_SYMBOL(constrainBottomSpaceToView)
#endif

#ifndef alignAttribute
#define alignAttribute __NS_SYMBOL(alignAttribute)
#endif

#ifndef equalWidthForViews
#define equalWidthForViews __NS_SYMBOL(equalWidthForViews)
#endif

#ifndef equalHeightForViews
#define equalHeightForViews __NS_SYMBOL(equalHeightForViews)
#endif

#ifndef alignLeadingEdgesOfViews
#define alignLeadingEdgesOfViews __NS_SYMBOL(alignLeadingEdgesOfViews)
#endif

#ifndef alignTrailingEdgesOfViews
#define alignTrailingEdgesOfViews __NS_SYMBOL(alignTrailingEdgesOfViews)
#endif

#ifndef alignTopEdgesOfViews
#define alignTopEdgesOfViews __NS_SYMBOL(alignTopEdgesOfViews)
#endif

#ifndef alignBottomEdgesOfViews
#define alignBottomEdgesOfViews __NS_SYMBOL(alignBottomEdgesOfViews)
#endif

#ifndef alignLeadingAndTrailingEdgesOfViews
#define alignLeadingAndTrailingEdgesOfViews __NS_SYMBOL(alignLeadingAndTrailingEdgesOfViews)
#endif

#ifndef alignTopAndBottomEdgesOfViews
#define alignTopAndBottomEdgesOfViews __NS_SYMBOL(alignTopAndBottomEdgesOfViews)
#endif

#ifndef spaceOutViewsHorizontally
#define spaceOutViewsHorizontally __NS_SYMBOL(spaceOutViewsHorizontally)
#endif

#ifndef spaceOutViewsVertically
#define spaceOutViewsVertically __NS_SYMBOL(spaceOutViewsVertically)
#endif

#ifndef distributeCenterXOfViews
#define distributeCenterXOfViews __NS_SYMBOL(distributeCenterXOfViews)
#endif

#ifndef distributeCenterYOfViews
#define distributeCenterYOfViews __NS_SYMBOL(distributeCenterYOfViews)
#endif

/**
 * UIView+FLKAutoLayoutDebug.h
 */
#ifndef FLKAutoLayoutDebug
#define FLKAutoLayoutDebug __NS_SYMBOL(FLKAutoLayoutDebug)
#endif

#ifndef flk_nameTag
#define flk_nameTag __NS_SYMBOL(flk_nameTag)
#endif

#ifndef flk_exerciseAmbiguityInLayout
#define flk_exerciseAmbiguityInLayout __NS_SYMBOL(flk_exerciseAmbiguityInLayout)
#endif

#ifndef flk_autolayoutTrace
#define flk_autolayoutTrace __NS_SYMBOL(flk_autolayoutTrace)
#endif
