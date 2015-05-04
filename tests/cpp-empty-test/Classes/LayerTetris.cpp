#include "LayerTetris.h"
#include "TetrisCommon.h"
#include "Tetris.h"
#include "SceneLobby.h"

static Tetris* l_s_p_tetris = 0;

Layer_Tetris::Layer_Tetris()
{
	m_score = 0;
	m_label_score = 0;
}

Layer_Tetris::~Layer_Tetris()
{
}

cocos2d::Scene* Layer_Tetris::scene()
{
	auto scene = Scene::create();

	Layer_Tetris* tetris = Layer_Tetris::create();
	scene->addChild(tetris);

	return scene;
}

bool Layer_Tetris::init()
{
	bool ret = true;

	auto win_size = Director::getInstance()->getWinSize();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto layer_bg = LayerColor::create(Color4B::BLACK);
	addChild(layer_bg);

	auto sp = Sprite::create("t_30.png");
	auto w_layer = sp->getContentSize().width*C_COLUMN;
	auto h_layer = sp->getContentSize().height*C_ROW;
	

	auto layer_bg_tetris = LayerColor::create(Color4B::ORANGE);
	layer_bg_tetris->setContentSize(Size(w_layer, h_layer));
	layer_bg_tetris->setPosition(Vec2(win_size.width / 2 - w_layer / 2, win_size.height - h_layer));
	addChild(layer_bg_tetris);

	
	TTFConfig config("fonts/aleta.ttf", 12);

	auto label = Label::createWithTTF(config, "s:");
	label->setAnchorPoint(Vec2(0, 0.5));
	label->setPosition(Vec2(5, win_size.height - 20));
	addChild(label);

	m_label_score = Label::createWithTTF(config, "0");
	m_label_score->setAnchorPoint(Vec2(0, 0.5));
	m_label_score->setPosition(Vec2(label->getPositionX()+label->getContentSize().width, label->getPositionY()));
	addChild(m_label_score);


	TTFConfig ttfConfig("fonts/aleta.ttf", 12);

	auto l_back = Label::createWithTTF(ttfConfig, "back");
	auto l_left = Label::createWithTTF(ttfConfig, "left.");
	auto l_right = Label::createWithTTF(ttfConfig, "right.");
	auto l_down = Label::createWithTTF(ttfConfig, "down.");
	auto l_bottom = Label::createWithTTF(ttfConfig, "bottom");
	auto l_transform = Label::createWithTTF(ttfConfig, "trans.");

	auto item_back = MenuItemLabel::create(l_back, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));
	auto item_left = MenuItemLabel::create(l_left, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));
	auto item_right = MenuItemLabel::create(l_right, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));
	auto item_down = MenuItemLabel::create(l_down, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));
	auto item_bottom = MenuItemLabel::create(l_bottom, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));
	auto item_transform = MenuItemLabel::create(l_transform, CC_CALLBACK_1(Layer_Tetris::menuCallback, this));

	auto x = 120;
	auto blank = 50;

	item_transform->setAnchorPoint(Vec2(0,0.5));
	item_left->setAnchorPoint(Vec2(0, 0.5));
	item_right->setAnchorPoint(Vec2(0, 0.5));
	item_down->setAnchorPoint(Vec2(0, 0.5));
	item_bottom->setAnchorPoint(Vec2(0, 0.5));
	item_back->setAnchorPoint(Vec2(0, 0.5));

	item_transform->setTag(ID_ITEM_TRANSFORM);
	item_left->setTag(ID_ITEM_LEFT);
	item_right->setTag(ID_ITEM_RIGHT);
	item_down->setTag(ID_ITEM_DOWN);
	item_bottom->setTag(ID_ITEM_BOTTOM);
	item_back->setTag(ID_ITEM_BACK);

	item_transform->setPosition(Vec2(5, item_transform->getContentSize().height*2));
	item_left->setPosition(Vec2(x, item_left->getContentSize().height));
	item_right->setPosition(Vec2(item_left->getPositionX() + item_right->getContentSize().width + blank, item_left->getPositionY()));
	
	item_bottom->setPosition(Vec2(visibleSize.width-item_bottom->getContentSize().width-5, item_transform->getPositionY()));
	item_down->setPosition(Vec2(item_bottom->getPositionX() , item_left->getPositionY()));

	item_back->setPosition(Vec2(visibleSize.width-item_back->getContentSize().width, visibleSize.height-item_back->getContentSize().height/2));

	auto menu = Menu::create(item_left, item_right, item_down, item_bottom, item_transform, item_back, nullptr);
	menu->setPosition(Vec2(0, 0));
	this->addChild(menu);



	auto pos_bg_tetris = layer_bg_tetris->getPosition();
	auto size_bg_tetris = layer_bg_tetris->getContentSize();
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			auto sp = Sprite::create("t_30.png");
			if (sp)
			{
				sp->setAnchorPoint(Vec2(0, 1));
				int w = sp->getContentSize().width;
				int h = sp->getContentSize().height;
				sp->setPosition(Vec2(pos_bg_tetris.x + j*w, pos_bg_tetris.y+size_bg_tetris.height - i*h));
				//m_tetris[i][j]->setPosition(Vec2(0+j*C_W_RECT/2, win_size.height-i*C_H_RECT/2));
				sp->setVisible(false);
				m_tetris[i][j] = sp;
				addChild(sp);
			}
		}
	}
	return ret;
}

