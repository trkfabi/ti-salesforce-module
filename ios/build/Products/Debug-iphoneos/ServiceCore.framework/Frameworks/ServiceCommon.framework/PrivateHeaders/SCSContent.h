//
//  SCSContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSContentDelegate.h"

@protocol SCSContentData, SCSContentDelegate;

/**
 Protocol defining the interface for a content controller capable of returning loadable content.
 */
@protocol SCSContent <NSObject>

/**
 Unique name to identify the given piece of content by.  Can be used in conjunction with nestedContentWithName:.
 */
@property (nonatomic, copy) NSString *name;

/**
 Delegate for receiving notifications about this content.
 @see SCSContentDelegate
 */
@property (nonatomic, weak) NSObject<SCSContentDelegate> *delegate;

/**
 Indicates whether or not this content should be considered empty.
 */
@property (nonatomic, assign, readonly, getter = isEmpty) BOOL empty;

/**
 Indicates whether or not this content is loading from its source.
 */
@property (nonatomic, readonly, getter=isLoading) BOOL loading;

@optional

/**
 Indicates whether or not the contentWillBeginUpdates: and contentDidEndUpdates: should be sent only when more substantive delegate messages are sent from within them.

 This prevents empty "willBegin" and "didEnd" calls with nothing else.
 */
@property (nonatomic, assign, getter=shouldDeferDelegateUpdateCalls) BOOL deferDelegateUpdateCalls;

/**
 Result data this content instance represents.
 
 @note
 This method is optional because some types of content may not have a single object that can represent it.  Examples are content classes that conform to SCSIndexedContent; the content may only be available when a given index is also supplied.

 @return Object conforming to SCSContentData, or `nil` if no content is available.
 @see SCSContentData
 */
- (NSObject<SCSContentData>*)contentData;

/**
 Optional method used to cause the data to be loaded from its source.
 
 Not all types of content may be loaded from its source, so ensure that the content implements this method.

 @param completionBlock Completion block when the content has been loaded.
 */
- (void)loadContent:(void(^)(NSError* error))completionBlock;

/**
 Optional method that returns an SCSContent instance with the supplied name which may be nested within this instance.
 
 Some content controllers may wrap or embed other nested content controllers inside of it.  If a content controller does this, it should implement this method to allow consumers of this controller to find and use those child controllers based on their supplied name.

 @param name Name to find the nested content with.

 @return The SCSContent instance with the given name, or `nil` if none was found.
 */
- (NSObject<SCSContent>*)nestedContentWithName:(NSString*)name;

@end
