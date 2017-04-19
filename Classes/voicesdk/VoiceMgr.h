#pragma once

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

#define RECORD_AUDIO_PATH "record_audio.amr"
#define DOWNLOAD_AUDIO_PATH  "download_audio.amr"

class VoiceMgr : public Layer
{
public:
	static VoiceMgr* getInstance();
    // 编码
    Data encode(Data data);
    // 解码
    Data decode(string data);
    
    // _
    // onPlayCallback:null,
    string _voiceMediaPath;   // 声音存放路径
    
    // funciton
    
    void prepare();
    // 准备
    void prepare(string filename);
    
    // 释放
    void release();
    
    // 取消
    void cancel();
    
    // 清楚缓存
    void clearCache(string filename);
    
    // 播放
    void play(string filename);
    
    // 暂停
    void stop();
    
    // 获得音量
    int getVoiceLevel(int maxLevel);
    
    void writeVoice(string voiceData);
    // 写入声音数据  当从服务器收到声音通知的时候   when get data from service then  call this function
    void writeVoice(string filename, string voiceData);
    
    // 获得声音数据  // 然后可以发送到服务器         when need send data to service
    string getVoiceData(string filename);
    
    string getVoiceData();
    
    // 设置本地存储路劲
    void setStorageDir(string dir);
    
    void download();

private:
    
	VoiceMgr();
	static VoiceMgr* _instance;
};
