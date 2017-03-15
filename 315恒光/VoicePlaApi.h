//
//  VoicePlaApi.hpp
//  Mahjong
//
//  Created by tanweijiang on 2017/03/01.
//
//

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class VoicePlaApi{
public:
    static VoicePlaApi* getInstance();

	// 开始录音 按钮按下
	void beginRecordAudio();

	// 录音结束 按钮弹起
	void endRecordAudio();

	// 删除录音
	void deleteAudio();

	// 播放录音
	void playAudio();

private:
    VoicePlaApi();
    static VoicePlaApi* _instance;
};

