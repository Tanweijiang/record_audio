//
//  GameAudioManage.hpp
//  Mahjong
//
//  Created by tanweijiang on 2017/03/01.
//
//

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class GameAudioManage{
public:
    static GameAudioManage* getInstance();

	// ��ʼ¼�� ��ť����
	void beginRecordAudio();

	// ¼������ ��ť����
	void endRecordAudio();

	// ɾ��¼��
	void deleteAudio();

	//�������� ���� base64���ܹ���string
	void playRecord(std::string enbytes);

	std::string getRecordFilePath();
	


private:
    GameAudioManage();
    static GameAudioManage* _instance;
};

