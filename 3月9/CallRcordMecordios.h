
#pragma once
using namespace std;

class CallRcordMecordios{
public:
    static CallRcordMecordios* getInstance();

    /** 开始录音 */
    void beginRecordAudio();
    
    /** 录音结束 */
    void endRecordAudio();
    
    /** 取消录音 */
    void cancelRecordAudio();
    
    /** 播放录音*/
    void playAudio();
    
    /** 删除录音*/
    void deleltefile();
    
    /** 设置可以播放的路径*/
   void setCallCanPlayFilepath(std::string path);
    
    void test1();
    
    /** 获取录音文件路径*/
    std::string getRecordFilepath();
private:
    CallRcordMecordios();
    static CallRcordMecordios* _instance;
};





