#include "SceneLobby.h"
#include "LayerTetris.h"
#include "LayerTetrisWifi.h"
//#include "tpb.h"
#include <iostream>


#include "MsgId_pb.h"
#include "C2S_pb.h"
#include "S2C_pb.h"
#include "test_pb.h"

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
	
	TetrisSocket::getInstance()->start("115.28.92.94", 7007); //("121.42.52.249", 5060);//("115.28.92.94", 7000);

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
	Director::getInstance()->replaceScene(TransitionFadeDown::create(1.0f, Layer_TetrisWifi::scene()));
	
	tetris_protocol::C2SLogin *loginbuf = new tetris_protocol::C2SLogin();

	//tetris_protocol::C2SMsg* msg = new tetris_protocol::C2SMsg();//dynamic_cast<C2SMsg*>(new tetris_protocol::C2SLogin());//new tetris_protocol::C2SMsg();
	//msg->set_msgid(C2S_Login);
	//dynamic_cast<C2SLogin*>(msg)->set_channelid(9999);
	//dynamic_cast<C2SLogin*>(msg)->set_channelaccountid("hyq");
	//dynamic_cast<C2SLogin*>(msg)->set_logintoken("test");
	//loginbuf->set_channelid(9999);
	//loginbuf->set_channelaccountid("hyq");
	//loginbuf->set_logintoken("test");
	//
	//tetris_protocol::C2SMsg* msg = new tetris_protocol::C2SMsg();//(C2SMsg*)(loginbuf);
	//msg->set_msgid(C2S_Login);
	////msg->AppendToString();
	////C2SLogin* lTmp = (C2SLogin*) (msg);
	//string s;
	//msg->SerializeToString(&s);
	////string sTmp = loginbuf->SerializeAsString();
	//send_data sendData;
	//sendData.sign = 127;
	//sendData.len = s.length()+4;
	//sendData.body = (char*)s.c_str();

	//hyq::HyqLogin* l = new hyq::HyqLogin();

	//TetrisSocket::getInstance()->send_message(sendData);

	////delete loginbuf;
	//loginbuf = 0;

	//char* begin = TetrisSocket::getInstance()->unsign_short_to_bytes(127);
	//char* len = TetrisSocket::getInstance()->unsign_short_to_bytes(strlen(login.body)+4);
	//char *tmp = new char(strlen(begin) + strlen(len) + s.length());
	//memcpy(tmp, begin, strlen(begin));
	//memcpy(tmp + strlen(begin), len, strlen(len));
	//memcpy(tmp + strlen(begin) + strlen(begin), (char*)s.c_str(), s.length());
	////login.totalLen = login.bodyLen + 1 + strlen(login.cmd) + 4;
	//
	//TetrisMessage* msg = new TetrisMessage(login.cmd, login.body);

	
	//TetrisSocket::getInstance()->sendMessage(tmp, strlen(begin) + strlen(begin) + s.length());
	
	//string  netMsg;
	//loginbuf->SerializeToString(&netMsg);
	//char* mark = TetrisSocket::getInstance()->unsign_short_to_bytes(127);
	//char* length = TetrisSocket::getInstance()->unsign_short_to_bytes(netMsg.length() + 4);
	//char* ss = TetrisSocket::getInstance()->unsign_short_to_bytes(127, false);

	//log("ss");
	//log(ss);
	
}

void SceneLobby::CallbackHelp(Ref* sender)
{
	CCLOG("CallbackHelp");
}

void SceneLobby::CallbackSetting(Ref* sender)
{
	CCLOG("CallbackSetting");
}

