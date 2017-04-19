#include "VocieScene.h"
#include "voicesdk/VoiceMgr.h"
#include "voicesdk/Base64.h"
#include "time.h" 

#define	RECORD_BTN_TAG       1001  //
#define PPLAY_BTN_TAG        1002  //
#define WARN_WINDOW_BTN_TAG  1003  //
#define TESTEXIT_BTN_TAG     1004  //

Scene* VocieScene::createScene(){
	auto scene = Scene::create();
	auto layer = VocieScene::create();
	scene->setName("VocieScene");
	scene->addChild(layer);
	return scene;
}
bool VocieScene::init(){
	if (!Layer::init()){
		return false;
	}
	_lastTouchTime = 0;;
	_voice =nullptr;
	_volume=1;
	_voice_failed=nullptr;
	_lastCheckTime = -1;;
	_timeBar=nullptr;
	MAX_TIME = 15;
	scheduleUpdate();
	return true;
}

void VocieScene::onEnter()
{
	CCLOG("== enter VocieScene  onEnter function ==");
	auto _vSize = Director::getInstance()->getVisibleSize();
	
	_voice = Sprite::create("voice/yuyin_bg.png");
	_voice->setPosition(_vSize.width / 2, _vSize.height / 2);
	addChild(_voice, -1);
	_voice->setVisible(false);
	
	_voice_failed = CCLayerColor::create(ccc4(192, 192, 192, 255), 600, 800);
	_voice_failed->setPosition(_vSize.width / 2-200, _vSize.height / 2-300);
	addChild(_voice_failed,999);
	_voice_failed->setVisible(false);


	auto recordPic = Sprite::create("voice/recorder.png");  
	recordPic->setPosition(80, 130);
	_voice->addChild(recordPic);

	auto label = Label::create();
	label->setString("up  can cancel!!");
	label->setSystemFontSize(24);
	label->setPosition(ccp(140, 40));
	_voice->addChild(label);


	auto btnVoice = Button::create("voice/recordBtn.png");
	btnVoice->addTouchEventListener(CC_CALLBACK_2(VocieScene::touchEvent, this));
	btnVoice->setPosition(Vec2(_vSize.width / 2, 140));
	btnVoice->setTag(RECORD_BTN_TAG);
	addChild(btnVoice);


	auto playBtn = Button::create("voice/adj.png");
	playBtn->addClickEventListener(CC_CALLBACK_1(VocieScene::btnClickCallback, this));
	playBtn->setPosition(Vec2(_vSize.width / 2+200, 140));
	playBtn->setTag(PPLAY_BTN_TAG);
	addChild(playBtn);
//	playBtn->setVisible(false);
    
    
    auto testExitBtn = Button::create("voice/adj.png");
    testExitBtn->addClickEventListener(CC_CALLBACK_1(VocieScene::btnClickCallback, this));
    testExitBtn->setPosition(Vec2(_vSize.width / 2+400, 140));
    testExitBtn->setTag(TESTEXIT_BTN_TAG);
    addChild(testExitBtn);
	//testExitBtn->setVisible(false);


	auto label2 = Label::create();
	label2->setString("record time is too short");
	label2->setSystemFontSize(24);
	label2->setPosition(ccp(300, 500));
	_voice_failed->addChild(label2);
	auto warnOkBtn = Button::create("voice/btn.png");
	warnOkBtn->addClickEventListener(CC_CALLBACK_1(VocieScene::btnClickCallback, this));
	warnOkBtn->setPosition(Vec2(300, 300));
	warnOkBtn->setTag(WARN_WINDOW_BTN_TAG);
	_voice_failed->addChild(warnOkBtn);


	_timeBar = Sprite::create("voice/bar.png");
	_timeBar->setPosition(160, 4);
	_timeBar->setScale(0.0f);
	_voice->addChild(_timeBar);


	Layer::onEnter();
}
void VocieScene::onVoiceOK()
{
	if (_lastTouchTime != 0) {
		VoiceMgr::getInstance()->release();
		long time = dateNow() - _lastTouchTime;
		string msg = VoiceMgr::getInstance()->getVoiceData("record.amr");
		testmsg = msg;
		log(" == get msg content =====:%s", msg.c_str());
		log(" ==get msg length =====:%d", msg.size());

		// net.send("voice_msg", { msg:msg,time : time });
	}
	_voice->setVisible(false);
}

void VocieScene::touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	Button *btn = (Button*)pSender;
	int btnTag = btn->getTag();
	switch (type){
	case Widget::TouchEventType::BEGAN:
		log("==touch begin ==");
        VoiceMgr::getInstance()->prepare("record.amr");
		_lastTouchTime = dateNow();                  // kais
		_voice->setVisible(true);
		_voice_failed->setVisible(false);	      
		break;
	case Widget::TouchEventType::MOVED:
		log("== touch move == ");
		break;
	case Widget::TouchEventType::ENDED:
		log("== touch end == ");
		log("has record time is===%ld", dateNow() - _lastTouchTime);
		if (dateNow() - _lastTouchTime < 1) {   // 1000
			_voice_failed->setVisible(true);
			VoiceMgr::getInstance()->cancel();
			log("== cancel record !!==");
		}
		else {
			log("== onVoiceOK ==");
			onVoiceOK();
		}
		_lastTouchTime = 0;
		break;
	case Widget::TouchEventType::CANCELED:
		log("== touch cancel ==");
		VoiceMgr::getInstance()->cancel();
		_lastTouchTime = 0;
		_voice->setVisible(false);
		break;
	default:
		break;
	}
}

void VocieScene::btnClickCallback(cocos2d::Ref* pSender)
{
	Button *btn = (Button*)pSender;
	int btnTag = btn->getTag();
	switch (btnTag) {
	case WARN_WINDOW_BTN_TAG:
		_voice->setVisible(false);
		_voice_failed->setVisible(false);
		break;
	case PPLAY_BTN_TAG:
		log("== play voice btn callback ==");
		VoiceMgr::getInstance()->play("record.amr");
		break;
    case TESTEXIT_BTN_TAG:  //  test play Voice   when  get data from network
		VoiceMgr::getInstance()->writeVoice("recordttt.amr",testmsg);

            break;
	default:
		break;
	}
}


long VocieScene::dateNow()
{
	time_t rawtime;
	return time(&rawtime);
}

void VocieScene::update(float delta) {

	if (_voice->isVisible() == true && _voice_failed->isVisible() == false) {
			for (int i =0 ;i<7;i++){
			}
		}

	if (_lastTouchTime) {
		int time = dateNow() - _lastTouchTime;
		if (time >= MAX_TIME) {
			onVoiceOK();
			_lastTouchTime = 0;
		}
		else {
			float percent = time / MAX_TIME;
			//_timeBar->setScaleX(1 - percent);
			_timeBar->setScaleX(percent);
		}
	}
}

void VocieScene::onExit()
{
	Layer::onExit();
}
