//
//  SCSContentListController.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSIndexedContentList.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Implementation of a SCSIndexedContentList controller that notifies delegates on a specific underlying queue.
 */
@interface SCSContentListController : NSObject <SCSIndexedContentList>

/**
 Initializer that constructs a content list with an initial set of content controllers.

 @param firstObj `nil` terminated list of SCSIndexedContent controllers.

 @return Initialized content list controller.
 */
- (instancetype)initWithContentControllers:(NSObject<SCSIndexedContent>*)firstObj, ... NS_REQUIRES_NIL_TERMINATION;

/**
 Initializer that constructs a content list with an initial set of content controllers from an array.

 @param contentControllers Array of SCSIndexedContent controllers.

 @return Initialized content list controller.
 */
- (instancetype)initWithArray:(NSArray<NSObject<SCSIndexedContent>*>*)contentControllers;

/**
 Returns the total number of rows across all child content controllers.
 */
@property (nonatomic, readonly) NSUInteger totalRowCount;

/**
 The dispatch queue used to execute operations.  If `nil`, it won't constrain to any specific queue.
 
 Default: dispatch_get_main_queue()
 */
@property (nullable, retain) dispatch_queue_t underlyingQueue;

@end

NS_ASSUME_NONNULL_END
