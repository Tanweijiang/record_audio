#pragma once
#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//USING_NS_CC_EXT;
//USING_NS_CC;
//using namespace ui;
//using namespace std;

USING_NS_CC;
using namespace experimental;
using namespace std;

class VoiceMgr : public Layer
{
public:
	static VoiceMgr* getInstance();

	// ����
	Data encode(Data data);
	// ����
	Data decode(string data);

	// _
     // onPlayCallback:null,
	string _voiceMediaPath;   // �������·��
	
	// funciton
	// ׼��
	void prepare(string filename);

	// �ͷ�
	void release();

	// ȡ��
	void cancel();

	// д����������
	void writeVoice(string filename,string voiceData);

	// �������
	void clearCache(string filename);

	// ����
	void play(string filename);

	// ��ͣ
	void stop();

	// �������
	int getVoiceLevel(int maxLevel);

	// �����������
	string getVoiceData(string filename);

	// ���ñ��ش洢·��
	void setStorageDir(string dir);

	void download();

private:
	VoiceMgr();
	static VoiceMgr* _instance;

};
