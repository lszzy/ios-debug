//
//  FWDebugManager.h
//  FWDebug
//
//  Created by 吴勇 on 17/2/26.
//  Copyright © 2017年 wuyong.site. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 调试管理器
 */
@interface FWDebugManager : NSObject

/// 是否启用5秒内摇一摇两次切换调试器，默认YES
@property (nonatomic, assign) BOOL shakeEnabled;

/// 是否启用5秒内5指点击两次切换调试器，默认YES
@property (nonatomic, assign) BOOL touchEnabled;

/// 调试器是否隐藏
@property (nonatomic, readonly) BOOL isHidden;

/// 打开URL调试钩子方法，长按帧率按钮触发
@property (nonatomic, copy, nullable) BOOL (^openUrl)(NSString *url);

/// 单例模式
+ (instancetype)sharedInstance;

/// 注册自定义入口，点击时打开objectBlock返回值，支持控制器和任意对象
- (void)registerEntry:(NSString *)entryName objectBlock:(id (^)(void))objectBlock;

/// 注册自定义入口，点击时触发actionBlock，参数为调试控制器
- (void)registerEntry:(NSString *)entryName actionBlock:(void (^)(__kindof UITableViewController *))actionBlock;

/// 记录自定义事件，object为事件对象，userInfo为weak引用附加信息
- (void)recordEvent:(NSString *)event object:(id)object userInfo:(nullable id)userInfo;

/// 切换调试器
- (void)toggle;

/// 显示调试器
- (void)show;

/// 隐藏调试器
- (void)hide;

@end

NS_ASSUME_NONNULL_END
