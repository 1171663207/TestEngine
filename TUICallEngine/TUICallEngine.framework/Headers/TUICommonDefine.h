//
//  TUICommonDefine.h
//  TUICallEngine
//
//  Created by noah on 2022/8/4.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TUILog.h"

typedef NS_ENUM(NSUInteger, TUIAudioPlaybackDevice) {
    TUIAudioPlaybackDeviceSpeakerphone,
    TUIAudioPlaybackDeviceEarpiece,
};

typedef NS_ENUM(NSUInteger, TUICamera) {
    TUICameraFront,
    TUICameraBack,
};

typedef NS_ENUM(NSInteger, TUINetworkQuality) {
    TUINetworkQualityUnknown,
    TUINetworkQualityExcellent,
    TUINetworkQualityGood,
    TUINetworkQualityPoor,
    TUINetworkQualityBad,
    TUINetworkQualityVbad,
    TUINetworkQualityDown,
};

#define TRTCLog(fmt, ...) TRTCCloudCallingAPILog(fmt, ##__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN

@interface TUIRoomId : NSObject

/// int类型房间号
@property (nonatomic, assign) UInt32 intRoomId;

@end

@interface TUIVideoView : UIView

@end

@interface TUINetworkQualityInfo : NSObject

/// 用户ID
@property (nonatomic, copy, nullable) NSString *userId;
/// 网络原因
@property (nonatomic, assign) TUINetworkQuality quality;

@end

NS_ASSUME_NONNULL_END
