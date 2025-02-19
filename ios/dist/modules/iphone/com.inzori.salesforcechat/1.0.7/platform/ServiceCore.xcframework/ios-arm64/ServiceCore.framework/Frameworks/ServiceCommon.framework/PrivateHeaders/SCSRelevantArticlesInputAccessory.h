//
//  SCSRelevantArticlesInputAccessory.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 4/21/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCSRelevantArticlesInputAccessory;

/**
 Delegate for consumers of a SCSRelevantArticlesInputAccessory controller.
 */
@protocol SCSRelevantArticlesInputAccessoryDelegate <NSObject>

@optional

/**
 Notifies the receiver when the relevant article accessory will begin loading results.

 @param relevantAccessory Accessory that is beginning to load results.
 @param page The page being loaded.
 */
- (void)relevantArticlesAccessory:(UIViewController<SCSRelevantArticlesInputAccessory>*)relevantAccessory
                 beginLoadingPage:(NSUInteger)page;

/**
 Notifies the receiver when the relevant article accessory finishes loading its results, with an optional error.

 @param relevantAccessory Accessory that has finished loading
 @param page The page being loaded.
 @param error Error object, if an error occurred, otherwise `nil`.
 */
- (void)relevantArticlesAccessory:(UIViewController<SCSRelevantArticlesInputAccessory>*)relevantAccessory
              finishedLoadingPage:(NSUInteger)page
                totalArticleCount:(NSUInteger)count
                            error:(nullable NSError*)error;

/**
 Notifies the receiver that the user wishes to show the related articles.
 
 If this method is not implemented, the default behavior will be to perform whatever action is made when the `[SCSRelevantArticlesInputAccessory showRelatedArticles:sender:]` method is invoked.  If this method is implemented however, no action will automatically be taken on behalf of the user tapping on the related articles label, and the receiver implementing this method must present the appropriate UI.

 @param relevantAccessory Accessory that has finished loading
 @param sender View that triggered the action.
 */
- (void)relevantArticlesAccessory:(UIViewController<SCSRelevantArticlesInputAccessory>*)relevantAccessory
              showRelatedArticles:(nullable id)sender;

@end

/**
 Protocol defining the interface available to consumers of relevant articles.  This controller can be returned by requesting a view controller using the `SCUServiceEventRelevantArticles` event.
 
 The following SCSEvent userInfo keys are supported

 - `sourceController` - The source controller that is requesting the accessory input.
 - `searchTerms` - An `NSSet<NSString*>` list of search terms to initialize the controller with.
 
 When returned it is assumed the view controller will be added as a child view controller of the parent.  It's important to note that the `inputAccessoryView` is meant to be used within the keyboard's `inputAccessoryView`, not the `view` itself.
 */
@protocol SCSRelevantArticlesInputAccessory <NSObject>

/**
 Delegate to receive updates due to changes in the contents of the accessory controller.
 */
@property (nullable, nonatomic, weak) NSObject<SCSRelevantArticlesInputAccessoryDelegate> *inputAccessoryDelegate;

/**
 The set of search terms to use.  The values are aggregated together to perform the appropriate article searches.
 */
@property (nullable, nonatomic, copy) NSSet<NSString*> *searchTerms;

/**
 The number of articles returned.
 */
@property (nonatomic, assign, readonly) NSUInteger numberOfArticles;

/**
 Indiciates whether or not the controller is actively loading articles/
 */
@property (nonatomic, assign, readonly, getter = isLoadingArticles) BOOL loadingArticles;

/**
 The page size to use, defaults to `20`.
 */
@property (nonatomic, assign) NSUInteger pageSize;

/**
 The view to add to the calling controller's view hierarchy to be used when displaying results, if needed.
 */
@property (null_resettable, nonatomic, strong, readonly) UIView *inputAccessoryView;

/**
 Overrides the root category and category group names to use when performing searches.  If unspecified, it defaults to the values defined within SCServiceConfiguration.

 @param rootCategoryName Root category name.
 @param groupName Category group name.
 */
- (void)setRootCategory:(NSString*)rootCategoryName inCategoryGroup:(NSString*)groupName;

/**
 Allows the caller to explicitly show the related articles, instead of waiting for a user action.

 @param animated Animated.
 @param sender Optional sender that triggered the action.
 */
- (void)showRelatedArticles:(BOOL)animated sender:(nullable id)sender;

/**
 Identifies whether or not related article searches are supported within the current user.  This performs several checks to ensure the knowledge configuration is valid.  This must be performed at least once per user to determine whether or not the related articles support can be used.

 @param completion Completion block that is used to determine whether or not relevant article support is available to this user.
 */
- (void)areRelatedArticlesSupported:(void(^)(BOOL relatedArticlesSupported))completion;

@end

NS_ASSUME_NONNULL_END
