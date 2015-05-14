#include "TetrisMessage.h"

using namespace cocos2d;





TetrisMessage::TetrisMessage(MSG_DATA* data)
{
	m_data.copy(*data);
}

TetrisMessage::~TetrisMessage(void)
{

}
