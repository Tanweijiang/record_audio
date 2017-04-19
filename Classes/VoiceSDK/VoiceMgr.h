#pragma once
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

#define RECORD_AUDIO_PATH "record_audio.amr"
#define DOWNLOAD_AUDIO_PATH  "download_audio.amr"

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

	void prepare();
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

	void writeVoice(string voiceData);
	// д����������  ���ӷ������յ�����֪ͨ��ʱ��   when get data from service then  call this function 
	void writeVoice(string filename, string voiceData);

	// �����������  // Ȼ����Է��͵�������         when need send data to service 
	string getVoiceData(string filename);

	string getVoiceData();

	// ���ñ��ش洢·��
	void setStorageDir(string dir);

	void download();

private:
	VoiceMgr();
	static VoiceMgr* _instance;
};
