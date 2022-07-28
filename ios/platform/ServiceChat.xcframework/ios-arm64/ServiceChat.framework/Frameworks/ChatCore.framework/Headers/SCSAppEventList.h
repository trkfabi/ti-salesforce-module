//
//  SCSAppEventList.h
//  ChatCore
//
//  Created by Jeremy Wright on 2021-11-16.
//  Copyright © 2021 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**

 The `SCSAppEventList` allows for matching specific schemes of URLs which may be received remotely.
 When a matching URL is detected it is removed from the original message, and results in a URL event which
 is flagged as being an AppEvent.

 @see `SCSChatInterface`
 */
@interface SCSAppEventList : NSObject <NSCopying>


/**
 Initializer for generating a matching scheme for AppEvent URLs

 @param scheme the matching scheme to be applied against all incoming URLs.
 */
- (instancetype)initWithScheme:(NSString *)scheme;

/**
 Add a description to be associated with the matched URL.
 @param description The description for the associated URL.
 @param path The specific path on the URL which to associate with the description.
*/
- (void)addDescription:(NSString *)description forPath:(NSString *)path;

/**
 Add a description to be associated with the matched URL.
 Matching will occur in the order that the descriptions are added. You should add patterns
 in order: from the most specific to the most generic.

 For example if you add ".*" as an expression first, that will always match all paths provided on this instance.
 Note: Expressions are given priority when returning an associated description. It is recommended to
 use either direct path matching, or regex matching. Not both.

 @param description The description for the associated URL.
 @param expression The regex expression which will be used to match against a provided url.
 The pattern must be a valid regex expression or it will be ignored.
*/
- (void)addDescription:(NSString *)description withExpression:(NSString *)expression;

/**
 Returns the description associated with the given path.
 The list of patterns will be searched in-order first. If no matches are found then it will attempt to directly
 match the description from the given path.

 @param path The description for the associated URL.
*/
- (nullable NSString *)descriptionForPath:(NSString *)path;

@property (nonatomic, readonly, strong) NSString *scheme;

@end

NS_ASSUME_NONNULL_END
