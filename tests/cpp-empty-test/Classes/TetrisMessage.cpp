#include "TetrisMessage.h"





TetrisMessage::TetrisMessage(MSG_DATA* data):
m_data(0)
{
	if (data->sign == MSG_TAG)
	{
		m_data = new MSG_DATA();
		m_data->len = data->len;
		m_data->sign = data->sign;
		m_data->body = new char[data->len - MSG_HEAD_LEN];
		memset(m_data->body, 0, data->len - MSG_HEAD_LEN);
		memcpy(m_data->body, data->body, data->len - MSG_HEAD_LEN);
	}
	
}

TetrisMessage::~TetrisMessage(void)
{
	if (m_data)
	{
		if (m_data->body)
		{
			delete []m_data->body;
			m_data->body = 0;
		}
		delete m_data;
		m_data = 0;
	}
	
}
