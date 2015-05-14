#include "TetrisDispatchMsg.h"
#include "S2C_pb.h"
#include "C2S_pb.h"


using namespace tetris_protocol;


TetrisDispatchMsg* TetrisDispatchMsg::m_instance = 0;

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


void TetrisDispatchMsg::Destory()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = 0;
	}
}

TetrisDispatchMsg* TetrisDispatchMsg::GetInstance()
{
	if (m_instance)
	{
		m_instance = new TetrisDispatchMsg();
	}
	return m_instance;
};


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
	{//消息分发部分 掉Lua消息分发脚本
		TetrisMessage *msg = Queues.front();
		dispatch(msg);
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

void TetrisDispatchMsg::dispatch(TetrisMessage *msg)
{
	tetris_protocol::S2CMsg* s2cMsg = new tetris_protocol::S2CMsg();//S2CMsg::ParseFromString(s);
	if (s2cMsg)
	{
		s2cMsg->ParseFromString(msg->getData().body);
		switch (s2cMsg->msgid())
		{
		case C2S_Login:
		{
			log("c2slogin recieve success!!");
		}break;
		default:
			break;
		}
	}
	
}


