
#include "CallRcordMecordios.h"
#include "AudioRecordManager.h"

CallRcordMecordios* CallRcordMecordios::_instance = NULL;

CallRcordMecordios* CallRcordMecordios::getInstance(){
    if (_instance == NULL){
        _instance = new CallRcordMecordios();
    }
    return _instance;
}

CallRcordMecordios::CallRcordMecordios(){}

/** 开始录音 */
void CallRcordMecordios::beginRecordAudio(){
  [[AudioRecordManager recordManager] beginRecordAudio];
}

/** 录音结束 */
void CallRcordMecordios::endRecordAudio(){
 [[AudioRecordManager recordManager]  endRecordAudio];
}

/** 取消录音 */
void CallRcordMecordios::cancelRecordAudio(){
    [[AudioRecordManager recordManager]  cancelRecordAudio];

}

/** 播放录音*/
void CallRcordMecordios::playAudio(){
   [[AudioRecordManager recordManager]  playAudio];
}

/** 删除录音*/
void CallRcordMecordios::deleltefile(){
[[AudioRecordManager recordManager]  deleltefile];
}

/** 获取录音文件路径*/
void CallRcordMecordios::getRecordFilepath(){
   //todo
}

