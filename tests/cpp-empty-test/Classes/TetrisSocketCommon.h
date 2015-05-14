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
	void copy(MSG_DATA data)
	{
		sign = data.sign;
		len = data.len;
		std::memcpy(body, data.body, len - MSG_HEAD_LEN);
	}
};
