//
//  NSString+LanguageConversion.h
//  ServiceCommon
//
//  Created by Aaron Eisses on 3/23/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (LanguageConversion)

/**
 Converts the a NSString representing a language and regional value into a corresponding
 language and region value that is supported by Salesforce org.
 
 @return A language and region string that Salesforce org supports.
 */
- (NSString * _Nullable)convertToSupportedLanguage;

@end
