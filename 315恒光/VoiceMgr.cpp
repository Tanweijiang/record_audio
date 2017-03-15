/*
  祭奠我逝去的  恒光 
  tanwejiang 
*/
#include "VoiceMgr.h"
#include "audio/include/AudioEngine.h"
#include "payment/CallAndroidMethod.h"
#include "Base64.h"
//#include "base/base64.h"
//#include "game/utils/Audio.h"

VoiceMgr* VoiceMgr::_instance = NULL;
VoiceMgr* VoiceMgr::getInstance() {

	if (_instance == NULL) {
		_instance = new VoiceMgr();
	}
	return _instance;
}

VoiceMgr::VoiceMgr() {
	//std::string  url =  coco2d   //cc.url.raw("resources/test2.amr");
	//fileUtils.writeDataToFile(decode(content), url);
	//FileUtils::getInstance()->writeDataToFile();

	_voiceMediaPath = FileUtils::getInstance()->getWritablePath() + "/voicemsgs/";      // 每次初始化路劲
	setStorageDir(_voiceMediaPath);
}

Data VoiceMgr::encode(Data data)
{
	auto t = Data();
	return t;
}

Data VoiceMgr::decode(string data)
{
	auto t = Data();
	return t;
}

void VoiceMgr::prepare(string filename)
{
	AudioEngine::pauseAll();
	clearCache(filename);  // todov
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->prepare(filename);
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	// prepareRecord filename
	//jsb.reflection.callStaticMethod("VoiceSDK", "prepareRecord:", filename);
#endif
}

void VoiceMgr::release()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->release();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	//jsb.reflection.callStaticMethod("VoiceSDK", "finishRecord");
#endif
}

void VoiceMgr::cancel()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->cancel();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	//jsb.reflection.callStaticMethod("VoiceSDK", "cancelRecord");
#endif
}

void VoiceMgr::writeVoice(string filename, string voiceData)
{
	//if (voiceData && voiceData.length > 0) {
	//	auto fileData = decode(voiceData);
	//	auto url = _voiceMediaPath + filename;
	//	clearCache(filename);
	//	FileUtils::getInstance()->writeDataToFile(fileData, url);
	//}
}

void VoiceMgr::clearCache(string filename)
{
	string url = _voiceMediaPath + filename;
	log("check file:==%s", url.c_str());
	
	if (FileUtils::getInstance()->isFileExist(url)) {
		log("remove:==%s" , url.c_str());
		FileUtils::getInstance()->removeFile(url);
	}
	if (FileUtils::getInstance()->isFileExist(url + ".wav")) {
		string tempUrl = url + ".wav";
	    log("remove:==%s" ,tempUrl.c_str());
		FileUtils::getInstance()->removeFile(url + ".wav");
	}
}

void VoiceMgr::play(string filename)
{
	AudioEngine::pauseAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->play(filename);
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	//jsb.reflection.callStaticMethod("VoiceSDK", "play:", filename);
#endif
}

void VoiceMgr::stop()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->stop();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	//jsb.reflection.callStaticMethod("VoiceSDK", "stopPlay");
#endif
}

int VoiceMgr::getVoiceLevel(int maxLevel)
{
	// return Math.floor(Math.random() * maxLevel + 1);
	return 1;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
#endif
}

string VoiceMgr::getVoiceData(string filename)
{
	//string urla = "tt";
	string url = _voiceMediaPath + filename;
	log("VoiceMgr::getVoiceData ==url ======%s",url.c_str());
	//log("getVoiceData:%s" + url.c_str());
	//Data fileData = FileUtils::getInstance()->getDataFromFile(url);
	string voiceData = "";
	voiceData = FileUtils::getInstance()->getStringFromFile(url);
	string msg = "";
	if (voiceData!=""){
		msg = base64_encode((unsigned char*)voiceData.c_str(), (unsigned int)voiceData.length());
	}	
	return msg;
}

// 设置本地存储路劲
void VoiceMgr::setStorageDir(string dir)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	// jni 调用 setStorageDir 方法
	CallAndroidMethod::getInstance()->setStorageDir(dir);
#endif
}

void VoiceMgr::download()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	// todo
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	// todo
#endif
}