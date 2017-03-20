//
//  ChatVoiceRecorderVC.m
//  Jeans
//
//  Created by Jeans on 3/23/13.
//  Copyright (c) 2013 Jeans. All rights reserved.
//

#import "ChatVoiceRecorderVC.h"
//#import "UIView+Animation.h"
#import "ChatRecorderView.h"

@interface ChatVoiceRecorderVC ()<AVAudioRecorderDelegate>{
    CGFloat                 curCount;           //当前计数,初始为0
    ChatRecorderView        *recorderView;      //录音界面
    CGPoint                 curTouchPoint;      //触摸点
    BOOL                    canNotSend;         //不能发送
    NSTimer                 *timer;
}

@property (retain, nonatomic)   AVAudioRecorder     *recorder;

@end

@implementation ChatVoiceRecorderVC
@synthesize recorder;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc{
    [recorder release];
    [recorderView release];
    [super dealloc];
}

#pragma mark - 开始录音
- (void)beginRecordByFileName:(NSString*)_fileName;{

    //设置文件名和录音路径
    self.recordFileName = _fileName;
    self.recordFilePath = [VoiceRecorderBaseVC getPathByFileName:recordFileName ofType:@"wav"];

    //初始化录音
    self.recorder = [[[AVAudioRecorder alloc]initWithURL:[NSURL URLWithString:recordFilePath]
                                                settings:[VoiceRecorderBaseVC getAudioRecorderSettingDict]
                                                   error:nil]autorelease];
    recorder.delegate = self;
    recorder.meteringEnabled = YES;
    
    if([recorder prepareToRecord]){
        NSLog(@"== preparetoRecord is ok ===");
    }
    
    //还原计数
    curCount = 0;
    //还原发送
    canNotSend = NO;
    
    //开始录音
    [[AVAudioSession sharedInstance] setCategory: AVAudioSessionCategoryPlayAndRecord error:nil];
    [[AVAudioSession sharedInstance] setActive:YES error:nil];
    [recorder record];
    
}
@end
