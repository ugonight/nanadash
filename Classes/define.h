#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <string.h>
using namespace CocosDenshion;

extern char soundFileName[255];	//����ɑ��̏ꏊ�Ŏg��Ȃ��ŁI�I�I�I�I�I�I�I�I

extern void makeFileName(char* fileName, char* result);

#define LoadBGM(FN) makeFileName(FN, soundFileName); SimpleAudioEngine::getInstance()->preloadBackgroundMusic(soundFileName);
#define LoadSE(FN) makeFileName(FN, soundFileName); SimpleAudioEngine::getInstance()->preloadEffect(soundFileName);
#define PlayBGM(FN) makeFileName(FN, soundFileName); SimpleAudioEngine::getInstance()->playBackgroundMusic(soundFileName, true);
#define PlaySE(FN) makeFileName(FN, soundFileName); SimpleAudioEngine::getInstance()->playEffect(soundFileName);