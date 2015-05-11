#include "TetrisDispatchMsg.h"


TetrisDispatchMsg::TetrisDispatchMsg(void)
{
	//pthread_mutex_init(&_mutex, NULL);
    this->onEnter();
	this->onEnterTransitionDidFinish();
	this->scheduleUpdate();
}

TetrisDispatchMsg::~TetrisDispatchMsg(void)
{
	//pthread_mutex_destroy(&_mutex);
	this->unscheduleUpdate();
}

void TetrisDispatchMsg::addEvent(TetrisMessage *msg)
{
	//pthread_mutex_lock(&_mutex);
	_mutex.lock();
	if(msg){
		Queues.push(msg);
	}
	_mutex.unlock();
	//pthread_mutex_unlock(&_mutex);
}

void TetrisDispatchMsg::update( float fDelta )
{
	//pthread_mutex_lock(&_mutex);
	_mutex.lock();
	//解析发送过来的消息
	if (Queues.size()>0) 
	{
		TetrisMessage *msg = Queues.front();
		//消息分发部分 掉Lua消息分发脚本
		//JHCallLua::getInstance()->NotifyLua(msg->_msgBody);
		//pop/delete/null
		Queues.pop();
		delete msg;
		msg = NULL;
	}
	_mutex.unlock();
	//pthread_mutex_unlock(&_mutex);
}

void TetrisDispatchMsg::removeAll()
{
	int k = Queues.size();
	for (int i = 0;i<k;i++)
	{
		Queues.pop();
	}
}


