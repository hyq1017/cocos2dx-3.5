#include "SceneLobby.h"
#include "LayerTetris.h"
#include "LayerTetrisWifi.h"
//#include "tpb.h"
#include <iostream>


#include "MsgId_pb.h"
#include "C2S_pb.h"
#include "S2C_pb.h"
#include "test_pb.h"
#include "TetrisSocket.h"
#include "TetrisSocketCommon.h"


using namespace std;
using namespace tetris_protocol;

Scene* SceneLobby::scene()
{
    auto scene = Scene::create();
    SceneLobby *layer = SceneLobby::create();
    scene->addChild(layer);

    return scene;
}

bool SceneLobby::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	auto factor = Director::getInstance()->getContentScaleFactor();

	auto winsize = Director::getInstance()->getWinSize();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto layer_bg = LayerColor::create(Color4B::ORANGE);
	addChild(layer_bg);

	auto title = Label::createWithTTF("Hello Tetris", "fonts/aleta.ttf", 16);
	title->setPosition(Vec2(winsize.width / 2, winsize.height - 50));
	this->addChild(title);



	TTFConfig ttfConfig("fonts/aleta.ttf", 10);
	auto blank = 30;
	float y = origin.y + visibleSize.height / 2;

	auto l_start = Label::createWithTTF(ttfConfig, "SINGLE");
	auto l_rank = Label::createWithTTF(ttfConfig, "WIFI");
	//auto l_help = Label::createWithTTF(ttfConfig, "HELP");

	auto item_start = MenuItemLabel::create(l_start, CC_CALLBACK_1(SceneLobby::CallbackStart, this));
	auto item_rank = MenuItemLabel::create(l_rank, CC_CALLBACK_1(SceneLobby::CallbackRank, this));
	//auto item_help = MenuItemLabel::create(l_help, CC_CALLBACK_1(SceneLobby::CallbackHelp, this));

	item_start->setPosition(Vec2(origin.x + visibleSize.width / 2-40, y));
	item_rank->setPosition(Vec2(origin.x + visibleSize.width / 2+40, y));
	//item_help->setPosition(Vec2(origin.x + visibleSize.width / 2, y - 30 * 2));

	auto menu = Menu::create(item_start, item_rank/*, item_help*/, nullptr);
	menu->setPosition(Vec2(0, 0));
	this->addChild(menu);

	

    return true;
}

void SceneLobby::onEnter()
{
	Layer::onEnter();
	
	TetrisSocket::getInstance()->start("127.0.0.1", 7000); //("127.0.0.1", 6000);//("115.28.92.94", 7007); //("121.42.52.249", 5060);//("115.28.92.94", 7000);

}

void SceneLobby::onExit()
{
	Layer::onExit();
}

void SceneLobby::CallbackStart(Ref* sender)
{
	CCLOG("CallbackStart");
	Director::getInstance()->replaceScene(TransitionFadeDown::create(1.0f, Layer_Tetris::scene()));
}

void SceneLobby::CallbackRank(Ref* sender)
{
	CCLOG("CallbackRank");
	//Director::getInstance()->replaceScene(TransitionFadeDown::create(1.0f, Layer_TetrisWifi::scene()));
	
	tetris_protocol::C2SLogin *loginbuf = new tetris_protocol::C2SLogin();
	
	hyq::HyqLogin* l = new hyq::HyqLogin();
	l->set_channelaccountid("hyq");
	l->set_channelid(9999);
	l->set_logintoken("hello");

	string s;
	l->SerializeToString(&s);

	MSG_DATA data;
	data.sign = 127;
	data.len = s.length();
	data.body = (char*)s.c_str();

	TetrisSocket::getInstance()->send_message(data);
	
}

void SceneLobby::CallbackHelp(Ref* sender)
{
	CCLOG("CallbackHelp");
}

void SceneLobby::CallbackSetting(Ref* sender)
{
	CCLOG("CallbackSetting");
}

