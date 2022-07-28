//
//  SCSExpandableIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSIndexedContentList.h"

/**
 Implementation of a SCSIndexedContentList controller that has support to expand and collapse a list of sections.  As sections are expanded or collapsed, the appropriate delegate methods are called to communicate the changes in rows and row counts.
 */
@interface SCSExpandableIndexedContent : NSObject<SCSIndexedContentList>

/**
 Set of indexes to be expanded.
 */
@property (nonatomic, copy) NSIndexSet *expandedIndexes;

/**
 Nested content controller supplied to the constructor.

 @see SCSIndexedContentList
 */
@property (nonatomic, strong, readonly) NSObject<SCSIndexedContentList> *content;

/**
 Designated initializer used to construct a content controller with.

 @param content Content controller to act as the source for the content list.

 @return Initialized content list.
 */
- (instancetype)initWithContent:(NSObject<SCSIndexedContentList>*)content NS_DESIGNATED_INITIALIZER;

@end
