//
//  SCSLinkPreviewDelegate.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 12/3/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSLinkPreviewData.h"
#import "SCSEvent.h"
@protocol SCSLinkPreviewDelegate <NSObject>

@optional
/**
 Message sent to the delegate when the preview data is loaded for an article.

 @param previewData  Preview data for an article.
 @see `SCSLinkPreviewData`
 */
- (void)articlePreviewEvent:(SCSEvent*_Nonnull)event didLoadPreviewData:(nullable SCSLinkPreviewData*)previewData error:(nullable NSError*)error;

/**
 Message sent to the delegate when the viewController is loaded for an article.

 @param viewController  Viewcontroller for the selected article.
 */
- (void)articlePreviewEvent:(SCSEvent*_Nonnull)event didLoadArticleViewController:(nullable UIViewController*)viewController error:(nullable NSError*)error;

@end

