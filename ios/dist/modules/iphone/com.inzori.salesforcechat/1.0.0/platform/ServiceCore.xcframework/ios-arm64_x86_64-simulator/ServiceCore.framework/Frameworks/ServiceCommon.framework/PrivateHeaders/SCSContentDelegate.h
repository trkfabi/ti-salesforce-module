//
//  SCSContentDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCSContent;

@protocol SCSContentDelegate <NSObject>

@optional

- (void)contentWillLoadContent:(NSObject<SCSContent>*)content;
- (void)contentDidLoadContent:(NSObject<SCSContent>*)content;
- (void)content:(NSObject<SCSContent>*)content didReceiveError:(NSError*)error;
- (void)contentWillBeginUpdates:(NSObject<SCSContent>*)content;
- (void)contentDidEndUpdates:(NSObject<SCSContent>*)content;
- (void)content:(NSObject<SCSContent>*)content becameInvalidWithError:(NSError*)error;

@end

NS_ASSUME_NONNULL_END
