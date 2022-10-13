//
//  SCSLinkPreviewData.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 11/19/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface SCSLinkPreviewData : NSObject

@property (nonatomic, readonly) NSString *previewTitle;
@property (nullable, nonatomic, readonly) NSString *previewDescription;
@property (nullable, nonatomic, readonly) UIImage *previewImage;
@property (nullable, nonatomic, readonly) UIImage *favIcon;

@property (nonatomic, readonly, getter=isArticle) BOOL article;

- (instancetype)initWithTitle:(NSString *)title decription:(nullable NSString *)description image:(nullable UIImage *)image favIcon:(nullable UIImage *)favIcon;
- (instancetype)initArticleWithTitle:(NSString *)title decription:(nullable NSString *)description image:(nullable UIImage *)image favIcon:(nullable UIImage *)favIcon;
@end

NS_ASSUME_NONNULL_END
