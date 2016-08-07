#pragma once

#include "cocos2d.h"

class LogoLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(LogoLayer);
private:
	void end();
};
