//
//  SCEdgeContainerView.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/11/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Convenience view class that will allow touches to pass through to the superclass unless the touch is within a subview of this view.
 
 You can use this class when you want the background of a view to pass touches through, but for child UI elements to still intercept touches.
 */
@interface SCPassthroughView : UIView

@end
