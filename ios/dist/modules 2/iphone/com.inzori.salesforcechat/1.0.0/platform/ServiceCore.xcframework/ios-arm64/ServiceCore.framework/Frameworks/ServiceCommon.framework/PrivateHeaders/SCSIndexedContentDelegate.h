//
//  SCSIndexedContentDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSContentDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCSIndexedContent;

@protocol SCSIndexedContentDelegate <SCSContentDelegate>

@required

- (void)contentReloaded:(NSObject<SCSIndexedContent>*)content;

@optional

- (void)content:(NSObject<SCSIndexedContent>*)content didChangeItemCount:(NSUInteger)itemCount;
- (void)content:(NSObject<SCSIndexedContent>*)content didInsertItemsAtIndexes:(NSIndexSet*)indexes;
- (void)content:(NSObject<SCSIndexedContent>*)content didDeleteItemsAtIndexes:(NSIndexSet*)indexes;
- (void)content:(NSObject<SCSIndexedContent>*)content didReloadItemsAtIndexes:(NSIndexSet*)indexes;
- (void)content:(NSObject<SCSIndexedContent>*)content didMoveItemAtIndex:(NSInteger)oldIndex toIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
