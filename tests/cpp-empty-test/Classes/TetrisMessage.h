#pragma once
#include <iostream>
#include <string>
//#include "json/json.h"
#include "cocos2d.h"
#include "TetrisCommon.h"
#include "TetrisSocketCommon.h"

USING_NS_CC;
using namespace std;

class TetrisMessage
{

public:

	TetrisMessage( MSG_DATA* data);
	~TetrisMessage(void);


	MSG_DATA getData(){ return m_data; };

private:
	MSG_DATA m_data;

};

