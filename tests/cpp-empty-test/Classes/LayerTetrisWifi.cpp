#include "LayerTetrisWifi.h"
#include "TetrisCommon.h"
#include "Tetris.h"
#include "SceneLobby.h"

static Layer_TetrisWifi* g_s_p_tetris_wifi = 0;

static Tetris* l_s_p_tetris_1 = 0;
static Tetris* l_s_p_tetris_2 = 0;
static Tetris* l_s_p_tetris_3 = 0;

Layer_TetrisWifi::Layer_TetrisWifi():
m_point_touchBegin(Vec2(0,0)),
m_layer_game_1(0),
m_layer_game_2(0),
m_layer_game_3(0),
m_layer_gameTitle_2(0),
m_layer_gameTitle_3(0),
m_layer_prop(0),
m_layer_myInfo(0),
m_layer_myTip(0),
m_b_bottom(false),
m_t_touchBegin(0.0)
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
	
	
	auto layer_bg_tetris = LayerColor::create(myColor4BOrange);
	if (layer_bg_tetris)
	{//自己的方块区域
		m_layer_game_1 = layer_bg_tetris;
		layer_bg_tetris->setContentSize(Size(C_SPACE_TETRIS + (C_W_RECT + C_SPACE_TETRIS)*C_COLUMN,
											  C_SPACE_TETRIS+(C_H_RECT + C_SPACE_TETRIS)*C_ROW));
		layer_bg_tetris->setPosition(Vec2(0, win_size.height - layer_bg_tetris->getContentSize().height));
		addChild(layer_bg_tetris);
	}
	
	auto layer_title_tetris_2 = LayerColor::create(myColor4BDeepAqua);
	if (layer_title_tetris_2)
	{
		layer_title_tetris_2->setContentSize(Size(C_W_RECT_2*C_COLUMN, 18));
		layer_title_tetris_2->setPosition(Vec2(layer_bg_tetris->getPositionX() + layer_bg_tetris->getContentSize().width + C_SPACE,
			layer_bg_tetris->getPositionY() + layer_bg_tetris->getContentSize().height - layer_title_tetris_2->getContentSize().height));
		addChild(layer_title_tetris_2);


		//名字：
		TTFConfig config("fonts/aleta.ttf", 5);

		int blank = 5;

		auto label = Label::createWithTTF(config, "name:wyh");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_title_tetris_2->getContentSize().height / 2 + blank));
		layer_title_tetris_2->addChild(label);

		label = Label::createWithTTF(config, "lv:v13");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_title_tetris_2->getContentSize().height / 2-blank));
		layer_title_tetris_2->addChild(label);
	}
	
	auto layer_bg_tetris_2 = LayerColor::create(myColor4BBlueViolet);
	if (layer_bg_tetris_2)
	{//玩家2的方块区域
		m_layer_game_2 = layer_bg_tetris_2;
		layer_bg_tetris_2->setContentSize(Size(C_W_RECT_2*C_COLUMN, C_H_RECT_2*C_ROW));
		layer_bg_tetris_2->setPosition(Vec2(layer_title_tetris_2->getPositionX(),
			layer_title_tetris_2->getPositionY() - layer_bg_tetris_2->getContentSize().height));
		addChild(layer_bg_tetris_2);
	}

	auto layer_bg_tetris_3 = LayerColor::create(myColor4BBlueViolet);
	if (layer_bg_tetris_3)
	{//玩家3的方块区域
		m_layer_game_3 = layer_bg_tetris_3;
		layer_bg_tetris_3->setContentSize(Size(C_W_RECT_2*C_COLUMN, C_H_RECT_2*C_ROW));
		layer_bg_tetris_3->setPosition(Vec2(layer_bg_tetris_2->getPositionX(), layer_bg_tetris->getPositionY()));
		addChild(layer_bg_tetris_3);
	}
	
	auto layer_title_tetris_3 = LayerColor::create(myColor4BDeepAqua);
	if (layer_title_tetris_3)
	{
		layer_title_tetris_3->setContentSize(Size(layer_title_tetris_2->getContentSize().width, layer_title_tetris_2->getContentSize().height));
		layer_title_tetris_3->setPosition(Vec2(layer_bg_tetris_3->getPositionX(),
			layer_bg_tetris_3->getPositionY() + layer_bg_tetris_3->getContentSize().height));
		addChild(layer_title_tetris_3);

		TTFConfig config("fonts/aleta.ttf", 5);

		int blank = 5;

		auto label = Label::createWithTTF(config, "name:hf");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_title_tetris_3->getContentSize().height / 2 + blank));
		layer_title_tetris_3->addChild(label);

		label = Label::createWithTTF(config, "lv:v13");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_title_tetris_3->getContentSize().height / 2 - blank));
		layer_title_tetris_3->addChild(label);
	}
	

	auto layer_prop = LayerColor::create(myColor4BYellow);
	if (layer_prop)
	{//道具层
		m_layer_prop = layer_prop;
		layer_prop->setContentSize(Size(win_size.width, 20));
		layer_prop->setPosition(Vec2(layer_bg_tetris->getPositionX(), layer_bg_tetris->getPositionY() - C_SPACE - layer_prop->getContentSize().height));
		addChild(layer_prop);
	}
	
	auto layer_myinfo = LayerColor::create(myColor4BDeepSkyBlue);
	if (layer_myinfo)
	{//个人信息层
		m_layer_myInfo = layer_myinfo;
		layer_myinfo->setContentSize(Size(win_size.width, win_size.height - layer_bg_tetris->getContentSize().height - C_SPACE * 2 - layer_prop->getContentSize().height));
		layer_myinfo->setPosition(Vec2(0, 0));
		addChild(layer_myinfo);

		//名字：
		TTFConfig config("fonts/aleta.ttf", 10);

		int blank = 20;

		auto label = Label::createWithTTF(config, "name:hyq");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_myinfo->getContentSize().height/2+blank));
		layer_myinfo->addChild(label);

		label = Label::createWithTTF(config, "level:v13");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_myinfo->getContentSize().height / 2));
		layer_myinfo->addChild(label);

		label = Label::createWithTTF(config, "score:199484");
		label->setTextColor(Color4B::BLACK);
		label->setAnchorPoint(Vec2(0, 0.5));
		label->setPosition(Vec2(0, layer_myinfo->getContentSize().height / 2-blank));
		layer_myinfo->addChild(label);
	}
	int space = 1;
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{

			auto layer = LayerColor::create(Color4B::WHITE);
			layer->setContentSize(Size(C_W_RECT, C_H_RECT));
			layer->setVisible(false);
			Point p = Vec2(C_SPACE_TETRIS + j*(C_W_RECT + C_SPACE_TETRIS),
				m_layer_game_1->getContentSize().height - (i + 1)*(C_H_RECT + C_SPACE_TETRIS));
			layer->setPosition(p);
			m_layer_game_1->addChild(layer);
			m_tetris[i][j] = layer;
		}
	}

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

	auto listener_touch = EventListenerTouchAllAtOnce::create();

	listener_touch->onTouchesBegan = CC_CALLBACK_2(Layer_TetrisWifi::onTouchesBegan, this);
	listener_touch->onTouchesMoved = CC_CALLBACK_2(Layer_TetrisWifi::onTouchesMoved, this);
	listener_touch->onTouchesEnded = CC_CALLBACK_2(Layer_TetrisWifi::onTouchesEnded, this);
	listener_touch->onTouchesCancelled = CC_CALLBACK_2(Layer_TetrisWifi::onTouchesCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_touch, this);
	
	CreateNextTetris();
	StartTimer();
}







