//
//  SCSWindowManager.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 9/19/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Singleton used to manage windows, the relationship between windows, and to manage the statusbar styling when the `needsStatusbarOverrides` returns `YES`.
 */
@interface SCSWindowManager : NSObject

/**
 The primary application window from the host app.  If `nil`, it defaults to the initial window.
 */
@property (nullable, nonatomic, weak) UIWindow *primaryWindow;

/**
 The window that status bar context should be taken from.  This defaults to `primaryWindow`.
 */
@property (null_resettable, nonatomic, weak) UIWindow *statusbarContextWindow;

/**
 The currently-active window that UIKit will believe is responsible for the statusbar appearance.
 */
@property (nonatomic, weak, readonly) UIWindow *activeStyleWindow;

/**
 Indicates if view controller-based status bar styling has been opted-in within this application.
 */
@property (nonatomic, assign, readonly) BOOL needsStatusbarOverrides __TVOS_PROHIBITED;

/**
 Indicates whether or not any subclasses of SCSWindow are present.
 */
@property (nonatomic, assign, readonly) BOOL hasServiceSDKWindows;

/**
 Shared singleton instance

 @return Shared window manager.
 */
+ (instancetype)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

/**
 Returns an array of all the visible, non-system windows, sorted by window level.  This ensures that system windows such as the text input or keyboard windows are omitted.

 @return Array of visible windows sorted by window level.
 */
- (NSArray<UIWindow*> *)visibleWindows;

/**
 Returns an array of windows used by the AV frameworks for video playback.
 
 @note This is an expensive operation, and shouldn't be called too frequently.
 @warning This method does not guarantee that all windows used for video playback will be returned, and hasn't been extensively tested in all circumstances.  This method may need to be updated in future releases to cover any edge-cases that are discoered.

 @return Array of windows used by the system for fullscreen video playback.
 */
- (NSArray<UIWindow*> *)videoPlaybackWindows;

@end

NS_ASSUME_NONNULL_END
