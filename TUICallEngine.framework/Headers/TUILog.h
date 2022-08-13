//
//  TUILog.h
//  TUICallEngine
//
//  Created by noah on 2022/8/3.//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Log  Parameters
static const int TC_TUICALLING_COMPONENT = 3;
static const int TC_TIMCALLING_COMPONENT = 10;

FOUNDATION_EXPORT void TRTCCloudCallingAPILog(NSString *format, ...);

NS_ASSUME_NONNULL_BEGIN

@interface TUILog : NSObject

@property (class, nonatomic, assign) int component;

@end

NS_ASSUME_NONNULL_END
