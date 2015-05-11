#pragma once
#include "cocos2d.h"
#include <iostream> 
#include <queue>  
#include <numeric> 
#include <algorithm>
//#include "pthread/pthread.h"
#include "TetrisMessage.h"
//#include "TetrisCallLua.h"
//#include "TetrisDefine.h"
//#include "JHLuaCallC.h"


class TetrisDispatchMsg : public cocos2d::CCNode
{
public:

	TetrisDispatchMsg(void);
	~TetrisDispatchMsg(void);

	//thread update function
	virtual void update(float fDelta);
	//add messages 
    void addEvent(TetrisMessage *msg);
	// remove all messages
	void removeAll();

private:

	//messages queue
	queue<TetrisMessage*> Queues;
	//thread mutex 
	//pthread_mutex_t _mutex;
	std::mutex _mutex;

};

