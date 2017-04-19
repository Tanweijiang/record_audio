/*
  tanwejiang 
*/

#include "voicesdk/VoiceMgr.h"
#include "audio/include/AudioEngine.h"
#include "voicesdk/Base64.h"
using namespace experimental;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "voicesdk/android/CallAndroidMethod.h"
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
#include "voicesdk/ios/CallVoiceApi.h"
#endif

VoiceMgr* VoiceMgr::_instance = NULL;
VoiceMgr* VoiceMgr::getInstance() {

	if (_instance == NULL) {
		_instance = new VoiceMgr();
	}
	return _instance;
}

VoiceMgr::VoiceMgr() {
    _voiceMediaPath = FileUtils::getInstance()->getWritablePath(); 
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

void VoiceMgr::prepare()
{
	prepare(RECORD_AUDIO_PATH);
}

void VoiceMgr::prepare(string filename)
{
	AudioEngine::pauseAll();
	clearCache(filename);  // todov
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->prepare(filename);
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
   CallVoiceApi::getInstance()->prepareRecord(filename);
#endif
}

void VoiceMgr::release()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->release();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
    CallVoiceApi::getInstance()->finishRecord();
#endif
}

void VoiceMgr::cancel()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->cancel();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
     CallVoiceApi::getInstance()->cancelRecord();
#endif
}

void VoiceMgr::writeVoice(string voiceData){
	writeVoice(DOWNLOAD_AUDIO_PATH,voiceData);
}

void VoiceMgr::writeVoice(string filename, string voiceData)
{
	log("testmsg === %s", voiceData.c_str());
	string recodByte = base64_decode(voiceData.c_str());
	log("recodByte === %s", recodByte.c_str());
	string path = VoiceMgr::getInstance()->_voiceMediaPath + filename;
	FileUtils::getInstance()->writeStringToFile(recodByte, path);
	VoiceMgr::getInstance()->play(filename);
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
     CallVoiceApi::getInstance()->play(filename);
#endif
}

void VoiceMgr::stop()
{
	AudioEngine::resumeAll();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	CallAndroidMethod::getInstance()->stop();
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
     CallVoiceApi::getInstance()->stopPlay();
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

string VoiceMgr::getVoiceData(){
	getVoiceData(RECORD_AUDIO_PATH);
}

string VoiceMgr::getVoiceData(string filename)
{
	string url = _voiceMediaPath + filename;
	log("VoiceMgr::getVoiceData ==url ======%s",url.c_str());
    
    bool testisExit = FileUtils::getInstance()->isFileExist(url);
    if (testisExit) {
        log("VoiceMgr::getVoiceData  arm is exit");

    }
    else{
          log("VoiceMgr::getVoiceData  arm is  not exit");
    }
      
    bool testisExit2 = FileUtils::getInstance()->isFileExist(_voiceMediaPath+"record.amr.wav");
    if (testisExit2) {
        log("VoiceMgr::getVoiceData  wav is exit");
        
    }
    else{
        log("VoiceMgr::getVoiceData  wav is  not exit");
    }
    
	ssize_t*size = new ssize_t();
	auto voiceData = FileUtils::getInstance()->getFileData(url, "r", size);
	log("VoiceMgr::getVoiceData == ======end ==");
	string msg = "";
	msg = base64_encode(voiceData, *size);

	log("VoiceMgr::getVoiceData  ==base64_encode ========%s",msg.c_str());
	return msg;
}



void VoiceMgr::setStorageDir(string dir)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	CallAndroidMethod::getInstance()->setStorageDir(dir);
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
    CallVoiceApi::getInstance()->setStorageDir(dir);
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
