//
//  SCSIndexedContentList.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSContent.h"
#import "SCSIndexedContentListDelegate.h"

@protocol SCSIndexedContent, SCSIndexedContentListDelegate;

/**
 Protocol defining content controllers that are capable of managing lists of indexed content.
 */
@protocol SCSIndexedContentList <SCSContent>

/**
 Array of indexed content controllers contained within this content list.
 */
@property (nonatomic, strong, readonly) NSArray *indexedContentList;

/**
 Delegate for receiving notifications about this content.
 @see SCSIndexedContentListDelegate
 @see SCSContentDelegate
 */
@property (nonatomic, weak) NSObject<SCSIndexedContentListDelegate> *delegate;

/**
 Inserts a new indexed content controller at the given section.

 @param content SCSIndexedContent to insert.
 @param section Section to insert the section at.

 @return `YES` if the content was successfully inserted.
 */
- (BOOL)insertIndexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section;

/**
 Replaces the content at the given section with a new SCSIndexedContent controller.

 @param section Section to replace the current content controller.
 @param content SCSIndexedContent controller to substitute.

 @return `YES` if the content was successfully replaced.
 */
- (BOOL)replaceIndexedContentAtSection:(NSUInteger)section withContent:(NSObject<SCSIndexedContent>*)content;

/**
 Moves the content from one section to another.

 @param fromSection Index for the content at its current location.
 @param toSection   New index for the content.

 @return `YES` if the content was moved successfully.
 */
- (BOOL)moveIndexedContentFromSection:(NSUInteger)fromSection toSection:(NSUInteger)toSection;

/**
 Removes the content from the indicated section.

 @param section Section to remove the content from.

 @return The SCSIndexedContent object that was removed, or `nil` if no content was found at that section.
 */
- (NSObject<SCSIndexedContent>*)removeIndexedContentAtIndex:(NSUInteger)section;

/**
 Returns the SCSIndexedContent at the given section.

 @param section Section to retrieve the content from.

 @return SCSIndexedContent instance, or `nil` if no content was found at that section.
 */
- (NSObject<SCSIndexedContent>*)indexedContentAtSection:(NSUInteger)section;

/**
 Returns the SCSContentData located at the section and row indicated by the supplied index path.

 @param indexPath Index path to locate the data at.

 @return SCSContentData instance at the given section and row, or `nil` if no data is found.
 */
- (NSObject<SCSContentData>*)dataForItemAtIndexPath:(NSIndexPath*)indexPath;

/**
 Returns the current number of sections in the content list.

 @return Number of sections.
 */
- (NSUInteger)numberOfSections;

/**
 Returns the number of items contained in the SCSIndexedContent instance at the supplied section.

 @param section Section to retrieve the item list from.

 @return Number of items in the given section.
 */
- (NSUInteger)numberOfItemsInSection:(NSUInteger)section;

/**
 Returns the index within the content list where the given indexed content object may be found.

 @param content Indexed content object.

 @return Section index where this nested content is found, or `NSNotFound` if the content could not be found.
 */
- (NSUInteger)indexOfNestedContent:(NSObject<SCSIndexedContent>*)content;

@optional

/**
 Performs the given block of updates within a batch, allowing multiple operations to be unified under a single set of delegate responses.
 
 @warning This is an optional method, and not all classes conforming to SCSIndexedContentList may implement this method.

 @param updates Block of updates to batch together.
 */
- (void)performBatchUpdates:(void(^)(void))updates;

/**
 Returns the index within the content list where the nested content with the given name may be found.

 @param name Content name.

 @return Section index where this nested content is found, or `NSNotFound` if the content could not be found.
 */
- (NSUInteger)indexOfNestedContentWithName:(NSString*)name;

/**
 Returns the index path where the object with the given content ID is found.

 @param contentDataId Content data ID to find.

 @return Index path for where this content is found, or `nil` if no content with that ID could be found.
 */
- (NSIndexPath*)indexPathOfObjectWithContentDataId:(NSString *)contentDataId;

@end
