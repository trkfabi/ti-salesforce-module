//
//  NSBundle+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-12-15.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (ServiceCommon)

@property (nonatomic, copy, nullable) NSString *previousCompatabilityVersion;
@property (nonatomic, strong, readonly) NSString *currentCompatiabilityVersion;

@end

NS_ASSUME_NONNULL_END
