//
//  LVRecordTool.m
//  RecordAndPlayVoice
//
//  Created by PBOC CS on 15/3/14.
//  Copyright (c) 2015年 liuchunlao. All rights reserved.
//

//#define LVRecordFielName @"lvRecord.caf"


#import "AudioRecordManager.h"
#import "LVRecordTool.h"

@interface AudioRecordManager () <LVRecordToolDelegate>

@property (nonatomic, strong) LVRecordTool *recordTool;

@end

@implementation AudioRecordManager

#pragma mark - 单例
+ (instancetype)recordManager {
    
//    AudioRecordManager* recordManager = [[AudioRecordManager alloc] init];
//    recordManager.recordTool = [LVRecordTool sharedRecordTool];
//    [recordManager setup];
//    return recordManager;
    
    static dispatch_once_t onceToken;
    static AudioRecordManager *instance;
    dispatch_once(&onceToken, ^{
        if (instance == nil) {
            instance = [[self alloc] init];
            instance.recordTool = [LVRecordTool sharedRecordTool];
            [instance setup];
        }
    });
    return instance;
}


- (void)setup {
    
    self.recordTool.delegate = self;
}

/** 开始录音 */
-(void)beginRecordAudio
{
     NSLog(@"== beginRecordAudio == ");
     [self.recordTool startRecording];
}

/** 录音结束 */
-(void)endRecordAudio{
     NSLog(@"== endRecordAudio == ");
    [self.recordTool stopRecording];
     NSLog(@"已成功录音");
}

/** 取消录音 */
- (void)cancelRecordAudio{
     NSLog(@"== cancelRecordAudio == ");
    [self.recordTool stopRecording];
    [self.recordTool destructionRecordingFile];
    NSLog(@"已取消录音");
}

/** 播放录音*/
- (void)playAudio{
     NSLog(@"== playAudio == ");
    [self.recordTool playRecordingFile];
}

/** 删除录音*/
- (void)deleltefile{
    [self.recordTool stopRecording];
    [self.recordTool destructionRecordingFile];
}

/** 获取录音文件路径*/
- (NSString*)getRecordFilepath{
    NSURL* filePath = [self.recordTool getFilePath];
    NSString * urlStr = [filePath absoluteString];
    return urlStr;
}


- (void)setCanPlayFilepath:(NSString*)path{
     NSLog(@"AudioRecordManager :: setPlayRecordFilepath  === path = %@",path);
    [self.recordTool setCanPlayFilepath:path];
}

//- (void)getRecordFilepath:(NSString*) audioPath{
//
//   // NSURL * url = [NSURL URLWithString:audioPath];
//    NSURL * url = [[NSURL alloc] initWithString:audioPath];
//    self.recordTool.recordFileUrl =()url;
//}

- (void)dealloc {
    
    if ([self.recordTool.recorder isRecording]) [self.recordTool stopPlaying];
    
    if ([self.recordTool.player isPlaying]) [self.recordTool stopRecording];
    
}

#pragma mark - LVRecordToolDelegate
- (void)recordTool:(LVRecordTool *)recordTool didstartRecoring:(int)no {
    
//    NSString *imageName = [NSString stringWithFormat:@"mic_%d", no];
//    self.imageView.image = [UIImage imageNamed:imageName];
}

@end
