//
//  VoicePlaApi.cpp
//  Mahjong
//
//   Created by tanweijiang on 2017/03/01.
//

#include "VoicePlaApi.h"
#include "payment/CallAndroidMethod.h"

VoicePlaApi* VoicePlaApi::_instance = NULL;

VoicePlaApi* VoicePlaApi::getInstance(){
    
    if (_instance == NULL){
        _instance = new VoicePlaApi();
    }
    return _instance;
}

void VoicePlaApi::beginRecordAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC
	
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID 
	CallAndroidMethod::getInstance()->beginRecordAudio();
#endif
}

void VoicePlaApi::endRecordAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID 
	CallAndroidMethod::getInstance()->endRecordAudio();
#endif
}

void VoicePlaApi::deleteAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID  
	CallAndroidMethod::getInstance()->deleteAudio();
#endif
}

void VoicePlaApi::playAudio()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID  
	CallAndroidMethod::getInstance()->playAudio();
#endif
}

VoicePlaApi::VoicePlaApi() {  
}
