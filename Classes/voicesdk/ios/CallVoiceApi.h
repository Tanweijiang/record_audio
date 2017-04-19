
#pragma once
//#include <string.h>

class CallVoiceApi{
public:
    static CallVoiceApi* getInstance();

    void prepareRecord(std::string filename);
    
    void finishRecord();
    
    void cancelRecord();
    
    void play(std::string filename);
    
    void stopPlay();
    
    void setStorageDir(std::string dir);
private:
    CallVoiceApi();
    static CallVoiceApi* _instance;
};
