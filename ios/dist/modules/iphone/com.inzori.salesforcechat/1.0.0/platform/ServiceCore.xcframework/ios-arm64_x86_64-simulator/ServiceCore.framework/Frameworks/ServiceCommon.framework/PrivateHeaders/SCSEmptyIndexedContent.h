//
//  SCSEmptyIndexedContent.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/3/16
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import "SCSIndexedContent.h"

/**
 Implementation of an SCSIndexedContent controller that always returns 0 rows.
 
 This can be useful to fill in blank data, or to define placeholders for visual content.
 */
@interface SCSEmptyIndexedContent : NSObject <SCSIndexedContent>

@end
