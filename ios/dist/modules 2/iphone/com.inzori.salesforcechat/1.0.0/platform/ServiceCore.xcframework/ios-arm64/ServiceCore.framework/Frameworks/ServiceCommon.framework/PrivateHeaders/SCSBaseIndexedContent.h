//
//  SCSBaseIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSBaseContent.h"
#import "SCSIndexedContent.h"

/**
 Convenience base class that can be used to define SCSIndexedContent instances from.

 This class provides helper methods used to call delegates at the appropriate times, optionally with messages sent via a specific queue.
 @see SCSBaseContent
 @see SCSIndexedContent
 */
@interface SCSBaseIndexedContent : SCSBaseContent <SCSIndexedContent>

@end
