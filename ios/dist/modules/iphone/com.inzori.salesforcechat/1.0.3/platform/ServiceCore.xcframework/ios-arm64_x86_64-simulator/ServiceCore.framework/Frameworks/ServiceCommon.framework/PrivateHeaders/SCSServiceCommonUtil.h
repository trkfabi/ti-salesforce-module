//
//  SCSServiceCommonUtil.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 9/28/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCSServiceCommonUtil : NSObject

/**
 *  Get the current os version for the device
 *
 *  @return A float value for the os version. The major version of the os will be the whole number, ie 7.01
 */
+ (float)osVersion;

/**
 *  Get the current os version for the device
 *
 *  @return A String value for the os version.
 */
+ (NSString *)osVersionName;

/**
 * Get the best matching consumer name for the hardware name of the device.
 */
+ (NSString *)deviceName;

/**
 * Get the hardware string identifier for the current device.
 */
+ (NSString *)hardwareString;

/**
 * Infers the frame of the keyboard if it returns an invalid CGRect.
 */
+ (NSNotification *)fixKeyboardFrame:(NSNotification *)notification window:(UIWindow *)window;

/**
 *  Get the current application version for the consuming app
 *
 *  @return A string value of the app version
 */
+ (NSString *)appVersion;

@end

NS_ASSUME_NONNULL_END
