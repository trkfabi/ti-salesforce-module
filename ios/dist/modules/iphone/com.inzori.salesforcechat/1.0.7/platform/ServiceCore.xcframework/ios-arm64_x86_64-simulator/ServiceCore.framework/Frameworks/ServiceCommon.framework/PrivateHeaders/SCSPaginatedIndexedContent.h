//
//  SCSPaginatedIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSBaseIndexedContent.h"
#import "SCSIndexedContentDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, SCSPaginatedState) {
    SCSPaginatedStateCanLoadMore   = 1 << 0,
    SCSPaginatedStateIsEmpty       = 1 << 1,
    SCSPaginatedStateIsLoading     = 1 << 2,
    SCSPaginatedStateIsLoadingMore = 1 << 3,
};

@class SCSPaginatedIndexedContent;
@protocol SCSPaginatedIndexedContentDelegate

@optional

- (void)paginatedContent:(SCSPaginatedIndexedContent*)content stateDidChange:(SCSPaginatedState)newState fromState:(SCSPaginatedState)state;

@end

/**
 Wraps an SCSIndexedContent instance to support automatic pagination within its contents.
 */
@interface SCSPaginatedIndexedContent : SCSBaseIndexedContent

/**
 The SCSIndexedContent instance supplied to the constructor.
 */
@property (nonatomic, strong, readonly) NSObject<SCSIndexedContent> *content;

/**
 Delegate property used for paginated controller actions only.
 */
@property (nonatomic, weak) NSObject<SCSPaginatedIndexedContentDelegate> *paginatedDelegate;

/**
 Indicates whether or not the footer should be visible.
 
 The content data to present in the footer is supplied through the `setFooterContent:forState:` method.
 */
@property (nonatomic, assign, getter=isFooterVisible) BOOL footerVisible;

/**
 The current state of the controller.
 */
@property (nonatomic, assign, readonly) SCSPaginatedState currentState;

/**
 Designated initializer to construct a filtered content controller.

 @param content Nested content controller to filter.

 @return Initialized content controller.
 */
- (instancetype)initWithContent:(NSObject<SCSIndexedContent>*)content NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/**
 Returns the content data to use for the given state.
 
 @param stateMask A bitmask indicating the the state of the content controller
 
 @return Array of SCSContentData instances to add at the end of the indexed content, or `nil` if nothing should be shown for this state.
 */
- (nullable NSArray<NSObject<SCSContentData>*>*)footerContentForState:(SCSPaginatedState)stateMask;

/**
 Sets the footer content to show for the given state.
 
 @param footerContent Array of SCSContentData instances to add at the end of the indexed content, or `nil` if nothing should be shown for this state.
 @param stateMask A bitmask indicating the the state of the content controller
 */
- (void)setFooterContent:(nullable NSArray<NSObject<SCSContentData>*>*)footerContent forState:(SCSPaginatedState)stateMask;

@end

NS_ASSUME_NONNULL_END
