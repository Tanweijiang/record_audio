#ifndef _VOICECALLANDROIDMETHOD_H_
#define _VOICECALLANDROIDMETHOD_H_

#include "cocos2d.h"
using namespace cocos2d;

class VoiceCallAndroidMethod{
public:
	/*
	* China good voice 
	*/
	static VoiceCallAndroidMethod* getInstance();
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
	VoiceCallAndroidMethod();
	static VoiceCallAndroidMethod* _instance;
};
#endif
