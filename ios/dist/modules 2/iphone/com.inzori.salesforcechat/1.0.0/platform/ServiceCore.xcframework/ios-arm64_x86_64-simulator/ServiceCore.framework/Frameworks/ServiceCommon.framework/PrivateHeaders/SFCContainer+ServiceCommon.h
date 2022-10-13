//
//  SFCContainer+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-12-04.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@import SalesforceCore;

NS_ASSUME_NONNULL_BEGIN

SFC_EXTERN NSString * const SFCContainerServiceIdentifier;

@interface SFCContainer (ServiceCommon)

+ (instancetype)serviceContainer;

@end

NS_ASSUME_NONNULL_END
