//
//  SCSMinimizedThumbnailAnimator.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-03-18.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SCSMinimizedAttachmentAnimatorOptions) {
    SCSMinimizedAttachmentAnimatorOptionScaleWindow     = 1 <<  0,
    SCSMinimizedAttachmentAnimatorOptionFadeWindow      = 1 <<  1,
    SCSMinimizedAttachmentAnimatorOptionScaleAttachment = 1 <<  2,
    SCSMinimizedAttachmentAnimatorOptionFadeAttachment  = 1 <<  3,
};

@interface SCSMinimizedAttachmentAnimator : NSObject <UIViewControllerAnimatedTransitioning>

- (instancetype)initWithOptions:(SCSMinimizedAttachmentAnimatorOptions)options NS_DESIGNATED_INITIALIZER;

@end
