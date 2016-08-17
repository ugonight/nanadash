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
	this->scheduleUpdate();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//”wŒi
	Sprite* bg[2] = { Sprite::create("EDGE2.png") , Sprite::create("EDGE2.png") };
	bg[0]->setAnchorPoint(Vec2(0, 0)); bg[1]->setAnchorPoint(Vec2(0, 0));
	bg[0]->setPosition(Vec2(origin.x, origin.y)); bg[1]->setPosition(Vec2(origin.x + visibleSize.width * 2 - 2, origin.y));
	//auto seq = Sequence::create(
	//	MoveBy::create(2.0f, Vec2(-visibleSize.width * 2, 0)), 
	//	MoveBy::create(0.0f, Vec2(visibleSize.width * 2, 0)),
	//	NULL);
	//bg[0]->runAction(RepeatForever::create(seq));	//bg[1]->runAction(RepeatForever::create(seq));
	this->addChild(bg[0], 0, "bg0");	this->addChild(bg[1], 0, "bg1");

	return 1;
}

void GameLayer::update(float delta) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg0 = this->getChildByName("bg0");	auto bg1 = this->getChildByName("bg1");
	
	bg0->setPositionX(bg0->getPositionX() - 2);
	bg1->setPositionX(bg1->getPositionX() - 2);
	if (bg0->getPositionX() <= -visibleSize.width * 2)
		bg0->setPosition(Vec2(origin.x + visibleSize.width * 2 - 3, origin.y));
	if (bg1->getPositionX() <= -visibleSize.width * 2)
		bg1->setPosition(Vec2(origin.x + visibleSize.width * 2 - 3, origin.y));
}