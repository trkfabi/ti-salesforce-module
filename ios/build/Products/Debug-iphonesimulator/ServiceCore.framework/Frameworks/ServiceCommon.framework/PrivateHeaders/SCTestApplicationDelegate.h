//
//  SCTestApplicationDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/5/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#ifdef DEBUG
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SFCNetworkDelegate;

/**
 The boilerplate app delegate implementing the test application behavior.
 
 A test application need only specify this class, or a subclass of it, within the `main.m` file of the app to provide this behavior; no custom app delegate is necessary.  For example:
 
     int main(int argc, char * argv[]) {
         @autoreleasepool {
             return UIApplicationMain(argc, argv, nil, @"SCTestApplicationDelegate");
         }
     }
 */
@interface SCTestApplicationDelegate : UIResponder<UIApplicationDelegate>

/**
 Command-line arguments supplied to the application at runtime.  To specify default values, add a dictionary of key/value pairs to the `SCSDefaultArguments` Info.plist for the application.
 
 Any command line arguments supplied to the application (either through the scheme settings, or through an XCUITest launch argument) will be present in the `commandLineArguments` property.  One special argument, the `mockBundles` argument, accepts a comma-separated list of bundle identifiers to use when connecting mock network delegate datasources.
 
 Subclasses of SCTestApplicationDelegate can create their own abstract properties that exposes values returned from the commandLineArguments property to configure various aspects of the application.
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,NSString*> *commandLineArguments;

/**
 The array of network mocks to manage.  When set to `nil` it will automatically register mock instances from the command-line `mockBundles` argument, which is expected to be a comma-separated list of bundle IDs.
 */
@property (null_resettable, nonatomic, copy) NSArray<NSObject<SFCNetworkDelegate>*> *networkMocks;

/**
 Title to show on the root view controller.  Defaults to the name of the app.

 @return Application title string.
 */
- (NSString*)applicationTitle;

/**
 If the splitview controller used needs to be customized, this method can be overridden to specify a different class.

 @return Class to use when constructing the UISplitViewController.
 */
- (Class)splitViewControllerClass;

/**
 If the navigation controllers used within the application need to be customized, this method can be overridden to specify a different class.

 @return Class to use when constructing UINavigationController instances.
 */
- (Class)navigationControllerClass;

/**
 If the `SCTestListTableViewController` needs to be extended to provide additional capabilities (e.g. adding toolbar or navigation bar items for options and settings), this method can be overridden to return the name of a subclass to use.

 @return Subclass of SCTestApplicationDelegate to use when constructing the root view controller.
 */
- (Class)rootViewControllerClass;

@end

NS_ASSUME_NONNULL_END
#endif
