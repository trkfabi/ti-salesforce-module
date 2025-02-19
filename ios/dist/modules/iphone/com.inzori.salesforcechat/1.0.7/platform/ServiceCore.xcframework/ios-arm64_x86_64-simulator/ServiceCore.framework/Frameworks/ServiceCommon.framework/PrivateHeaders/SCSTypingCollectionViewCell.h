//
//  SCSTypingCollectionViewCell.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-12-19.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCSIncomingCollectionViewCell.h"

@class SCSPulsingMultiDotView;
@interface SCSTypingCollectionViewCell : SCSIncomingCollectionViewCell

@property (nonatomic, readonly) SCSPulsingMultiDotView *typingIndicatorView;

- (void)beginAnimating;

@end
