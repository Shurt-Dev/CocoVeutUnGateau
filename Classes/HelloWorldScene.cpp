/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include <string>

USING_NS_CC;
using namespace std;

int mapNumber = 1; // 1 to 6
int backgroundNumber = 1; // 1 or 2

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    _tileMap = TMXTiledMap::create("map/Map " + to_string(mapNumber) + ".tmx");
    backgroundSprite = Sprite::create("map/Fond " + to_string(backgroundNumber) + ".png");
    backgroundSprite->setPosition(Vec2(480, 320));

    arrow = Sprite::create("map/Arrow.png");
    arrow->setScale(0.5);
    arrow->setAnchorPoint(Vec2(0, 0));
    arrow->setPosition(Vec2(60,440));

    addChild(backgroundSprite);
    addChild(_tileMap);
    addChild(arrow);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt) {
    bool right = true; // Right or Left
    // Moving functions
    MoveBy* moveUp = MoveBy::create(1, Vec2(0, 20));
    MoveBy* moveDown = MoveBy::create(1, Vec2(0, -20));
    MoveBy* moveRight = MoveBy::create(1, Vec2(20, 0));
    MoveBy* moveLeft = MoveBy::create(1, Vec2(-20, 0));

    DelayTime* pause = DelayTime::create(1); // Delay

    // Moving sequences : Function + delay
    Sequence* moveUpSeq = Sequence::create(moveUp, pause, nullptr); 
    Sequence* moveDownSeq = Sequence::create(moveDown, pause, nullptr); 
    Sequence* moveRightSeq = Sequence::create(moveRight, pause, nullptr); 
    Sequence* moveLeftSeq = Sequence::create(moveLeft, pause, nullptr);

    // Moving from Right to Left to Right to Left to Right to Left to Right to Left to Right to Left...
    if (right) {
        if (_tileMap->getLayer("Calque de Tuiles 1")->getTileGIDAt(Vec2((arrow->getPositionX() / 20) + 1, arrow->getPositionY() / 20)) == 0) {
            arrow->runAction(moveRightSeq->clone());
            arrow->setRotation(0);
        } else {
            right = false;
        }
    } else {
        if (_tileMap->getLayer("Calque de Tuiles 1")->getTileGIDAt(Vec2((arrow->getPositionX() / 20) - 1, arrow->getPositionY() / 20)) == 0) {
            arrow->runAction(moveLeftSeq->clone());
            arrow->setRotation(180);
        }
        else {
            right = true;
        }
    }
}