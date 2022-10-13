//
//  SCSImageAction.h
//  ServiceCommon
//
//  Created by Qingqing Liu on 04/01/2016.
//  Copyright © 2016 salesforce.com. All rights reserved.
//

@import SalesforceCore.SalesforceNetwork;

/** This class is responsible for downloading an iamge from a remote URL */
@interface SCSImageAction : SFCSalesforceAction

/** Creates an instance of `SCSImageAction` to download image from remote 
 
@param imageUrl Image url
@param responseBlock Block to be invoked after image is downloaded from remote. 
 */
+ (nonnull SCSImageAction *)actionToGetImage:(nonnull NSURL *)imageUrl withResponseBlock:(nullable SFCActionResponseBlock)responseBlock;

@end
