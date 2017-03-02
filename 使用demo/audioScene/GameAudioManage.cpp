//
//  GameAudioManage.cpp
//  Mahjong
//
//   Created by tanweijiang on 2017/03/01.
//

#include "GameAudioManage.h"
#include "payment/CallAndroidMethod.h"
#include "recordIosAudioutils/CallRcordMecordios.h"

GameAudioManage* GameAudioManage::_instance = NULL;

GameAudioManage* GameAudioManage::getInstance(){
    
    if (_instance == NULL){
        _instance = new GameAudioManage();
    }
    return _instance;
}

void GameAudioManage::beginRecordAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    CallRcordMecordios::getInstance()->beginRecordAudio();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID 
	CallAndroidMethod::getInstance()->beginRecordAudio();
#endif
}

void GameAudioManage::endRecordAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
 CallRcordMecordios::getInstance()->endRecordAudio();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID 
	CallAndroidMethod::getInstance()->endRecordAudio();
#endif
}

void GameAudioManage::deleteAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    CallRcordMecordios::getInstance()->deleltefile();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID  
	CallAndroidMethod::getInstance()->deleteAudio();
#endif
}

void GameAudioManage::playAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    CallRcordMecordios::getInstance()->playAudio();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID  
	CallAndroidMethod::getInstance()->playAudio();
#endif
}

GameAudioManage::GameAudioManage() {  
}
