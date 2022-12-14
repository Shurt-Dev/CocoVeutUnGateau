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

    TMXTiledMap* _tilemap = TMXTiledMap::create("map/Map " + to_string(mapNumber) + ".tmx");
    auto backgroundSprite = Sprite::create("map/Background " + to_string(backgroundNumber) + ".png");

    backgroundSprite->setPosition(Vec2(480, 320));

    Sprite* arrow = Sprite::create("map/Arrow.png");
    arrow->setScale(0.5);
    arrow->setAnchorPoint(Vec2(0, 0));
    arrow->setPosition(Vec2(60,440));

    MoveTo* moveUp = MoveTo::create(1, Vec2(arrow->getPositionX(), arrow->getPositionY() + 20));
    MoveTo* moveDown = MoveTo::create(1, Vec2(arrow->getPositionX(), arrow->getPositionY() - 20));
    MoveTo* moveRight = MoveTo::create(1, Vec2(arrow->getPositionX() + 20, arrow->getPositionY()));
    MoveTo* moveLeft = MoveTo::create(1, Vec2(arrow->getPositionX() - 20, arrow->getPositionY()));

    addChild(backgroundSprite);
    addChild(_tilemap);
    addChild(arrow);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}