void Layer_TetrisWifi::onExit()
{
	Layer::onExit();


}

void Layer_TetrisWifi::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	auto touch = static_cast<Touch*>(touches[0]);

	m_point_touchBegin = touch->getLocation();
	m_b_bottom = false;

	struct  timeval tv;
	gettimeofday(&tv, NULL);
	m_t_touchBegin = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	//log(tmp);
	//return  tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void Layer_TetrisWifi::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	auto touch = static_cast<Touch*>(touches[0]);

	auto touchLocation = touch->getLocation();

	float nMoveX = touchLocation.x - m_point_touchBegin.x;
	int nMoveY = touchLocation.y - m_point_touchBegin.y;

	if (abs(nMoveX) > abs(nMoveY))
	{
		if (nMoveX >= C_W_RECT)
		{
			event_right();
		}
		if (nMoveX < 0 && nMoveX <= -C_W_RECT)
		{
			event_left();
		}
	}
	else
	{
		if (nMoveY < 0 && (-nMoveY) >= C_W_RECT)
		{
			if ((-nMoveY) >= 3 * C_W_RECT)
			{
				m_b_bottom = true;
			}
			else
			{
				event_down();
			}
		}
	}
}

void Layer_TetrisWifi::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	auto touch = static_cast<Touch*>(touches[0]);

	auto touchLocation = touch->getLocation();
	if (touchLocation==m_point_touchBegin)
	{
		event_transform();
	}
	struct  timeval tv;
	gettimeofday(&tv, NULL);
	long tmp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	long s = tmp - m_t_touchBegin;
	if (m_b_bottom && s < 300)
	{//时间在0.3s内才能执行
		event_bottom();
	}
	m_point_touchBegin = touch->getLocation();
}

