#ifndef __LAYER_TETRIS_H__
#define __LAYER_TETRIS_H__

#include "cocos2d.h"
#include "TetrisCommon.h"

extern Block g_marks[C_ROW][C_COLUMN];


using namespace cocos2d;

class Layer_Tetris:public Layer
{
public:
	Layer_Tetris();
	~Layer_Tetris();
	static Scene* scene();
	static Layer_Tetris* create();
	bool init();
	void StartTimer();
	void StopTimer();
	void Loop(float);
	void CheckCleanUp();
	void onEnter();
	void onExit();
	void DrawTetris();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void UpdateScore();
	void setScore(const long& score){ m_score = score; }
	long getScore(){ return m_score; }
	void menuCallback(Ref* sender);
	void menuCallback_backLobby(Ref* sender);
	void CreateNextTetris();

	void event_left();
	void event_right();
	void event_down();
	void event_bottom();
	void event_transform();
	void event_restart();

private:
	Sprite* m_tetris[C_ROW][C_COLUMN];
	Label* m_label_score;
	long m_score;
private:
	//no copy
	Layer_Tetris(const Layer_Tetris&);
	Layer_Tetris& operator=(const Layer_Tetris&);
private:
	enum 
	{
		ID_ITEM_LEFT,
		ID_ITEM_RIGHT,
		ID_ITEM_DOWN,
		ID_ITEM_TRANSFORM,
		ID_ITEM_BOTTOM,
		ID_ITEM_BACK,
		//ID_LEFT,
	};
};




#endif // !__LAYER_TETRIS_H__

