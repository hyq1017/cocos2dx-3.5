/**
 * GameClient.cpp
 * Author: 
 *		terry
 */


//#ifdef WIN32
#ifdef WIN32
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#else
#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#endif



#include "TetrisSocket.h"
//#include "JHLog.h"


#include <exception>
#include "TetrisMessage.h"
#include "AppDelegate.h"
#include <thread>
#include "TetrisSocketCommon.h"
#include "TetrisDispatchMsg.h"


static TetrisSocket* mInstance;
#ifdef WIN32
static SOCKET sock;
#else
static int sock;
#endif // 0


static bool SHUTDOWN;
static bool s_bCreateReceiveThread;
TetrisSocket::TetrisSocket(void) {
	s_bCreateReceiveThread = false;
	position = 0;
	SHUTDOWN = false;
}

TetrisSocket::~TetrisSocket(void) {
	SHUTDOWN = true;
#ifdef WIN32
	closesocket(sock);
	sock = NULL;
#else
	sock = 0;
#endif
	
	mInstance = NULL;

	delete (char*)buf;
}

TetrisSocket* TetrisSocket::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new TetrisSocket;
		
	}
	return mInstance;
}

int TetrisSocket::close() {
#ifdef WIN32
	return closesocket(sock);
#else
	return 0;
#endif
}

// init socket and bind the server address
int TetrisSocket::start(const char* host, int port) 
{
	SHUTDOWN = false;
	

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	sockaddr_in addr; 
    WSADATA wsaData;
	int stat = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (0 != stat) {
		return stat;
	}
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sock) {
		return INVALID_SOCKET;
	}
	addr.sin_addr.S_un.S_addr = inet_addr(host);  
	addr.sin_family = AF_INET;  
	addr.sin_port = htons(port);
#else
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sock) {
		//CCLog("________________________________________________-1 == sock");
		return -1;
	}
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_port = htons(port);
#endif
	
	int ret = connect(sock, (const struct sockaddr*)&addr, sizeof(addr));
	if (ret >= 0 && !s_bCreateReceiveThread) {
		log("connet success");
		startReceiveThread();
		
	}
	else
	{
		//CCLog("________________________________________________JHSocket::start_connect<0");
	}

	return ret;
}

void* TetrisSocket::loopReceive(void* param) {
	fd_set readfds;
	struct timeval timeout = { 0, 8 };
	int selectRet = 0;
	
	while (!SHUTDOWN) 
	{
		
		MSG_DATA* msgData = mInstance->decode();
		if (msgData)
		{
			TetrisDispatchMsg::GetInstance()->addEvent(new TetrisMessage(msgData));
		}
		
		FD_ZERO(&readfds);
		FD_SET(sock, &readfds);
		#ifdef WIN32
			selectRet = select(0, &readfds, NULL, NULL, &timeout);	
		#else
			selectRet = select(sock + 1, &readfds, NULL, NULL, &timeout);
		#endif
		
		if (selectRet > 0) 
		{
			int pos = mInstance->position;
			int read = recv(sock, &(mInstance->buf[pos]), RECV_SIZE, 0);
			if (read > 0) {
				mInstance->position += read;
			}
		}
		
#ifdef WIN32

		Sleep(2);
#else
#endif
	}

	//pthread_exit(&recvtid);
	delete []&readfds;
	//delete []&recvtid;
	s_bCreateReceiveThread = false;
	return 0;
}

MSG_DATA* TetrisSocket::decode() {
	
	if (position <= MSG_HEAD_LEN)
	{
		return NULL;
	}
	int total = getTotalLength();
	int bodyLen = total-MSG_HEAD_LEN;

	if (position >= total ) {

		MSG_DATA* resp = new MSG_DATA;
		resp->len = total;
		resp->body = new char[bodyLen];
		memcpy(resp->body, buf + MSG_HEAD_LEN, bodyLen);
		//resp->body[total - 1] = 0;

		int remains = position - (total);
		if (remains > 0) {

			char* remainsBuf = new char[remains];
			memcpy(remainsBuf, &buf[total], remains);
			memset(buf, 0, BUF_SIZE);
			memcpy(buf, remainsBuf, remains);
			position = remains;

			delete[]remainsBuf;
		}

		else if (remains == 0) {
			position = 0;
		}
		return resp;
	}

	return NULL;
}

void TetrisSocket::startReceiveThread() {
	   
		auto t = std::thread(&TetrisSocket::loopReceive, this);
		t.detach();
		s_bCreateReceiveThread = true;
}

short TetrisSocket::getTotalLength() {
	//int totalLen = 0;
	//char tmp[4];
	//memcpy(tmp, mInstance->buf, 4);
	//for (int i = 0; i < 4; i++) 
	//{
	//	if (tmp[i] < 0) 
	//	{
	//		tmp[i] = tmp[i] & 0xFF;
	//	}
	//}

	//memcpy(&totalLen, tmp, 4);
	//return totalLen;
	short total = 0;
	char tmp[MSG_TOTALLEN_LEN];
	memcpy(tmp, mInstance->buf+MSG_SIGN_LEN, MSG_TOTALLEN_LEN);
	for (int i = 0; i < MSG_TOTALLEN_LEN; i++)
	 {
		 if (tmp[i] < 0)
		 {
			 tmp[i] = tmp[i] & 0xFF;
		 }
	 }

	 memcpy(&total, tmp, 4);
	return total;
}







char* TetrisSocket::convertIntToCharArray(short data)
{
	char *result = new char[4];
	memset(result, 0, 4);

	result[0] = (char)data;
	result[1] = (char)(data >> 8);
	result[2] = (char)(data >> 16);
	result[3] = (char)(data >> 24);

	return result;
}





int TetrisSocket::send_message(MSG_DATA data)
{
	int totallen = data.len+MSG_HEAD_LEN;
	char * senddata = new char(totallen);
	char *sign = new char[MSG_SIGN_LEN];
	memset(sign, 0, MSG_SIGN_LEN);

	sign[0] = (char)htons(data.sign);
	sign[1] = (char)(htons(data.sign) >> 8);
	memcpy(senddata, sign, MSG_SIGN_LEN);

	sign[0] = (char)htons(totallen);
	sign[1] = (char)(htons(totallen) >> 8);
	memcpy(senddata + MSG_HEAD_LEN - MSG_SIGN_LEN, sign, MSG_HEAD_LEN - MSG_SIGN_LEN);

	memcpy(senddata + MSG_HEAD_LEN, data.body, data.len);

	int ret = send(sock, senddata, totallen, 0);

	delete []senddata;
	senddata = 0;
	delete[]sign;
	sign = 0;

	return ret;
}
