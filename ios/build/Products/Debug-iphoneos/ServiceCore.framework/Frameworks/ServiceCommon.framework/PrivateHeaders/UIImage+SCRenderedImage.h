//
//  UIImage+SCRenderedImage.h
//  ServiceSDK
//
//  Created by Amit Gosar on 6/5/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (SCRenderedImage)

+ (UIImage *)spinnerImageWithSize:(CGSize)size strokeColor:(UIColor*)strokeColor trackColor:(UIColor*)trackColor;
+ (UIImage *)imageFromColor:(UIColor *)color withSize:(CGSize)size;
+ (UIImage *)circularImageWithSize:(CGSize)size color:(UIColor*)color;

@end
