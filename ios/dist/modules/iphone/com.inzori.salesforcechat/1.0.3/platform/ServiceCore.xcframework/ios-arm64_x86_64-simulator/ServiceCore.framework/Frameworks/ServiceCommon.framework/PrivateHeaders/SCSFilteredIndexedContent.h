//
//  SCSFilteredIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSBaseIndexedContent.h"

/**
 Wraps around SCSIndexedContent and filters the output to maximumRows number of items.
 
 @see SCSIndexedContent
 */
@interface SCSFilteredIndexedContent : SCSBaseIndexedContent

/**
 The SCSIndexedContent instance supplied to the constructor.
 */
@property (nonatomic, strong, readonly) NSObject<SCSIndexedContent> *content;

/**
 The maximum number of rows to return.
 
 Changing this property will result in the appropriate delegate calls to be sent, if the nested content contains more than the previous value of this property allowed for.  Settings this value to `NSUIntegerMax` will mean no filtering will occur.
 */
@property (nonatomic, assign) NSUInteger maximumRows;

/**
 Designated initializer to construct a filtered content controller.

 @param content Nested content controller to filter.

 @return Initialized content controller.
 */
- (instancetype)initWithContent:(NSObject<SCSIndexedContent>*)content NS_DESIGNATED_INITIALIZER;

@end

