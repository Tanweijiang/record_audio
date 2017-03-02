#include "payment/CallAndroidMethod.h"
#include"payment/MahjongPayHandler.h"
//#include "game/mahjong/state/TGameData.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#define JAVA_SRC getJniPath()

CallAndroidMethod* CallAndroidMethod::_instance = 0;

CallAndroidMethod::CallAndroidMethod(){
	_jniPath = "org/cocos2dx/cpp/payment";
}

CallAndroidMethod* CallAndroidMethod::getInstance() {
	if(_instance == 0){
		_instance = new CallAndroidMethod();
	}
	return _instance;
}

const char*  CallAndroidMethod::getJniPath()
{
	return _jniPath.c_str();
}



void CallAndroidMethod::requestEvent(std::string poxiaoId,std::string payId){
    //GAMEDATA::getInstance()->setIsInPay(true);
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("mahjong_start_pay");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo methodInfo;
		auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
		bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"requestEvent","(Ljava/lang/String;Ljava/lang/String;)V");
        jstring poxiao_id = JniHelper::getEnv()->NewStringUTF(poxiaoId.c_str());
		jstring pay_point = JniHelper::getEnv()->NewStringUTF(payId.c_str());;
		if(isHave){
			jobject jobj;
			JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID,poxiao_id,pay_point);
		}
#endif	
}

void CallAndroidMethod::queryEventResult(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"queryPayResult","()V");
    if(isHave){
        jobject jobj;
        JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID);
    }
#endif
}


void CallAndroidMethod::shareToWeChat(std::string url,std::string title, std::string content,bool friends){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"shareToWeChat","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V");
    jstring share_url = JniHelper::getEnv()->NewStringUTF(url.c_str());
    jstring share_title = JniHelper::getEnv()->NewStringUTF(title.c_str());
    jstring share_content = JniHelper::getEnv()->NewStringUTF(content.c_str());
    jboolean share_friends = friends;
    if(isHave){
        jobject jobj;
        JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID,share_url,share_title,share_content,friends);
    }
#endif
}

void CallAndroidMethod::shareImageToWeChat(std::string imagePath,bool friends){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"shareImageToWeChat","(Ljava/lang/String;Z)V");
    jstring share_url = JniHelper::getEnv()->NewStringUTF(imagePath.c_str());
    jboolean share_friends = friends;
    if(isHave){
        jobject jobj;
        JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID,share_url,friends);
    }
#endif
}

/*
  Â¼ÒôÏà¹Ø
*/

void CallAndroidMethod::beginRecordAudio()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/RecordUtil");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "beginRecordAudio", "()V");
	log("it is have =========1===%d", isHave);
	log("it is have =========1===%d", isHave);
	log("it is have =========1===%d", isHave);
	log("it is have =========1===%d", isHave);
	log("it is have =========1===%d", isHave);
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::endRecordAudio()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/RecordUtil");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "endRecordAudio", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::playAudio()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/RecordUtil");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "playAudio", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::deleteAudio()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/RecordUtil");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "deleteFile", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}


void CallAndroidMethod::weChatLogin(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/RecordUtil");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"weChatLogin","()V");
    if(isHave){
        jobject jobj;
        JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID);
    }
#endif
}

void CallAndroidMethod::clearWechatOpenId(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"clearWechatOpenId","()V");
    if(isHave){
        jobject jobj;
        JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID,methodInfo.methodID);
    }
#endif
}

std::string CallAndroidMethod::getSdCardDir(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo methodInfo;
    auto path  = String::createWithFormat("%s%s",JAVA_SRC,"/Payment");
    bool isHave = JniHelper::getStaticMethodInfo(methodInfo,path->getCString(),"getSdCardDir","()Ljava/lang/String;");
    if(isHave){
       	jstring str = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
        ret->autorelease();
        methodInfo.env->DeleteLocalRef(str);
        return ret->getCString();
    }
#endif
    return "";
}

void CallAndroidMethod::getNetInfo(int &netType, int &netLevel)
{

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	JniMethodInfo t;
	bool isHave = JniHelper::getStaticMethodInfo(t,  "org/cocos2dx/cpp/AppActivity", "getNetInfo", "()[I");
	if (isHave)
	{
		jintArray msg = (jintArray)t.env->CallStaticObjectMethod(t.classID, t.methodID);
		int len = t.env->GetArrayLength(msg);
		jint* elems = t.env->GetIntArrayElements(msg, 0);
		if (2 == len)
		{
			netType = elems[0];
			netLevel = elems[1];
		}
		t.env->ReleaseIntArrayElements(msg,elems,0);
		t.env->DeleteLocalRef(t.classID);
	}
	else
	{

	}
	return;
#endif
	netType = 1; netLevel = 1;
}

int CallAndroidMethod::getBatteryPersent(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	jint r = 0;
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "getBatteryPercent", "()I")) {
		r = t.env->CallStaticIntMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
	return r;
#endif
	return 50;
}

void CallAndroidMethod::showFeedBackDialog()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AppActivity", "showFeedDialogOnUiThread", "()V");
	if (isHave){
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

bool CallAndroidMethod::isInstalledWX()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/payment/Payment", "isWxinstalled", "()Z");
	if (isHave){
		
		auto jbool = JniHelper::getEnv()->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
		return jbool;
	}
#endif
	return false;
}
