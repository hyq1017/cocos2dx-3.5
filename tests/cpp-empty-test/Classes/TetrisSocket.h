#pragma once
//#include "JHMessage.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#if WIN32 
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#endif


struct send_data
{
	short sign;
	short len;
	char*body;
};

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
	int sendMessage(Request req);
	int sendMessage(send_data req);
	int sendMessage(char* data, int len);
	void startReceiveThread();
	int close();
	char* unsign_short_to_bytes(short num, bool bSmall=false);
	int send_message(send_data req);


private:
	TetrisSocket(void);
	~TetrisSocket(void);

	
	char* convertRequestToCharArray(send_data req);
	char* convertRequestToCharArray(Request req);
	//char* convertIntToCharArray(int data);
	char* convertIntToCharArray(short data);
	int getTotalLength();
	Response* decode();
	//void stopReceiveThread();
	static const int BUF_SIZE = 1024 * 64;
	static const int RECV_SIZE = 1024;

	char buf[BUF_SIZE];
	int position;

	

};

