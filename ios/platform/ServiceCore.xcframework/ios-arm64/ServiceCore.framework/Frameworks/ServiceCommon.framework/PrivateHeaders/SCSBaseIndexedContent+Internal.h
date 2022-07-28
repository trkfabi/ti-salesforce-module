//
//  SCSBaseIndexedContent+Internal.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSBaseIndexedContent.h"
#import "SCSBaseContent+Internal.h"

@interface SCSBaseIndexedContent (Internal)

- (void)delegate_contentReloaded;
- (void)delegate_didChangeItemCount:(NSUInteger)itemCount;
- (void)delegate_didInsertItemsAtIndexes:(NSIndexSet*)indexes;
- (void)delegate_didDeleteItemsAtIndexes:(NSIndexSet*)indexes;
- (void)delegate_didReloadItemsAtIndexes:(NSIndexSet*)indexes;
- (void)delegate_didMoveItemAtIndex:(NSInteger)oldIndex toIndex:(NSInteger)index;

@end
