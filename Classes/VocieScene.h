#pragma once
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace ui;
class VocieScene : public Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onEnter() override;

	virtual void onExit() override;

	void update(float delta);
	
	// 一切都ok 理想情况下  开始录音
	void onVoiceOK();

	void btnClickCallback(cocos2d::Ref* pSender);
	void touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	long dateNow();

    CREATE_FUNC(VocieScene);
private:
	long      _lastTouchTime;            // 开始录音时间 
	Sprite*  _voice;                    // 语音模块容器
	int 	 _volume;                   // 音量
	CCLayerColor*   _voice_failed;      // 录音失败弹出框
	long      _lastCheckTime;           // 检查录音时间
	Sprite*  _timeBar;                  // 时间条
	int 	 MAX_TIME;                  // 最大时间

	std::string testmsg;

};




// will delete  todo
//EventListenerCustom* _roomRespListener;     // 房间响应注册侦听
//EventListenerCustom* _reConnectAgain;       // 再次重连
//EventListenerCustom* _registerRespListener; // 注册响应侦听
