#ifndef _CALLANDROIDMETHOD_H_
#define _CALLANDROIDMETHOD_H_

#include "cocos2d.h"

using namespace cocos2d;

class CallAndroidMethod{
public:
	/*
	 * ¼�����
	 * ��ʼ¼�� ��ť����
	 * ¼������ ��ť����
	 * ɾ��¼��
	 * ����¼��
	 */
	void beginRecordAudio();
	void endRecordAudio();
	void deleteAudio();
	void playAudio();
	
	/*
	* China good voice 
	* ��ʼ¼�� ��ť����
	* ¼������ ��ť����
	* ɾ��¼��
	* ����¼��
	*/
	void prepare(std::string filename);
	void release();
	void cancel();
	void play(std::string filename);
	void stop();
	void getVoiceLevel();
	void setStorageDir(std::string dir);

	static CallAndroidMethod* getInstance();
	void requestEvent(std::string poxiaoId,std::string payId);  // ΢��֧���µ�
    void queryEventResult();    // ��ѯ֧�����
    void weChatLogin();         // ΢�ŵ�¼
    void clearWechatOpenId();    
    void shareToWeChat(std::string url,std::string title,std::string content,bool friends);
    void shareImageToWeChat(std::string imagePath,bool friends);  // ����ͼƬ
    std::string getSdCardDir();   // ���sd��·��
	bool isInstalledWX();         // �Ƿ�װwechat
	const char* getJniPath();

	void showFeedBackDialog();
public:
	/* ==============================================================================
	 * �����������õ�����������Ϣ  
	 *    netType   -1: û������    1: WIFI     2: �ƶ�����  
	 *	  netLevel  1: None 2:poor  3:moderate  4:good  5:great
	 * �� �� �ߣ�ckj
	 * �������ڣ�2016��12��19��16:56:17
	 * ==============================================================================*/
	void getNetInfo(int &netType, int &netLevel);
	int  getBatteryPersent();
private:
	std::string _jniPath;
	CallAndroidMethod();
	static CallAndroidMethod* _instance;
};
#endif
