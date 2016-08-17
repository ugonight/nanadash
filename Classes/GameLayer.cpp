#include "GameLayer.h"

USING_NS_CC;

Scene* GameLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameLayer::init()
{
	if (!Layer::init())	return false;
	//this->scheduleUpdate();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景
	Sprite* bg[2] = { Sprite::create("EDGE2.png") , Sprite::create("EDGE2.png") };
	bg[0]->setAnchorPoint(Vec2(0, 0)); bg[1]->setAnchorPoint(Vec2(0, 0));
	bg[0]->setPosition(Vec2(origin.x, origin.y)); bg[1]->setPosition(Vec2(origin.x + visibleSize.width * 2 - 2, origin.y));
	//auto seq = Sequence::create(
	//	MoveBy::create(2.0f, Vec2(-visibleSize.width * 2, 0)), 
	//	MoveBy::create(0.0f, Vec2(visibleSize.width * 2, 0)),
	//	NULL);
	//bg[0]->runAction(RepeatForever::create(seq));	//bg[1]->runAction(RepeatForever::create(seq));
	this->addChild(bg[0], 0, "bg0");	this->addChild(bg[1], 0, "bg1");

	//プレイヤー
	auto animation = Animation::create();
	animation->addSpriteFrameWithFileName("nana_dash01.png");
	animation->addSpriteFrameWithFileName("nana_dash02.png");
	animation->addSpriteFrameWithFileName("nana_dash03.png");
	animation->addSpriteFrameWithFileName("nana_dash02.png");
	animation->setDelayPerUnit(1.0f / 4.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1);
	auto nanadash = Sprite::create("nana_dash01.png");
	nanadash->setPosition(Vec2(origin.x, origin.y + visibleSize.height / 4));
	auto animate = Animate::create(animation);
	nanadash->runAction(RepeatForever::create(animate));
	nanadash->runAction(Sequence::create(MoveBy::create(1.0f, Vec2(100, 0)), CallFunc::create(CC_CALLBACK_0(GameLayer::sUpdate, this)), NULL));
	this->addChild(nanadash, 1, "nanadash");

	
	mTouchTime = mTouchY = mLeaveTime = 0;
	// 画面タップ認識
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch *touch, Event *unused_event) {
		mTouchTime = 1;
		mLeaveTime = 10;
		mTouchY = touch->getLocation().y;
		return true;
	};
	listener->onTouchMoved = [=](Touch *touch, Event *unused_event) {
		mTouchY = touch->getLocation().y;
		return true;
	};
	listener->onTouchEnded = [=](Touch *touch, Event *unused_event) {
		mTouchTime = 0;
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return 1;
}

void GameLayer::update(float delta) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景
	auto bg0 = this->getChildByName("bg0");	auto bg1 = this->getChildByName("bg1");
	bg0->setPositionX(bg0->getPositionX() - 2);
	bg1->setPositionX(bg1->getPositionX() - 2);
	if (bg0->getPositionX() <= -visibleSize.width * 2)
		bg0->setPosition(Vec2(origin.x + visibleSize.width * 2 - 4, origin.y));
	if (bg1->getPositionX() <= -visibleSize.width * 2)
		bg1->setPosition(Vec2(origin.x + visibleSize.width * 2 - 4, origin.y));

	//タップ
	auto nanadash = this->getChildByName("nanadash");
	if (mTouchTime > 0) {
		mTouchTime++;
		nanadash->setPositionX(nanadash->getPositionX() + 2);
		if (mTouchY > origin.y + visibleSize.height / 2) mTouchY = origin.y + visibleSize.height / 2;
		if (nanadash->getPositionY() > mTouchY) {
			nanadash->setPositionY(nanadash->getPositionY() - 2);
		}
		else if (nanadash->getPositionY() < mTouchY) {
			nanadash->setPositionY(nanadash->getPositionY() + 2);
		}
	}
	else {
		if (nanadash->getPositionX() > 0) nanadash->setPositionX(nanadash->getPositionX() - 2);
	}
	if (mLeaveTime > 0)mLeaveTime--;
}

void GameLayer::sUpdate() {
	this->scheduleUpdate();
}