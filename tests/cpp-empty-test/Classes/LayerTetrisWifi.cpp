#include "LayerTetrisWifi.h"
#include "TetrisCommon.h"
#include "Tetris.h"
#include "SceneLobby.h"

static Layer_TetrisWifi* g_s_p_tetris_wifi = 0;

Layer_TetrisWifi::Layer_TetrisWifi()
{

}

Layer_TetrisWifi::~Layer_TetrisWifi()
{
}

cocos2d::Scene* Layer_TetrisWifi::scene()
{
	auto scene = Scene::create();

	Layer_TetrisWifi* tetris = Layer_TetrisWifi::create();
	scene->addChild(tetris);

	return scene;
}

bool Layer_TetrisWifi::init()
{
	bool ret = true;

	auto factor = Director::getInstance()->getContentScaleFactor();

	auto win_size = Director::getInstance()->getWinSize();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto layer_bg = LayerColor::create(Color4B::WHITE);
	addChild(layer_bg);
	
	//自己的方块区域
	auto layer_bg_tetris = LayerColor::create(myColor4BOrange);
	layer_bg_tetris->setContentSize(Size(C_W_RECT*C_COLUMN, C_H_RECT*C_ROW));
	layer_bg_tetris->setPosition(Vec2(0, win_size.height - C_H_RECT*C_ROW));
	addChild(layer_bg_tetris);

	auto layer_title_tetris_2 = LayerColor::create(myColor4BDeepAqua);
	layer_title_tetris_2->setContentSize(Size(C_W_RECT_2*C_COLUMN, 18));
	layer_title_tetris_2->setPosition(Vec2(layer_bg_tetris->getPositionX() + layer_bg_tetris->getContentSize().width + C_SPACE,
		layer_bg_tetris->getPositionY() + layer_bg_tetris->getContentSize().height - layer_title_tetris_2->getContentSize().height));
	addChild(layer_title_tetris_2);

	//玩家2的方块区域
	auto layer_bg_tetris_2 = LayerColor::create(myColor4BBlueViolet);
	layer_bg_tetris_2->setContentSize(Size(C_W_RECT_2*C_COLUMN, C_H_RECT_2*C_ROW));
	layer_bg_tetris_2->setPosition(Vec2(layer_title_tetris_2->getPositionX() ,
		layer_title_tetris_2->getPositionY() - layer_bg_tetris_2->getContentSize().height));
	addChild(layer_bg_tetris_2);

	

	//玩家3的方块区域
	auto layer_bg_tetris_3 = LayerColor::create(myColor4BBlueViolet);
	layer_bg_tetris_3->setContentSize(Size(C_W_RECT_2*C_COLUMN, C_H_RECT_2*C_ROW));
	layer_bg_tetris_3->setPosition(Vec2(layer_bg_tetris_2->getPositionX(), layer_bg_tetris->getPositionY() ));
	addChild(layer_bg_tetris_3);

	auto layer_title_tetris_3 = LayerColor::create(myColor4BDeepAqua);
	layer_title_tetris_3->setContentSize(Size(layer_title_tetris_2->getContentSize().width, layer_title_tetris_2->getContentSize().height));
	layer_title_tetris_3->setPosition(Vec2(layer_bg_tetris_3->getPositionX(),
									layer_bg_tetris_3->getPositionY() + layer_bg_tetris_3->getContentSize().height));
	addChild(layer_title_tetris_3);

	//道具层
	auto layer_prop = LayerColor::create(myColor4BYellow);
	layer_prop->setContentSize(Size(win_size.width, 20));
	layer_prop->setPosition(Vec2(layer_bg_tetris->getPositionX(), layer_bg_tetris->getPositionY()-C_SPACE-layer_prop->getContentSize().height));
	addChild(layer_prop);

	//个人信息层
	auto layer_myinfo = LayerColor::create(myColor4BDeepSkyBlue);
	layer_myinfo->setContentSize(Size(win_size.width, win_size.height - layer_bg_tetris->getContentSize().height - C_SPACE*2 - layer_prop->getContentSize().height));
	layer_myinfo->setPosition(Vec2(0,0));
	addChild(layer_myinfo);

	return ret;
}

Layer_TetrisWifi* Layer_TetrisWifi::create()
{
	Layer_TetrisWifi* tetris = new Layer_TetrisWifi();
	if (tetris && tetris->init())
	{
		tetris->autorelease();
		return tetris;
	}
	else
	{
		delete tetris;
		tetris = 0;
		return 0;
	}
}


void Layer_TetrisWifi::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Layer_TetrisWifi::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Layer_TetrisWifi::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	
}







void Layer_TetrisWifi::onExit()
{
	Layer::onExit();
}



