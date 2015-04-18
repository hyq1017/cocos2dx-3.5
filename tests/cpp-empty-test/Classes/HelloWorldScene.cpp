#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "LayerTetris.h"
#include <string>


using namespace std;

Scene* SceneIntro::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    SceneIntro *layer = SceneIntro::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SceneIntro::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	m_map = cocos2d::experimental::TMXTiledMap::create("1/hyq.tmx");//("TileMaps/orthogonal-test2.tmx");

	if (m_map)
	{
		addChild(m_map, 0, 100);

		auto group = m_map->getObjectGroup("hero");
		ValueMap spawnPoint = group->getObject("pa");
		ValueMap;
		Value v_x = spawnPoint["x"];//获取对象的坐标  
		Value v_y = spawnPoint["y"];//获取对象的坐标  

		m_player = Sprite::create("1/www.png");
		m_player->setPosition(Vec2(v_x.asFloat(), v_y.asFloat()));
		addChild(m_player);
	}
	else
	{
		CCLOG("error");
	}

    
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(SceneIntro::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SceneIntro::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SceneIntro::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void SceneIntro::menuCloseCallback(Ref* sender)
{
	Director::getInstance()->replaceScene(Layer_Tetris::scene());
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
}

bool SceneIntro::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	//auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	float offsetX = 1;
	float offsetY = 1;
	if (locationInNode.x > m_player->getPositionX())
	{
		m_player->setPosition(Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY()));
	}
	else if (locationInNode.x < m_player->getPositionX())
	{
		m_player->setPosition(Vec2(m_player->getPositionX() - offsetX, m_player->getPositionY()));
	}


	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
		//target->setOpacity(180);
		return true;
	}
	return false;
}

void SceneIntro::onTouchMoved(Touch* touch, Event* event)
{

}

void SceneIntro::onTouchEnded(Touch* touch, Event* event)
{

}
