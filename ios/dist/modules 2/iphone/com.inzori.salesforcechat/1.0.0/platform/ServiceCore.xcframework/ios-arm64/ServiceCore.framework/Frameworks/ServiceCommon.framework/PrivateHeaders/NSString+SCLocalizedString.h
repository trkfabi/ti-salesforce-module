//
//  NSString+SCLocalizedString.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/10/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Localization support for Service Cloud SDK internal implementations.
 */
@interface NSString (SCLocalizedString)

/** Returns a localized string with the given key, and the supplied table.
 
 The keys used in here may be overridden by a host application; the key in this case is prepended with the string "ServiceCloud." and the main bundle's default localization table is searched.  If a localization is supplied for that matching key, the result is returned.  Otherwise the localization falls back to the framework-supplied localization within the indicated table.

 @warning This method should not be used directly, but should rather be accessed using a table-specific macro allowing the `genstrings` command to easily identify uses of localizable strings.
 @param key        Localizable key.
 @param table      Table to use, or `nil` if the default table should be used.  Within Service Cloud, this value should always be supplied.
 @param identifier Bundle identifier to use to find the string table.
 @return Localized string.
 */
+ (nullable NSString*)overridableLocalizedStringForKey:(nonnull NSString*)key table:(nullable NSString*)table bundleIdentifier:(nullable NSString*)identifier;

+ (nullable NSString*)overridableLocalizedStringForKey:(nonnull NSString*)key table:(nullable NSString*)table __deprecated;

@end

#define SCCommonLocalizedString(key) [NSString overridableLocalizedStringForKey:key table:@"ServiceCommon" bundleIdentifier:@"com.salesforce.ServiceSDK"]
