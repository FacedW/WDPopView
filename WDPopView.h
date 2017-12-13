//
//  WDPopView.h
//  TNDataDisplay
//
//  Created by 吴鼎 on 2017/12/11.
//  Copyright © 2017年 TN. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger,WDPopStyle) {
    WDPopStyleFromBottom = 0,
    WDPopStyleFromTop,
};

@protocol WDPopViewDelegate;
@interface WDPopView : NSObject
/**
 弹出方式，默认WDPopStyleFromBottom
 */
@property (nonatomic,assign) WDPopStyle popStyle;
/**
 弹窗背景色,默认0.6灰度
 */
@property (nonatomic,strong) UIColor *popViewBackgroundColor;
/**
 是否需要遮罩，默认YES
 */
@property (nonatomic,assign) BOOL isMasked;
/**
 代理
 */
@property (nonatomic,assign) id <WDPopViewDelegate>delegate;



/**
 初始化

 @param contentView 自定义的view
 @return popview
 */
- (instancetype)initWithContentView:(UIView *)contentView;
/**
 弹窗弹出

 @param animated 是否需要动画
 */
- (void)presentPopupControllerAnimate:(BOOL)animated;
/**
 弹窗收回
 
 @param animated 是否需要动画
 */
- (void)dismissPopupControllerAnimated:(BOOL)animated;
@end




@protocol WDPopViewDelegate <NSObject>
@optional
/**
 已经弹出
 
 @param contentView contentView
 */
- (void)WDPopContentViewDidPresent:(UIView*)contentView;
/**
 已经退出
 
 @param contentView contentView
 */
- (void)WDPopContentViewDidDismiss:(UIView*)contentView;
@end
