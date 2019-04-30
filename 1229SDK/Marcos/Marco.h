//
//  Marco.h
//  SDKLib
//
//  Created by MemoryFate on 2018/12/27.
//  Copyright © 2018 MemoryFate. All rights reserved.
//

#ifndef Marco_h
#define Marco_h

#define IMG_URL(url) [NSURL URLWithString:[NSString stringWithFormat:@"%@",url]]

// 获取屏幕尺寸
#define SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT  [UIScreen mainScreen].bounds.size.height
// 判断是否为NSNULL对象
#define isNSNULL(object) [object isKindOfClass:[NSNull class]]

// 弱引用
#define WEAK_SELF typeof(self) __weak weakSelf = self
/**************各设备屏幕宽度***************/
#define IPHONE4S_SCREEN_HEIGHT 480
#define IPHONE5S_SCREEN_HEIGHT 568
#define IPHONE6_SCREEN_HEIGHT  667
#define IPHONE6P_SCREEN_HEIGHT 736
#define IPHONE_X_AND_XS_SCREEN_HEIGHT 812
#define IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT 896
/**************各设备屏幕宽度***************/

//如果需要自定义 导航栏 和 工具栏（针对iPhone X 的适配）
#define navigation_H (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT)) ? 88:64)

#define tabbar_H (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT)) ? 83:49)

#define status_H (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT)) ? 44:20)

#define SafeAreaTopHeight    (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT))? 24 : 0)//相比64 增加了24
#define SafeAreaBottomHeight (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT))? 34 : 0)//相比49增加了34

#define BangScreen (((SCREEN_HEIGHT == IPHONE_X_AND_XS_SCREEN_HEIGHT)||(SCREEN_HEIGHT == IPHONE_XR_AND_XSMAX_SCREEN_HEIGHT))? 1 : 0)

/**************获取沙盒目录***************/
#define HOME_PATH           NSHomeDirectory()       // 程序根目录
#define DOCUMENT_PATH       NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).lastObject // DocumentPath
#define LIBRARY_PATH        NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).lastObject  // LibraryPath
#define LIBRARY_CACHE_PATH  NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject   // LibraryCachePath
#define TEMP_PATH           NSTemporaryDirectory()  // tempPath
// 客户端App版本号
#define kAppVersion                   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
// 操作系统版本号
#define kCurrentSystemVersion            [[UIDevice currentDevice] systemVersion]

// system size
#define kScreenBounds                    ([UIScreen mainScreen].bounds)
#define kScreenHeight                    ([UIScreen mainScreen].bounds.size.height)
#define kScreenWidth                     ([UIScreen mainScreen].bounds.size.width)
#define kStatusBarHeight                 [UIApplication sharedApplication].statusBarFrame.size.height
#define kTabBarHeight                    (kScreenIsIPhoneX ? 83.f : 49.f)
// frame按照比例布局
#define kAutoValue(value) (float)value / 375 * kScreenWidth

// iPhone X
#define kScreenIsIPhoneX                 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define kScreenSafeBottomHeight          (kScreenIsIPhoneX ? 34.f : 0.0)


// DEBUG日志
#ifdef DEBUG
#define Log(s,...) NSLog(@"<%@:(%d)>\n  %s\n  %@\n\n", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, __func__, [NSString stringWithFormat:(s), ##__VA_ARGS__])
#else
#define Log(s,...)
#endif

#endif /* Marco_h */
