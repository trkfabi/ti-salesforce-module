//
//  SCSMessagingCollectionViewController.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-10-31.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCPrivateDefines.h"

NS_ASSUME_NONNULL_BEGIN

// These cell reuse identifiers are already registered to the collection view upon initialization
// These enum values should be used to dequeue the reusable cells in your subclass
typedef NSString * SCSMessagingCellReuseIdentifier SCS_EXTENSIBLE_STRING_ENUM;

// SCSOutgoingCollectionViewCell
SCS_EXTERN SCSMessagingCellReuseIdentifier const SCSMessagingCellReuseIdentifierOutgoing;
// SCSIncomingCollectionViewCell
SCS_EXTERN SCSMessagingCellReuseIdentifier const SCSMessagingCellReuseIdentifierIncoming;
// SCSSystemCollectionViewCell
SCS_EXTERN SCSMessagingCellReuseIdentifier const SCSMessagingCellReuseIdentifierSystem;
// SCSTypingCollectionViewCell
SCS_EXTERN SCSMessagingCellReuseIdentifier const SCSMessagingCellReuseIdentifierTyping;

@class SCSMessagingInputViewController;
@interface SCSMessagingCollectionViewController : UIViewController <UICollectionViewDelegate>

/**
 Collection view for displaying messages
 */
@property (nonatomic, readonly, nullable) UICollectionView *collectionView;

/**
 ViewController that is responsible to text input and menus
 */
@property (nonatomic, readonly) SCSMessagingInputViewController *inputController;

/**
 Override this method in subclass to receive notification of messages being sent

 @param contents id with contents of the UITextView submission (typically NSString)
 */
- (void)didPressSendWithMessageContents:(id)contents;

/**
 Override this method in subclass to receive notification of text change in input view

 @param contents id with contents of the UITextView (typically NSString)
 */
- (void)didChangeInputViewText:(id)contents;

/**
 Override this method in subclass to receive notification of text view becoming focused
 */
- (void)didBeginInputViewEditing;

/**
 Override this method in subclass to receive notification of text view becoming unfocused
 */
- (void)didEndInputViewEditing;

/**
 Call this method to inform the CollectionView to scroll to the most recent message

 @param animated BOOL whether the scroll to the most recent message is animated
 */
- (void)scrollToMostRecentMessage:(BOOL)animated;

@end

@interface SCSMessagingCollectionViewController (UICollectionViewDelegate)

/**
 *  SCSMessagingCollectionViewController implements these methods for message bubble copying.
 *  If you choose for your subclass to become the delegate for the collectionView,
 *  your subclass must call super in these methods to maintain copy functionality.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath NS_REQUIRES_SUPER;
- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_REQUIRES_SUPER;
- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_REQUIRES_SUPER;

@end

@interface SCSMessagingCollectionViewController (UIScrollViewDelegate)

/**
 *  SCSMessagingCollectionViewController implements these methods to handle edge cases
 *  with the interactive scroll dismissal feature. If you choose for your subclass to become
 *  the delegate for the collectionView, your subclass must call super in these methods.
 */
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView NS_REQUIRES_SUPER;
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
