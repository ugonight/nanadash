
#include "TitleLayer.h"

#include "define.h"


USING_NS_CC;

Scene* TitleLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool TitleLayer::init() {

	if (Layer::init() == false)
		return false;

	this->scheduleUpdate();

	PlayBGM("music")

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// タイトルロゴ
	auto logo_ = Sprite::create("title_logo.png");
	logo_->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 3 / 4));
	logo_->setOpacity(0.0f);
	logo_->setScale(0.9f);

	auto seq = Sequence::create(
		FadeIn::create(0.5f),
		NULL
	);
	logo_->runAction(seq);
	logo_->runAction(ScaleTo::create(0.5f, 1.0f));

	this->addChild(logo_, 1, "logo");

	auto logo_e = Sprite::create("title_logo_e.png");
	logo_e->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 3 / 4));
	logo_e->setOpacity(0.0f);

	auto seq2 = Sequence::create(
		FadeIn::create(0.5f),
		FadeOut::create(1.0f),
		NULL
	);
	auto seq3 = Sequence::create(
		ScaleTo::create(1.5f, 2.0f),
		ScaleTo::create(0.0f, 1.0f),
		NULL
	);

	logo_e->runAction(RepeatForever::create(seq2));
	logo_e->runAction(RepeatForever::create(seq3));

	BlendFunc blend;
	blend.src = 0x8588;
	blend.dst = 1;
	logo_e->setBlendFunc(blend);

	this->addChild(logo_e, 2, "logo_e");


	// 背景
	auto bg_ = Sprite::create("title_back.png");
	bg_->setPosition(Vec2(origin.x, origin.y));
	auto seq4 = Sequence::create(
		MoveBy::create(5.0f, Vec2(visibleSize.width, visibleSize.height)),
		MoveBy::create(0.0f, Vec2(-visibleSize.width, -visibleSize.height)),
		NULL
	);
	bg_->runAction(RepeatForever::create(seq4));
	this->addChild(bg_, 0, "title_bg_0");

	// メニュー
	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// スタートボタン
	auto startBtn = MenuItemImage::create(
		"start_n.png",
		"start_s.png",
		"start_n.png",
		CC_CALLBACK_1(TitleLayer::startBtnCallback, this)
	);
	startBtn->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + 200));
	menu->addChild(startBtn);


	return true;
}

// スタートボタンが押された時のコールバック
void TitleLayer::startBtnCallback(Ref* pSender) {
	PlaySE("start")
}


