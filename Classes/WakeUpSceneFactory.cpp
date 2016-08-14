#include "WakeUpSceneFactory.h"
#include "LogoLayer.h"

#include "define.h"

USING_NS_CC;

cocos2d::Scene* WakeUpSceneFactory::create() {

	auto scene = Scene::create();

	LogoLayer *logoLayer = LogoLayer::create();
	scene->addChild(logoLayer, 1, "logoLayer");

	//preload
	LoadSE("rifujin")
	LoadSE("start")
	LoadBGM("music")

	return scene;
}