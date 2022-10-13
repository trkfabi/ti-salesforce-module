//
//  SCSOutgoingCollectionViewCell.h
//  ServiceCommon
//
//  Created by Thomas Myrden on 2017-08-03.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCSMessagingCollectionViewCell.h"

@interface SCSOutgoingCollectionViewCell : SCSMessagingCollectionViewCell

@property (nonatomic, weak, readonly) UIProgressView *progressView;

@end
