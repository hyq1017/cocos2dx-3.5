#pragma  once

#include <cstring>

enum
{
	MSG_TAG = 127,
	MSG_HEAD_LEN = 4,
	MSG_SIGN_LEN = 2,
	MSG_TOTALLEN_LEN = 2,
};

struct MSG_DATA
{
	short sign;
	short len;
	char*body;
	MSG_DATA()
	{
		sign = MSG_TAG;
		len = 0;
		body = 0;
	}
};
