//
//  NSString+SCOrgIdTrim.h
//  ServiceCommon
//
//  Created by Aaron Eisses on 1/5/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (SCOrgIdTrim)

- (NSString*)getFifteenDigitOrgIdFromId;

@end
