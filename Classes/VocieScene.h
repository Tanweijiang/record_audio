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
	
	// һ�ж�ok ���������  ��ʼ¼��
	void onVoiceOK();

	void btnClickCallback(cocos2d::Ref* pSender);
	void touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	long dateNow();

    CREATE_FUNC(VocieScene);
private:
	long      _lastTouchTime;            // ��ʼ¼��ʱ�� 
	Sprite*  _voice;                    // ����ģ������
	int 	 _volume;                   // ����
	CCLayerColor*   _voice_failed;      // ¼��ʧ�ܵ�����
	long      _lastCheckTime;           // ���¼��ʱ��
	Sprite*  _timeBar;                  // ʱ����
	int 	 MAX_TIME;                  // ���ʱ��

	std::string testmsg;

};




// will delete  todo
//EventListenerCustom* _roomRespListener;     // ������Ӧע������
//EventListenerCustom* _reConnectAgain;       // �ٴ�����
//EventListenerCustom* _registerRespListener; // ע����Ӧ����
