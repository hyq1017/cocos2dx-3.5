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
//#include "JHDefine.h"
#include "tpb.h"


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
	
	while (!SHUTDOWN) {
		
		Response* resp = mInstance->decode();
		
		if (resp) {
			
			char *body = resp->body;
			C2SLogin* login = new C2SLogin();
			if (login->ParseFromString(body))
			{
				string cmd;
				log(login->logintoken().c_str());
			}
			//login->ParseFromString(body);
			/*		Json::Reader reader;
					Json::Value ro;
					string cmd;
					char userid[64] ;
					if (reader.parse(body, ro)) {

					cmd = ro["cmd"].asString();
					sprintf(userid, "userid:%d", ro["user_id"].asInt());

					string s = "cmd:"+cmd+" "+userid;
					}

					AppDelegate::getDispatcher()->addEvent(new TetrisMessage(cmd, body));*/
	
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

Response* TetrisSocket:: decode() {
	
	if (position <= 4) 
	{
		return NULL;
	}	
	int total = getTotalLength();
	
	if (position >= total + 4) {
		
		Response* resp = new Response;
		resp->totalLen = total;
		resp->compress = buf[4];
		resp->body = new char[total];
		memcpy(resp->body, buf + 5, total - 1);
		resp->body[total - 1] = 0;

		int remains = position - (total + 4);
		if (remains > 0) {
			
			char* remainsBuf = new char[remains];
			memcpy(remainsBuf, &buf[total + 4], remains);
			memset(buf, 0, BUF_SIZE);
			memcpy(buf, remainsBuf, remains);
			position = remains;

			delete []remainsBuf;
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

int TetrisSocket::getTotalLength() {
	int totalLen = 0;
	char tmp[4];
	memcpy(tmp, mInstance->buf, 4);
	for (int i = 0; i < 4; i++) 
	{
		if (tmp[i] < 0) 
		{
			tmp[i] = tmp[i] & 0xFF;
		}
	}

	memcpy(&totalLen, tmp, 4);
	return totalLen;
}

int TetrisSocket::sendMessage(Request req) {
	char* data = convertRequestToCharArray(req);
	int ret = send(sock, data, req.totalLen + 4, 0);
	delete []data;
	return ret;
}

int TetrisSocket::sendMessage(char* data, int len)
{
	
	int ret = send(sock, data, len, 0);
	delete[]data;
	return ret;
}

int TetrisSocket::sendMessage(send_data req)
{
	char* data = convertRequestToCharArray(req);
	int ret = send(sock, data, req.len + 4, 0);
	log("buf:%s", data);
	delete[]data;
	return ret;
}

char* TetrisSocket::convertRequestToCharArray(Request req) {
	char *data = new char[req.totalLen + 4];
	char* totalLen = convertIntToCharArray(req.totalLen);

#ifdef WIN32
	data[0] = totalLen[0];
	data[1] = totalLen[1];
	data[2] = totalLen[2];
	data[3] = totalLen[3];
	//data[4] = req.id;
	//char* bodyLen = convertIntToCharArray(req.bodyLen);
	////_itoa_s(req.bodyLen, bodyLen, 4, 10);
	//data[5] = bodyLen[0];
	//data[6] = bodyLen[1];
	//data[7] = bodyLen[2];
	//data[8] = bodyLen[3];
#else
	memcpy(data, totalLen, 4);
	data[4] = req.id;
	char* bodyLen = convertIntToCharArray(req.bodyLen);
	memcpy(data + 5, bodyLen, 4);
#endif
	for (int i = 0; i < req.totalLen; i++) {
		data[i + 4] = req.body[i];
	}
	
	/*for (int i = 0; i < req.bodyLen; i++) {
		data[i+9] = req.body[i];
		}

		for (int i = 0; i < strlen(req.cmd); i++) {
		data[i + 9 + req.bodyLen] = req.cmd[i];
		}	*/
	return data;
}

char* TetrisSocket::convertRequestToCharArray(send_data req)
{
	char *data = new char[req.len + 4];
	char* sign = convertIntToCharArray(req.sign);
#ifdef WIN32
	data[0] = sign[0];
	data[1] = sign[1];
	//data[2] = sign[2];
	//data[3] = sign[3];

	delete sign;
	sign = 0;

	char* totalLen = convertIntToCharArray(req.len);
	data[2] = totalLen[0];
	data[3] = totalLen[1];
	//data[6] = totalLen[2];
	//data[7] = totalLen[3];
	delete totalLen;
	totalLen = 0;
	//data[4] = req.id;
	//char* bodyLen = convertIntToCharArray(req.bodyLen);
	////_itoa_s(req.bodyLen, bodyLen, 4, 10);
	//data[5] = bodyLen[0];
	//data[6] = bodyLen[1];
	//data[7] = bodyLen[2];
	//data[8] = bodyLen[3];
#else
	memcpy(data, totalLen, 4);
	data[4] = req.id;
	char* bodyLen = convertIntToCharArray(req.bodyLen);
	memcpy(data + 5, bodyLen, 4);
#endif
	for (int i = 0; i < req.len; i++) {
		data[i + 4] = req.body[i];
		}
	return data;
}

//char* TetrisSocket::convertIntToCharArray(int data) {
//
//	char *result = new char[4];
//	memset(result, 0, 4);
//
//	result[0] = (char)data;
//	result[1] = (char)(data >> 8);
//	result[2] = (char)(data >> 16);
//	result[3] = (char)(data >> 24);
//
//	return result;
//}

char* TetrisSocket::convertIntToCharArray(short data)
{
	char *result = new char[2];
	memset(result, 0, 2);

	result[0] = (char)data;
	result[1] = (char)(data >> 8);

	return result;
}





char* TetrisSocket::unsign_short_to_bytes(short num, bool bSmall)
{
	//char res[64];
	//vector<char> res;
	/*res.reserve(10);
	res.push_back(0);
	res.push_back(0);*/
	char* res = new char(2);
	short n = 1;
	for (short k = n; k >= 0; k--)
	{
		short mul = 2 ^ (8 * k - 0);
		res[k] = num / mul;//(short)floor((float)num / (float)mul);
	}
	if (!bSmall)
	{
		char t[2];
		for (short k = 0; k < n; k++)
		{
			t[k] = res[n-k+0];
		}
		res = t;
	}
	return res;
}

int TetrisSocket::send_message(send_data req)
{
	send_data senddata;
	senddata.sign = htons(req.sign);
	senddata.len = htons(req.len);
	/*senddata.body = new char(strlen(req.body));
	memcpy(senddata.body, req.body, strlen(req.body));*/
	senddata.body = req.body;

	int ret = send(sock, (char *)&senddata, req.len, 0);

	return ret;
}