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

	// ��ʼ¼�� ��ť����
	void beginRecordAudio();

	// ¼������ ��ť����
	void endRecordAudio();

	// ɾ��¼��
	void deleteAudio();

	// ����¼��
	void playAudio();

private:
    VoicePlaApi();
    static VoicePlaApi* _instance;
};

