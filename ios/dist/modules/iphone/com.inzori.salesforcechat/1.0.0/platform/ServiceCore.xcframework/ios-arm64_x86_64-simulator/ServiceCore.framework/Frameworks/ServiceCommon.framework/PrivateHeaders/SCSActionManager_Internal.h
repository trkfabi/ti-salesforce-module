//
//  SCSActionManager_Private.h
//  ServiceCommon
//
//  Created by Amit Gosar on 4/13/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCManagedSingleton.h"
#import "SCCPrivateDefines.h"
#import "SCInterfaceRouter.h"

NS_ASSUME_NONNULL_BEGIN

@class SCSEdgeAttachment;
@protocol SCSActionItemContainer;
SCS_EXTERN NSString * const SCSActionManagerKey;

@interface SCSActionManager () <SCManagedSingleton>

@property (nonatomic, weak) SCInterfaceRouter *interfaceRouter;

@property (nullable, nonatomic, strong, readonly) SCSEdgeAttachment *actionViewAttachment;
@property (nonatomic, assign, readonly) BOOL hasActionViewAttachment;

- (void)setActionItemContainer:(UIViewController<SCSActionItemContainer> * _Nullable)actionItemContainer;

- (nullable __kindof UIView<SCSActionItem> *)delegate_viewForActionItemWithName:(NSString*_Nullable)name;

- (nullable __kindof UIViewController<SCSActionItemContainer> *)delegate_actionItemContainerViewController;

- (nullable NSSet<NSString*>*)actionsToShowForViewController:(nullable UIViewController*)controller;

- (BOOL)shouldShowActionWithName:(NSString*)name;

@end

NS_ASSUME_NONNULL_END
