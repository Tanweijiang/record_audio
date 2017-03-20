#ifndef _CALLANDROIDMETHOD_H_
#define _CALLANDROIDMETHOD_H_

#include "cocos2d.h"

using namespace cocos2d;

class CallAndroidMethod{
public:
	/*
	 * 录音相关
	 * 开始录音 按钮按下
	 * 录音结束 按钮弹起
	 * 删除录音
	 * 播放录音
	 */
	void beginRecordAudio();
	void endRecordAudio();
	void deleteAudio();
	void playAudio();
	
	/*
	* China good voice 
	* 开始录音 按钮按下
	* 录音结束 按钮弹起
	* 删除录音
	* 播放录音
	*/
	void prepare(std::string filename);
	void release();
	void cancel();
	void play(std::string filename);
	void stop();
	void getVoiceLevel();
	void setStorageDir(std::string dir);

	static CallAndroidMethod* getInstance();
	void requestEvent(std::string poxiaoId,std::string payId);  // 微信支付下单
    void queryEventResult();    // 查询支付结果
    void weChatLogin();         // 微信登录
    void clearWechatOpenId();    
    void shareToWeChat(std::string url,std::string title,std::string content,bool friends);
    void shareImageToWeChat(std::string imagePath,bool friends);  // 分享图片
    std::string getSdCardDir();   // 获得sd卡路劲
	bool isInstalledWX();         // 是否安装wechat
	const char* getJniPath();

	void showFeedBackDialog();
public:
	/* ==============================================================================
	 * 功能描述：得到网络数据信息  
	 *    netType   -1: 没有网络    1: WIFI     2: 移动数据  
	 *	  netLevel  1: None 2:poor  3:moderate  4:good  5:great
	 * 创 建 者：ckj
	 * 创建日期：2016年12月19日16:56:17
	 * ==============================================================================*/
	void getNetInfo(int &netType, int &netLevel);
	int  getBatteryPersent();
private:
	std::string _jniPath;
	CallAndroidMethod();
	static CallAndroidMethod* _instance;
};
#endif
