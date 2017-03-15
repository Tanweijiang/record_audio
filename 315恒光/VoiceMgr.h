#pragma once
#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//USING_NS_CC_EXT;
//USING_NS_CC;
//using namespace ui;
//using namespace std;

USING_NS_CC;
using namespace experimental;
using namespace std;

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
	// 准备
	void prepare(string filename);

	// 释放
	void release();

	// 取消
	void cancel();

	// 写入声音数据
	void writeVoice(string filename,string voiceData);

	// 清楚缓存
	void clearCache(string filename);

	// 播放
	void play(string filename);

	// 暂停
	void stop();

	// 获得音量
	int getVoiceLevel(int maxLevel);

	// 获得声音数据
	string getVoiceData(string filename);

	// 设置本地存储路劲
	void setStorageDir(string dir);

	void download();

private:
	VoiceMgr();
	static VoiceMgr* _instance;

};