void Layer_TetrisWifi::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{

}

void Layer_TetrisWifi::setSpeed(const float t)
{
	float tt = t > 0.1 ? t : 0.1;
	unschedule(schedule_selector(Layer_TetrisWifi::Loop));
	schedule(schedule_selector(Layer_TetrisWifi::Loop), tt);
}

void Layer_TetrisWifi::Loop(float)
{
	if (l_s_p_tetris_1)
	{
		l_s_p_tetris_1->ConvertOnEnter();
		l_s_p_tetris_1->Down();
		l_s_p_tetris_1->ConvertOnExit();
	}
	DrawTetris();
	CheckCleanUp();
}

void Layer_TetrisWifi::CheckCleanUp()
{
	if (l_s_p_tetris_1 && l_s_p_tetris_1->IsBottom())
	{
		if (l_s_p_tetris_1->CleanUp())
		{
			/*m_score++;
			UpdateScore();*/
		}
		CreateNextTetris();
	}
}

void Layer_TetrisWifi::DrawTetris()
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			m_tetris[i][j]->setVisible(l_s_p_tetris_1->getBlocksPointer()[i][j].is_block);
		}
	}
}

void Layer_TetrisWifi::CreateNextTetris()
{
	Block blocks[C_ROW][C_COLUMN] = { 0 };
	if (l_s_p_tetris_1)
	{
		CopyAllBlocks(l_s_p_tetris_1->getBlocksPointer(), blocks);
		delete(l_s_p_tetris_1);
		l_s_p_tetris_1 = 0;
	}
	l_s_p_tetris_1 = Tetris::Create(TetrisKind(rand() % E_5_4));
	l_s_p_tetris_1->setBlocksPointer(blocks);
}
void Layer_TetrisWifi::StartTimer()
{
	unschedule(schedule_selector(Layer_TetrisWifi::Loop));
	schedule(schedule_selector(Layer_TetrisWifi::Loop), 1.0f);
}
void Layer_TetrisWifi::StopTimer()
{
	unschedule(schedule_selector(Layer_TetrisWifi::Loop));
}




void Layer_TetrisWifi::event_left()
{
	if (l_s_p_tetris_1)
	{
		l_s_p_tetris_1->ConvertOnEnter();
		l_s_p_tetris_1->Left();
		l_s_p_tetris_1->ConvertOnExit();
	}
	DrawTetris();
}

void Layer_TetrisWifi::event_right()
{
	if (l_s_p_tetris_1)
	{
		l_s_p_tetris_1->ConvertOnEnter();
		l_s_p_tetris_1->Right();
		l_s_p_tetris_1->ConvertOnExit();
	}
	DrawTetris();
}

void Layer_TetrisWifi::event_down()
{
	if (l_s_p_tetris_1)
	{
		l_s_p_tetris_1->ConvertOnEnter();
		l_s_p_tetris_1->Down();
		l_s_p_tetris_1->ConvertOnExit();
	}
	DrawTetris();
}

void Layer_TetrisWifi::event_bottom()
{
	for (int i = 0; i < C_ROW_BOTTOM; i++)
	{
		if (l_s_p_tetris_1)
		{
			l_s_p_tetris_1->ConvertOnEnter();
			l_s_p_tetris_1->Down();
			l_s_p_tetris_1->ConvertOnExit();
		}
		DrawTetris();
	}
}

void Layer_TetrisWifi::event_transform()
{
	if (l_s_p_tetris_1)
	{
		l_s_p_tetris_1->ConvertOnEnter();
		l_s_p_tetris_1->Transform();
		l_s_p_tetris_1->ConvertOnExit();
	}
	DrawTetris();
}

void Layer_TetrisWifi::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		event_left();

	}
	break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		event_right();
	}
	break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		event_down();
	}
	break;
	case EventKeyboard::KeyCode::KEY_KP_ENTER:
	{
		CCLOG("enter");
	}break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{//变形
		event_transform();
	}
	break;
	case EventKeyboard::KeyCode::KEY_SPACE:
	{
		event_bottom();

	}
	break;
	default:
		break;
	}
	CheckCleanUp();
}

void Layer_TetrisWifi::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}