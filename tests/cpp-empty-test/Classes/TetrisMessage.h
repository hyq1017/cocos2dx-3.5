#pragma once

#include "TetrisCommon.h"
#include "TetrisSocketCommon.h"


using namespace std;



class TetrisMessage
{

public:

	TetrisMessage( MSG_DATA* data);
	~TetrisMessage(void);


	MSG_DATA* getData(){ return m_data; };

private:
	MSG_DATA *m_data;
private:
	//no copy
	TetrisMessage(const TetrisMessage&);
	TetrisMessage& operator=(const TetrisMessage&);

};

