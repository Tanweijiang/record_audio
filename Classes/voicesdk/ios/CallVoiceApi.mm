
#include "voicesdk/ios/CallVoiceApi.h"
#include "VoiceSDK.h"

CallVoiceApi* CallVoiceApi::_instance = NULL;

CallVoiceApi* CallVoiceApi::getInstance(){
    if (_instance == NULL){
        _instance = new CallVoiceApi();
    }
    return _instance;
}

CallVoiceApi::CallVoiceApi(){}


void CallVoiceApi::prepareRecord(std::string filename){
     NSString *str= [NSString stringWithCString:filename.c_str() encoding:[NSString defaultCStringEncoding]];
     NSLog(@"==  CallVoiceApi:: prepareRecord ==str== %@",str);
    
    [VoiceSDK prepareRecord:str];
}

void CallVoiceApi::finishRecord(){
    NSLog(@"==  CallVoiceApi:: finishRecord ====");
    [VoiceSDK finishRecord];
}

void CallVoiceApi::cancelRecord(){
    [VoiceSDK cancelRecord];
}

void CallVoiceApi::play(std::string filename){
    
    NSString *str= [NSString stringWithCString:filename.c_str() encoding:[NSString defaultCStringEncoding]];
    
    [VoiceSDK play:str];
}

void CallVoiceApi::stopPlay(){
    [VoiceSDK stopPlay];
}


void CallVoiceApi::setStorageDir(std::string dir){
    
    NSString *str= [NSString stringWithCString:dir.c_str() encoding:[NSString defaultCStringEncoding]];

     [VoiceSDK setStorageDir:str];
}

