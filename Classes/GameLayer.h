#pragma once

#include "cocos2d.h"

class GameLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(GameLayer);
private:
	int mTouchTime;
	int mTouchY;
	int mLeaveTime;

	void sUpdate();	//scheduleUpdate()
};