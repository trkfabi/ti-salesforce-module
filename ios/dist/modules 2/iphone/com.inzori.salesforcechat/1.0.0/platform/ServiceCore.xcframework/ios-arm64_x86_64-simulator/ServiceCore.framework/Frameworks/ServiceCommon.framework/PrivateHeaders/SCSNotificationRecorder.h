//
//  SCSNotificationRecorder.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 3/8/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define WAIT_FOR_NOTIFICATION(recorder__, name__, timeout__) \
    ({ \
        BOOL stillWaiting = YES; \
        NSDate *startedWaiting = [NSDate date]; \
        do { \
            for (NSNotification *notification in recorder__.notifications) { \
                if ([notification.name isEqualToString:name__]) { \
                    stillWaiting = NO; \
                    break; \
                } \
            } \
            XCTestExpectation *expectation = [self expectationWithDescription:@"Wait"]; \
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.33 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{ \
                [expectation fulfill]; \
            }); \
            [self waitForExpectationsWithTimeout:1.0 handler:^(NSError * _Nullable error) { \
                XCTAssertNil(error); \
            }]; \
        } while (stillWaiting && [startedWaiting timeIntervalSinceNow] * -1.0 < timeout__); \
        XCTAssertFalse(stillWaiting); \
    })

@interface SCSNotificationRecorder : NSObject

@property (nonatomic, strong, readonly) NSArray<NSNotification*> *notifications;

- (void)addObserverForName:(nullable NSNotificationName)aName object:(nullable id)anObject;
- (void)reset;

@end

NS_ASSUME_NONNULL_END
