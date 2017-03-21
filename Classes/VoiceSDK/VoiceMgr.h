#pragma once
#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//USING_NS_CC_EXT;
//USING_NS_CC;
//using namespace ui;
//using namespace std;

USING_NS_CC;
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

	// �������
	void clearCache(string filename);

	// ����
	void play(string filename);

	// ��ͣ
	void stop();

	// �������
	int getVoiceLevel(int maxLevel);

	// д����������  ���ӷ������յ�����֪ͨ��ʱ��   when get data from service then  call this function 
	void writeVoice(string filename, string voiceData);

	// �����������  // Ȼ����Է��͵�������         when need send data to service 
	string getVoiceData(string filename);

	// ���ñ��ش洢·��
	void setStorageDir(string dir);

	void download();

private:
	VoiceMgr();
	static VoiceMgr* _instance;
};
