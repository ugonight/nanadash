#include "LogoLayer.h"
#include "TitleLayer.h"

#include "define.h"

USING_NS_CC;

bool LogoLayer::init() {
	if (!Layer::init()) return false;

	this->scheduleUpdate();

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("rifujin.png");
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	sprite->setOpacity(0.0f);

	auto *seq = Sequence::create(
		FadeIn::create(1.0f),
		FadeIn::create(1.5f),
		FadeOut::create(1.0f),
		CallFunc::create(CC_CALLBACK_0(LogoLayer::end, this)),
		NULL
	);

	PlaySE("rifujin")

	sprite->runAction(seq);

	this->addChild(sprite, 0, "logo");

	return true;
}

void LogoLayer::end() {
	////Close the cocos2d-x game scene and quit the application
	//Director::getInstance()->end();


	//画面遷移する。
	auto scene = TitleLayer::createScene();

	// 0.5秒かけてホワイトアウトしてタイトルに移動する
	auto fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);

	//LogoLayerを破棄してTitleLayerに遷移する
	Director::getInstance()->replaceScene(fade);
}
