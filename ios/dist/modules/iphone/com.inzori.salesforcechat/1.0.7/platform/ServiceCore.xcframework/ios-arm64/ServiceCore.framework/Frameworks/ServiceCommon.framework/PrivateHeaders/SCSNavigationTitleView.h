//
//  SCSNavigationTitleView.h
//  ServiceCommon
//
//  Created by Amisha Goyal on 4/28/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
/*
 View containing the titleLabel.
 */
@interface SCSNavigationTitleLabelContainerView: UIView @end
/*
 View containing the subtitleLabel.
 */
@interface SCSNavigationSubtitleLabelContainerView: UIView @end

@interface SCSNavigationTitleView : UIView

/*
 Label to specify the title for the view.
 */
@property (nonatomic, readonly) UILabel *titleLabel;

/*
 Label to specify the subtitle for the view.
 */
@property (nonatomic, readonly) UILabel *subtitleLabel;

/*
 Image view to indicate the presence status of the agent.
 */
@property (nonatomic, readonly) UIImageView *presenceIndicatorView;

/**
 Padding between the  presence image and the title label.
 */
@property (nonatomic, assign) IBInspectable CGFloat titleImagePadding UI_APPEARANCE_SELECTOR;

@end
