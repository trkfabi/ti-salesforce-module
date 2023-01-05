//
//  SCSBaseContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSContent.h"

/**
 Convenience base class that can be used to define SCSContent instances from.
 
 This class provides helper methods used to call delegates at the appropriate times, optionally with messages sent via a specific queue.
 @see SCSContent
 */
@interface SCSBaseContent : NSObject <SCSContent>

/**
 The dispatch queue used to execute operations.  If `nil`, it won't constrain to any specific queue.

 Default: dispatch_get_main_queue()
 */
@property (nullable, retain) dispatch_queue_t underlyingQueue;

@end
