//
//  SCSIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSContent.h"
#import "SCSIndexedContentDelegate.h"

@protocol SCSIndexedContentDelegate, SCSContentData;

/**
 SCSContent subprotocol defining types of content that contains indexed data.
 */
@protocol SCSIndexedContent <SCSContent>

/**
 Delegate for receiving notifications about this content.
 @see SCSIndexedContentDelegate
 @see SCSContentDelegate
 */
@property (nonatomic, weak) NSObject<SCSIndexedContentDelegate> *delegate;

/**
 Indicates whether or not this content is able to load more data.
 */
@property (nonatomic, readonly) BOOL canLoadMore;

/**
 Number of items contained in this content.
 
 When this value is expected to change, the appropriate delegate calls should be made.

 @return Number of items in this indexed content.
 @see SCSIndexedContentDelegate
 */
- (NSUInteger)numberOfItems;

/**
 Returns the SCSContentData instance representing the data at the given index.

 @param index Content index.

 @return SCSContentData instance for the given index, or `nil` if none was found.
 */
- (NSObject<SCSContentData>*)dataForItemAtIndex:(NSUInteger)index;

/**
 Returns the index where the content can be found that matches the given ID.

 @param contentDataId Content ID to find.

 @return Index for the corresponding data, or NSNotFound if no content was found with that ID.
 */
- (NSUInteger)indexOfObjectWithContentDataId:(NSString*)contentDataId;

@optional

/**
 If this content controller is capable of loading more data, this method indicates whether or not the controller is currently fetching more data.
 
 @see canLoadMore
 @see loadMoreContent:
 */
@property (nonatomic, readonly, getter=isLoadingMore) BOOL loadingMore;

/**
 If this content controller is capable of loading more data, this method initiates a request to load more content.

 @param completionBlock Completion block when more content is loaded.
 */
- (void)loadMoreContent:(void(^)(NSError* error))completionBlock;

@end
