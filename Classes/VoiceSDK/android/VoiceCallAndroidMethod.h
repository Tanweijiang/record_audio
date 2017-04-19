#ifndef _VOICECALLANDROIDMETHOD_H_
#define _VOICECALLANDROIDMETHOD_H_

#include "cocos2d.h"
using namespace cocos2d;

class CallAndroidMethod{
public:
	/*
	* China good voice 
	* 开始录音 按钮按下
	* 录音结束 按钮弹起
	* 删除录音
	* 播放录音
	*/
	static CallAndroidMethod* getInstance();
	void prepare(std::string filename);
	void release();
	void cancel();
	void play(std::string filename);
	void stop();
	void getVoiceLevel();
	void setStorageDir(std::string dir);
	const char* getJniPath();
private:
	std::string _jniPath;
	CallAndroidMethod();
	static CallAndroidMethod* _instance;
};
#endif
