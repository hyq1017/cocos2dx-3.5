#ifndef __LAYER_TETRIS_WIFI_H__
#define __LAYER_TETRIS_WIFI_H__

#include "cocos2d.h"
#include "TetrisCommon.h"

extern Block g_marks[C_ROW][C_COLUMN];


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


private:

private:
	//no copy
	Layer_TetrisWifi(const Layer_TetrisWifi&);
	Layer_TetrisWifi& operator=(const Layer_TetrisWifi&);
private:

};




#endif // !__LAYER_TETRIS_WIFI_H__

