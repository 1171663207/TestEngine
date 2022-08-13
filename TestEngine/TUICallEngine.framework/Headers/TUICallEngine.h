//
//  TUICallEngine.h
//  TUICalling
//
//  Created by noah on 2022/4/26.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUICallObserver.h"
#import "TUICallDefine.h"
#import "TUICommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUICallEngine : NSObject

+ (TUICallEngine *)createInstance;

+ (void)destroyInstance;

- (void)init:(int)sdkAppID userId:(NSString *)userId userSig:(NSString *)userSig succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(init(sdkAppID:userId:userSig:succ:fail:));

- (void)addObserver:(id<TUICallObserver>)observer;

- (void)removeObserver:(id<TUICallObserver>)observer;

- (void)call:(TUIRoomId *)roomId userId:(NSString *)userId callMediaType:(TUICallMediaType)callMediaType succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(call(roomId:userId:callMediaType:succ:fail:));

- (void)groupCall:(TUIRoomId *)roomId groupId:(NSString *)groupId userIdList:(NSArray *)userIdList callMediaType:(TUICallMediaType)callMediaType succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(groupCall(roomId:groupId:userIdList:callMediaType:succ:fail:));

- (void)accept:(TUICallSucc)succ fail:(TUICallFail)fail;

- (void)reject:(TUICallSucc)succ fail:(TUICallFail)fail;

- (void)hangup:(TUICallSucc)succ fail:(TUICallFail)fail;

- (void)ignore:(TUICallSucc)succ fail:(TUICallFail)fail;

- (void)inviteUser:(NSArray<NSString *> *)userIdList succ:(void(^)(NSArray *userIdList))succ fail:(TUICallFail)fail
NS_SWIFT_NAME(inviteUser(userIdList:succ:fail:));

- (void)joinInGroupCall:(TUIRoomId *)roomId groupId:(NSString *)groupId callMediaType:(TUICallMediaType)callMediaType succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(joinInGroupCall(roomId:groupId:callMediaType:succ:fail:));

- (void)switchCallMediaType:(TUICallMediaType)newType;

- (void)startRemoteView:(NSString *)userId videoView:(TUIVideoView *)videoView onPlaying:(void(^)(NSString *userId))onPlaying onLoading:(void(^)(NSString *userId))onLoading onError:(void(^)(NSString *userId, int code, NSString *errMsg))onError
NS_SWIFT_NAME(startRemoteView(userId:videoView:onPlaying:onLoading:onError:));

- (void)stopRemoteView:(NSString *)userId
NS_SWIFT_NAME(stopRemoteView(userId:));

- (void)openCamera:(TUICamera)camera videoView:(TUIVideoView *)videoView succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(openCamera(camera:videoView:succ:fail:));

- (void)closeCamera;

- (void)switchCamera:(TUICamera)camera;

- (void)openMicrophone:(TUICallSucc)succ fail:(TUICallFail)fail;

- (void)closeMicrophone;

- (void)selectAudioPlaybackDevice:(TUIAudioPlaybackDevice)device;

- (void)setSelfInfo:(NSString * _Nullable)nickname avatar:(NSString * _Nullable)avatar succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(setSelfInfo(nickname:avatar:succ:fail:));

- (void)enableMultiDeviceAbility:(BOOL)enable succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(enableMultiDeviceAbility(enable:succ:fail:));

@end

NS_ASSUME_NONNULL_END
