#include "VoiceSDK/android/CallAndroidMethod.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#define JAVA_SRC getJniPath()

CallAndroidMethod* CallAndroidMethod::_instance = 0;

CallAndroidMethod::CallAndroidMethod(){
	_jniPath = "org/cocos2dx/cpp/voicesdk";
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



/*
* china good voice  v2   start
*/
void CallAndroidMethod::prepare(std::string filename)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoiceRecorder");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "prepare", "(Ljava/lang/String;)V");
	jstring filename_j = JniHelper::getEnv()->NewStringUTF(filename.c_str());
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, filename_j);
	}
#endif
}

void CallAndroidMethod::release()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoiceRecorder");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "release", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::cancel()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoiceRecorder");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "cancel", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::play(std::string filename)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoicePlayer");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "play", "(Ljava/lang/String;)V");
	jstring filename_j = JniHelper::getEnv()->NewStringUTF(filename.c_str());
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, filename_j);
	}
#endif
}

void CallAndroidMethod::stop()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoicePlayer");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "stop", "()V");
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
#endif
}

void CallAndroidMethod::getVoiceLevel()
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	JniMethodInfo methodInfo;
//	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoiceRecorder");
//	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "getVoiceLevel", "()V");
//	if (isHave) {
//		jobject jobj;
//		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
//	}
//#endif
}

void CallAndroidMethod::setStorageDir(std::string dir)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo methodInfo;
	auto path = String::createWithFormat("%s%s", JAVA_SRC, "/VoiceRecorder");
	bool isHave = JniHelper::getStaticMethodInfo(methodInfo, path->getCString(), "setStorageDir", "(Ljava/lang/String;)V");
	jstring dir_j = JniHelper::getEnv()->NewStringUTF(dir.c_str());
	if (isHave) {
		jobject jobj;
		JniHelper::getEnv()->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, dir_j);
	}
#endif
}
/*
* china good voice  v2   end
*/

