#ifndef __LAYER_TETRIS_WIFI_H__
#define __LAYER_TETRIS_WIFI_H__

#include "cocos2d.h"
#include "TetrisCommon.h"

//extern Block g_marks[C_ROW][C_COLUMN];


using namespace cocos2d;

class Layer_TetrisWifi:public Layer
{
public:
	Layer_TetrisWifi();
	~Layer_TetrisWifi();
	static Scene* scene();
	static Layer_TetrisWifi* create();
	bool init();
	void onEnter();
	void onExit();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

	void StartTimer();
	void StopTimer();

	void setSpeed(const float t);
	void Loop(float);
	void CheckCleanUp();
	void DrawTetris();
	void CreateNextTetris();

	void event_left();
	void event_right();
	void event_down();
	void event_bottom();
	void event_transform();
	void event_restart();
private:
	bool m_b_bottom;
	long m_t_touchBegin;
	Point m_point_touchBegin;
	//Point m_point_touchEnd;
	LayerColor* m_layer_game_1;
	LayerColor* m_layer_game_2;
	LayerColor* m_layer_game_3;
	LayerColor* m_layer_gameTitle_2;
	LayerColor* m_layer_gameTitle_3;
	LayerColor* m_layer_prop;
	LayerColor* m_layer_myInfo;
	LayerColor* m_layer_myTip;
	LayerColor* m_tetris[C_ROW][C_COLUMN];
private:
	//no copy
	Layer_TetrisWifi(const Layer_TetrisWifi&);
	Layer_TetrisWifi& operator=(const Layer_TetrisWifi&);
private:

};




#endif // !__LAYER_TETRIS_WIFI_H__

