#pragma once
#include "cocos2d.h"
#include <iostream> 
#include <queue>  
#include <numeric> 
#include <algorithm>
#include "TetrisMessage.h"



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

	void dispatch(TetrisMessage *msg);

	static TetrisDispatchMsg* GetInstance();
	static void Destory();
private:

	//messages queue
	queue<TetrisMessage*> Queues;
	//thread mutex 
	//pthread_mutex_t _mutex;
	std::mutex _mutex;
	static TetrisDispatchMsg* m_instance;

};

