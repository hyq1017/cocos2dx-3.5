#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "TetrisCommon.h"
#include "TetrisSocketCommon.h"

using namespace std;

#if WIN32 
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#endif




struct Request {
	char id;
	char* body;
	char* cmd;
	int totalLen;
	int bodyLen;
	int begin;
};

struct Response {
	char compress;
	char* body;
	int totalLen;
};


class TetrisSocket {
public:
	static TetrisSocket* getInstance(); 
	static void* loopReceive(void* param);

	int start(const char* host, int port);
	//int sendMessage(char* data, int len);
	void startReceiveThread();
	int close();
	int send_message(MSG_DATA data);
private:
	TetrisSocket(void);
	~TetrisSocket(void);

	

	char* convertIntToCharArray(short data);
	short getTotalLength();
	MSG_DATA* decode();
	//void stopReceiveThread();
	static const int BUF_SIZE = 1024 * 64;
	static const int RECV_SIZE = 1024;

	char buf[BUF_SIZE];
	int position;

	

};

