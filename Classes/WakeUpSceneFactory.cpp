#include "WakeUpSceneFactory.h"
#include "LogoLayer.h"

USING_NS_CC;

cocos2d::Scene* WakeUpSceneFactory::create() {

	auto scene = Scene::create();

	LogoLayer *logoLayer = LogoLayer::create();
	scene->addChild(logoLayer, 1, "logoLayer");

	return scene;
}