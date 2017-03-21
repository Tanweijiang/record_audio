#include "AppDelegate.h"
#include "audio/include/AudioEngine.h"
#include "VocieScene.h"
USING_NS_CC;
using namespace experimental;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::create("WX_NiuNiu");
		director->setOpenGLView(glview);
	}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	glview->setFrameSize(1280, 720);
	glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::EXACT_FIT);
#endif
#if (CC_TARGET_PLATFORM==CC_PLATFORM_MAC)
	glview->setFrameSize(960, 540);
	glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::EXACT_FIT);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//if (visibleSize.width / visibleSize.height > 1280.0 / 720.0){
		//glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::EXACT_FIT);
	//}
	//else{
        glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::SHOW_ALL);
	//}
#endif

	// turn on display FPS
	director->setDisplayStats(false);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object

	auto scene = VocieScene::createScene();
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();
	// if you use SimpleAudioEngine, it must be pause
	AudioEngine::pauseAll();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();
	// if you use SimpleAudioEngine, it must resume here
	AudioEngine::resumeAll();
}
