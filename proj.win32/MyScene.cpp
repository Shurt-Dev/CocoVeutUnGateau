#include "MyScene.h"

USING_NS_CC;

Scene* MyScene::createScene()
{
    return MyScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MySceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MyScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(MyScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "hello world"
    // create and initialize a label
    
    auto label = label::createwithttf("hello world", "fonts/marker felt.ttf", 24);
    if (label == nullptr)
    {
        problemloading("'fonts/marker felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setposition(vec2(origin.x + visiblesize.width / 2,
            origin.y + visiblesize.height - label->getcontentsize().height));
    
        // add the label as a child to this layer
        this->addchild(label, 1);
    }
    
    // add "myscene" splash screen"
    auto sprite = sprite::create("hu_tao.jpg");
    if (sprite == nullptr)
    {
        problemloading("'helloworld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setposition(vec2(visiblesize.width / 2 + origin.x, visiblesize.height / 2 + origin.y));
    
        // add the sprite as a child to this layer
        this->addchild(sprite, 0);
    }


    return true;
}


void MyScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
