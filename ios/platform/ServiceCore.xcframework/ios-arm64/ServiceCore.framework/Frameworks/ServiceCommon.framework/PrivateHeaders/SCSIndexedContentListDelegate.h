//
//  SCSIndexedContentListDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSContentDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCSIndexedContentList, SCSIndexedContent;

//SCSIndexedContentListDelegate should inherit from SCSIndexedContentDelegate.
//Refer to comments on this pull request:
//https://git.soma.salesforce.com/embeddedService/ServiceSDK-iOS/pull/119

@protocol SCSIndexedContentListDelegate <SCSContentDelegate>

@optional

- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didLoadAllContentWithErrors:(nullable NSArray<NSError*>*)errors;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didReloadIndexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didAddIndexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didMoveIndexedContent:(NSObject<SCSIndexedContent>*)content fromSection:(NSUInteger)fromSection toSection:(NSUInteger)toSection;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didReplaceIndexedContent:(NSObject<SCSIndexedContent>*)oldContent withLoadableContent:(NSObject<SCSIndexedContent>*)newContent atSection:(NSUInteger)section;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList didRemoveIndexedContent:(NSObject<SCSIndexedContent>*)content fromSection:(NSUInteger)fromSection;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section didInsertItemsAtIndexes:(NSIndexSet*)indexes;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section didDeleteItemsAtIndexes:(NSIndexSet*)indexes;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section didReloadItemsAtIndexes:(NSIndexSet*)indexes;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContentWillLoadContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContentDidLoadContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section;
- (void)contentList:(NSObject<SCSIndexedContentList> *)contentList indexedContent:(NSObject<SCSIndexedContent> *)content atSection:(NSUInteger)section didReceiveError:(NSError *)error;
- (void)contentList:(NSObject<SCSIndexedContentList>*)contentList indexedContent:(NSObject<SCSIndexedContent>*)content atSection:(NSUInteger)section didMoveItemAtIndex:(NSInteger)oldIndex toIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
