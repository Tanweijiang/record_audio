//
//  LVRecordTool.h
//  RecordAndPlayVoice
//
//  Created by PBOC CS on 15/3/14.
//  Copyright (c) 2015年 liuchunlao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>


@class AudioRecordManager;
@protocol AudioRecordManagerDelegate <NSObject>

@optional
- (void)recordManager:(AudioRecordManager *)recordManager didstartRecoring:(int)no;

@end



@interface AudioRecordManager : NSObject


+ (instancetype)recordManager;

/** 开始录音 */
- (void)beginRecordAudio;

/** 录音结束 */
- (void)endRecordAudio;

/** 取消录音 */
- (void)cancelRecordAudio;

/** 播放录音*/
- (void)playAudio;

/** 删除录音*/
- (void)deleltefile;

/** 获取录音文件路径*/
- (void)getRecordFilepath;


@end
