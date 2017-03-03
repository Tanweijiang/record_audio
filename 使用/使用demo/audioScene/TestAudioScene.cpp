#include "TestAudioScene.h"
#include "GameRecordAudioManage.h"
#define	RECORD_BTN_TAG 1001
#define	PLAYER_BTN_TAG 1002
#define	DELETE_BTN_TAG 1003

Scene* TestAudioScene::createScene(){
	auto scene = Scene::create();
	auto layer = TestAudioScene::create();
	scene->setName("TestAudioScene");
	scene->addChild(layer);
	return scene;
}
bool TestAudioScene::init(){
	if (!Layer::init()){
		return false;
	}
	return true;
}

void TestAudioScene::onEnter()
{
	CCLOG("== enter TestAudioScene  onEnter function ==");
	Layer::onEnter();

	initUI();
}

void TestAudioScene::initUI()
{
	// Â¼Òô°´Å¥
	Size  _vSize = Director::getInstance()->getVisibleSize();
	auto recordBtn = Button::create("login/visitLogin.png");  
	recordBtn->addTouchEventListener(CC_CALLBACK_2(TestAudioScene::touchEvent, this));
	recordBtn->setPosition(Vec2(_vSize.width / 2, 600));
	recordBtn->setTag(RECORD_BTN_TAG);
	addChild(recordBtn);


	// ²¥·Å°´Å¥
	auto playBtn = Button::create("login/visitLogin.png");
	playBtn->addClickEventListener(CC_CALLBACK_1(TestAudioScene::btnClickCallback, this));
	playBtn->setPosition(Vec2(_vSize.width / 2, 400));
	playBtn->setTag(PLAYER_BTN_TAG);
	addChild(playBtn);

	// É¾³ý°´Å¥
	auto deleteBtn = Button::create("login/visitLogin.png");
	deleteBtn->addClickEventListener(CC_CALLBACK_1(TestAudioScene::btnClickCallback, this));
	deleteBtn->setPosition(Vec2(_vSize.width / 2, 200));
	deleteBtn->setTag(DELETE_BTN_TAG);
	addChild(deleteBtn);
}


void TestAudioScene::touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	Button *btn = (Button*)pSender;
	int btnTag = btn->getTag();
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		GameAudioManage::getInstance()->beginRecordAudio();
		break;
	case Widget::TouchEventType::MOVED:

		break;
	case Widget::TouchEventType::ENDED:
		GameAudioManage::getInstance()->endRecordAudio();
		break;
	case Widget::TouchEventType::CANCELED:
	
		break;
	default:
		break;
	}
}

void TestAudioScene::btnClickCallback(cocos2d::Ref* pSender)
{
	Button *btn = (Button*)pSender;
	int btnTag = btn->getTag();
	switch (btnTag) {
	case PLAYER_BTN_TAG:
		GameAudioManage::getInstance()->playAudio();
		break;
	case DELETE_BTN_TAG:
		GameAudioManage::getInstance()->deleteAudio();
		break;
	default:
		break;
	}
}

void TestAudioScene::onExit()
{
	Layer::onExit();
}
