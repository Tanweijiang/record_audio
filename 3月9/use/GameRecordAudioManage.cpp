//
//  GameAudioManage.cpp
//  Mahjong
//
//   Created by tanweijiang on 2017/03/01.
//

#include "GameRecordAudioManage.h"
#include "payment/android/CallAndroidMethod.h"
#include "payment/ios/recordAudio/CallRcordMecordios.h"
#include "payment/ThirdSDKMannger.h"
#include "game/utils/Audio.h"
#include "Base64.h"
GameAudioManage* GameAudioManage::_instance = NULL;

GameAudioManage* GameAudioManage::getInstance(){
    
    if (_instance == NULL){
        _instance = new GameAudioManage();
    }
    return _instance;
}

void GameAudioManage::beginRecordAudio()
{
	ThirdSDKMannger::beginRecordAudio();
}

void GameAudioManage::endRecordAudio()
{
	ThirdSDKMannger::endRecordAudio();
}

void GameAudioManage::deleteAudio()
{
	ThirdSDKMannger::deleteAudio();
}

std::string GameAudioManage::getRecordFilePath()
{
	return ThirdSDKMannger::getRecordFilePath();
}
void GameAudioManage::playRecord(std::string enbytes)
{
    auto newpath = FileUtils::getInstance()->getWritablePath()+"xxx.aac";
    auto file = FileUtils::getInstance();
    auto path = newpath;
    file->removeFile(path);
    
    auto debytes = base64_decode(enbytes);
    file->writeStringToFile(debytes, path);
    log("[DQMJ]GameAudioManage::playRecord %s",newpath.c_str());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
  
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
   CallRcordMecordios::getInstance()->setCallCanPlayFilepath(newpath);
    CallRcordMecordios::getInstance()->playAudio();
   // Audio::getInstance()->playEffect(path);
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
  
    Audio::getInstance()->playEffect(path);
#endif
    
    
}

GameAudioManage::GameAudioManage() {

}