Layer_Tetris* Layer_Tetris::create()
{
	Layer_Tetris* tetris = new Layer_Tetris();
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

void Layer_Tetris::StartTimer()
{
	unschedule(schedule_selector(Layer_Tetris::Loop));
	schedule(schedule_selector(Layer_Tetris::Loop), 1.0f);
}

void Layer_Tetris::Loop(float)
{
	l_s_p_tetris->ConvertOnEnter();
	l_s_p_tetris->Down();
	l_s_p_tetris->ConvertOnExit();
	DrawTetris();
	CheckCleanUp();
}

void Layer_Tetris::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Layer_Tetris::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Layer_Tetris::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//// 键位响应函数原型
	//void KeyboardTest::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
	//{
	//	log("Key with keycode %d pressed", keyCode);
	//}

	//void KeyboardTest::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
	//{
	//	log("Key with keycode %d released", keyCode);
	//}
	//

	/*if (!l_s_p_tetris)
	{
	l_s_p_tetris = Tetris::Create(E_1);
	}*/
	CreateNextTetris();
	StartTimer();
	
}

void Layer_Tetris::StopTimer()
{
	unschedule(schedule_selector(Layer_Tetris::Loop));
}

void Layer_Tetris::DrawTetris()
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			m_tetris[i][j]->setVisible(g_marks[i][j].is_block);
		}
	}
}

void Layer_Tetris::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
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

void Layer_Tetris::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}

void Layer_Tetris::CheckCleanUp()
{
	if (l_s_p_tetris && l_s_p_tetris->IsBottom())
	{
		if (l_s_p_tetris->CleanUp())
		{
			m_score++;
			UpdateScore();
		}
		CreateNextTetris();
	}
}

void Layer_Tetris::UpdateScore()
{
	if (m_label_score)
	{
		char tmp[64];
		snprintf(tmp, 64,"%ld", m_score >0?m_score:0);
		m_label_score->setString(tmp);
	}
}
void Layer_Tetris::menuCallback(Ref* sender)
{
	auto tag = dynamic_cast<Node*>(sender)->getTag();
	switch (tag)
	{
	case ID_ITEM_BACK:
	{
		Director::getInstance()->replaceScene(SceneLobby::scene());
	}break;
	case ID_ITEM_LEFT:
	{
		event_left();
	}break;
	case ID_ITEM_RIGHT:
	{
		event_right();
	}break;
	case ID_ITEM_DOWN:
	{
		event_down();
	}break;
	case ID_ITEM_BOTTOM:
	{
		event_bottom();
	}break;
	case ID_ITEM_TRANSFORM:
	{
		event_transform();
	}break;
	default:
		break;
	}
}

void Layer_Tetris::CreateNextTetris()
{
	if (l_s_p_tetris)
	{
		delete(l_s_p_tetris);
	}
	l_s_p_tetris = Tetris::Create(TetrisKind(rand() % E_5_4));
}

void Layer_Tetris::onExit()
{
	Layer::onExit();
}

void Layer_Tetris::menuCallback_backLobby(Ref* sender)
{
	Director::getInstance()->replaceScene(SceneLobby::scene());
}

void Layer_Tetris::event_left()
{
	l_s_p_tetris->ConvertOnEnter();
	l_s_p_tetris->Left();
	l_s_p_tetris->ConvertOnExit();
	DrawTetris();
}

void Layer_Tetris::event_right()
{
	l_s_p_tetris->ConvertOnEnter();
	l_s_p_tetris->Right();
	l_s_p_tetris->ConvertOnExit();
	DrawTetris();
}

void Layer_Tetris::event_down()
{
	l_s_p_tetris->ConvertOnEnter();
	l_s_p_tetris->Down();
	l_s_p_tetris->ConvertOnExit();
	DrawTetris();
}

void Layer_Tetris::event_bottom()
{
	for (int i = 0; i < C_ROW_BOTTOM; i++)
	{
		l_s_p_tetris->ConvertOnEnter();
		l_s_p_tetris->Down();
		l_s_p_tetris->ConvertOnExit();
		DrawTetris();
	}
}

void Layer_Tetris::event_transform()
{
	l_s_p_tetris->ConvertOnEnter();
	l_s_p_tetris->Transform();
	l_s_p_tetris->ConvertOnExit();
	DrawTetris();
}

void Layer_Tetris::event_restart()
{
	m_score = 0;
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			g_marks[i][j].is_block = false;
		}
	}

	CreateNextTetris();
	DrawTetris();
	UpdateScore();
}
