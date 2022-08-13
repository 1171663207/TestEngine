//
//  TUICallDefine.h
//  TUICalling
//
//  Created by noah on 2022/7/18.
//  Copyright © 2022 Tencent. All rights reserved.
//

#ifndef TUICallDefine_h
#define TUICallDefine_h

#import "TUICommonDefine.h"

typedef void (^TUICallSucc)(void);
typedef void (^TUICallFail)(int code, NSString *errMsg);

static const int TUICALL_RETURN_DEFAULT_VALUE = 0;
static const int TUICALL_RETURN_ERROR = -1;

/// Calling version
static const NSString * TUICALL_VERSION = @"1.0.0.51";

typedef NS_ENUM(NSInteger, TUICallMediaType) {
    TUICallMediaTypeUnknown,
    TUICallMediaTypeAudio,
    TUICallMediaTypeVideo,
};

typedef NS_ENUM(NSUInteger, TUICallRole) {
    TUICallRoleNone,
    TUICallRoleCall,
    TUICallRoleCalled,
};

typedef NS_ENUM(NSUInteger, TUICallStatus) {
    TUICallStatusNone,
    TUICallStatusWaiting,
    TUICallStatusAccept,
};

typedef NS_ENUM(NSUInteger, TUICallScene) {
    TUICallSceneGroup,
    TUICallSceneMulti,
    TUICallSceneSingle,
};

#ifndef dispatch_call_main_async_safe
#define dispatch_call_main_async_safe(block)\
    if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue())) {\
        block();\
    } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
    }
#endif

#endif /* TUICallDefine_h */
