//
//  SCSLinkPreviewLoader.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 11/19/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCSLinkPreviewData.h"
#import "SCSLinkPreviewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCSLinkPreviewLoader : NSObject  <SCSLinkPreviewDelegate>

- (void)getLinkPreviewForURL:(NSURL *)url completion:(void (^)(SCSLinkPreviewData *previewData, NSError *error))completion;
- (void)viewControllerForURL:(NSURL *)url completion:(void (^)(UIViewController *previewController, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
