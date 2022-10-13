/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  Class to handle screen annotations. This class implements the `SOSWebRTCDelegate`.
 */
@interface SOSScreenAnnotations: NSObject

/**
 *  If enabled, will allow drawing on the current screen by the service agent.
 *
 *  Default: `YES`
 *
 *  @note if you set this to `NO` while screen sharing is active, it will execute `-stop`.
 */
@property (atomic) BOOL enabled;

/**
 *  When enabled all touch events will clear the screen of annotations, unless the Agent is currently drawing.<br/>
 *  If you wish to handle clearing annotations yourself set this to `NO`.
 *
 *  Default: `YES`
 */
@property (atomic) BOOL clearOnTouches;

/**
 *  Customizable color of the line drawing feature.
 *  Will not change the color of existing lines on the screen.
 *
 *  Default: `[UIColor redColor]`
 */
@property (nonatomic) UIColor *lineColor;

/**
 *  Customizable width of the line drawing feature.
 *  Does not change the width of existing lines on the screen.
 *
 *  Default: `5.0f`
 */
@property (nonatomic) CGFloat lineWidth;

/**
 *  Clears the current annotation by reinitializing the drawer.
 */
- (void)clearDraw;

/**
 *  Initiates the drawing feature.
 */
- (void)start;

/**
 *  Stops the drawing feature.
 */
- (void)stop;

@end
