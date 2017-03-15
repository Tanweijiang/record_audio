#pragma once
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace ui;
class TestAudioScene : public Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onEnter() override;

	virtual void onExit() override;

	void initUI();

	void btnClickCallback(cocos2d::Ref* pSender);
	void touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

    CREATE_FUNC(TestAudioScene);
private:

};




// will delete  todo
//EventListenerCustom* _roomRespListener;     // 房间响应注册侦听
//EventListenerCustom* _reConnectAgain;       // 再次重连
//EventListenerCustom* _registerRespListener; // 注册响应侦听
