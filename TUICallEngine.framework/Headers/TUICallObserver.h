//
//  TUICallObserver.h
//  TUICalling
//
//  Created by noah on 2022/7/8.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUICallDefine.h"

@class TUIRoomId, TUINetworkQualityInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol TUICallObserver <NSObject>

@optional

/// An error occurred inside the SDK.
/// @param code Error code
/// @param message Error message
- (void)onError:(int)code message:(NSString * _Nullable)message
NS_SWIFT_NAME(onError(code:message:));

- (void)onCallReceived:(NSString *)callerId calleeIdList:(NSArray<NSString *> *)calleeIdList isGroupCall:(BOOL)isGroupCall callMediaType:(TUICallMediaType)callMediaType
NS_SWIFT_NAME(onCallReceived(callerId:calleeIdList:isGroupCall:callMediaType:));

- (void)onCallCancelled:(NSString *)callerId
NS_SWIFT_NAME(onCallCancelled(callerId:));

- (void)onCallBegin:(TUIRoomId *)roomId callMediaType:(TUICallMediaType)callMediaType callRole:(TUICallRole)callRole
NS_SWIFT_NAME(onCallBegin(roomId:callMediaType:callRole:));

- (void)onCallEnd:(TUIRoomId *)roomId callMediaType:(TUICallMediaType)callMediaType callRole:(TUICallRole)callRole totalTime:(float)totalTime
NS_SWIFT_NAME(onCallEnd(roomId:callMediaType:callRole:totalTime:));

- (void)onCallMediaTypeChanged:(TUICallMediaType)oldCallMediaType newCallMediaType:(TUICallMediaType)newCallMediaType
NS_SWIFT_NAME(onCallMediaTypeChanged(oldCallMediaType:newCallMediaType:));

/// 1. In a C2C call, only the caller will receive the rejection callback.
/// For example, if A calls B and C, and B rejects the call, A receives the callback but C does not.
/// 2. In an IM group call, all invitees can receive this callback.
/// For example, if A calls B and C, and B rejects the call, both A and C can receive the callback.
/// @param userId User rejecting the call
- (void)onUserReject:(NSString *)userId
NS_SWIFT_NAME(onUserReject(userId:));

/// 1. In a C2C call, only the caller will receive the callback for no users answering the call.
/// For example, if A calls B and C, but B doesn't answer the call, A receives the callback but C does not.
/// 2. In an IM group call, all invitees can receive this callback.
/// For example, if A calls B and C, but B doesn't answer the call, both A and C can receive the callback.
/// @param userId  No responding user
- (void)onUserNoResponse:(NSString *)userId
NS_SWIFT_NAME(onUserNoResponse(userId:));

/// The invitee is busy
/// @param userId  Busy user
- (void)onUserLineBusy:(NSString *)userId
NS_SWIFT_NAME(onUserLineBusy(userId:));

/// A user agreed to enter the call.
/// @param userId  User entering the call
- (void)onUserJoin:(NSString *)userId
NS_SWIFT_NAME(onUserJoin(userId:));

/// A user agreed to exit the call.
/// @param userId  User exiting the call
- (void)onUserLeave:(NSString *)userId
NS_SWIFT_NAME(onUserLeave(userId:));

/// A remote user turned the camera on/off.
/// @param userId Remote user ID
/// @param isVideoAvailable The remote user turned the camera on; false: The remote user turned the camera off
- (void)onUserVideoAvailable:(NSString *)userId isVideoAvailable:(BOOL)isVideoAvailable
NS_SWIFT_NAME(onUserVideoAvailable(userId:isVideoAvailable:));

/// A remote user turned the mic on/off.
/// @param userId Remote user ID
/// @param isAudioAvailable The remote user turned the mic on; false: The remote user turned the mic off
- (void)onUserAudioAvailable:(NSString *)userId isAudioAvailable:(BOOL)isAudioAvailable
NS_SWIFT_NAME(onUserAudioAvailable(userId:isAudioAvailable:));

/// Callback for user volumes
/// @param volumeMap userId : volume,  volume level table, the volume of each `userId`. Value range: 0-100.
- (void)onUserVoiceVolumeChanged:(NSDictionary <NSString *, NSNumber *> *)volumeMap
NS_SWIFT_NAME(onUserVoiceVolumeChanged(volumeMap:));

- (void)onUserNetworkQualityChanged:(NSArray<TUINetworkQualityInfo *> *)networkQualityList
NS_SWIFT_NAME(onUserNetworkQualityChanged(networkQualityList:));

- (void)onKickedOffline;

- (void)onUserSigExpired;

@end

NS_ASSUME_NONNULL_END

