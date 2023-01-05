//
//  NSArray+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 10/5/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (ServiceCommon)

- (BOOL)scs_allItemsConformToProtocol:(Protocol*)protocol;
- (BOOL)scs_allItemsAreKindOfClass:(Class)klass;

@end
