//
//  SCTestListTableViewController.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/5/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#ifdef DEBUG
#import <UIKit/UIKit.h>

@class SCTestListTableViewController, SCTestApplicationDelegate;

/**
 Protocol that view controllers within test applications can comform to in order for top-level controllers to appear.
 
 This allows the boilerplate of presenting testable options within a test application to be abstracted out.  All view controllers implementing this protocol will automatically be shown on the root of the application.
 */
@protocol SCTestViewController <NSObject>

@optional

/**
 Title for this test controller.  If this is not implemented, it defaults to the test controller's class name.

 @param viewController Test list table view controller this item will be added to.
 @return String title.
 */
+ (NSString*)titleForViewInTestList:(SCTestListTableViewController*)viewController;

/**
 Optional relative order for this class to appear in the table.  If not implemented, the order is somewhat random.

 @param viewController Test list table view controller this item will be added to.
 @return Relative integer value for the position in the table.
 */
+ (NSInteger)orderInTestList:(SCTestListTableViewController*)viewController;

/**
 If implemented, this method is invoked immediately upon application launch.

 @param appDelegate Application delegate that is launching.
 */
+ (void)applicationStarting:(SCTestApplicationDelegate*)appDelegate;

@end

/**
 The table view controller that presents the list of test controllers.
 
 If the `-[SCTestApplicationDelegate rootViewControllerClass]` method is implemented, you can specify a subclass of this class to be used when constructing the view hierarchy.  This allows the behavior of the test list controller to be extended.
 */
@interface SCTestListTableViewController : UITableViewController

/**
 The navigation controller presented within the detail stack.
 */
@property (nonatomic, weak) UINavigationController *detailNavigationController;

@end
#endif
