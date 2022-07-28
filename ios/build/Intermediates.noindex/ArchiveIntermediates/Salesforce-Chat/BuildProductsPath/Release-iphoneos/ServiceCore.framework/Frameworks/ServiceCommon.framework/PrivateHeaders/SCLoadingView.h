//
//  SCLoadingView.h
//  ServiceSDK
//
//  Created by Amit Gosar on 7/8/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSLoading.h"

@interface SCLoadingView : UIView <SCSLoading>

@property (nonatomic, strong) UIImageView *loadingImageView;
@property (nonatomic, strong) UIImage *loadingImage UI_APPEARANCE_SELECTOR;
@property (nonatomic) BOOL hidesWhenStopped;           // default is YES. calls -setHidden when animating gets set to NO

- (void)startAnimating;
- (void)stopAnimating;

@end