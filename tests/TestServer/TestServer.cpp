// TestServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <Winsock2.h>
#include <stdio.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsd;
	SOCKET server;                                            //服务器socket
	SOCKADDR_IN addrSrv;
	char sendBuf[1024];
	char recvBuf[1024];
	SOCKADDR_IN addrClient;
	SOCKET client;                                            //连接的客户端socket
	int len;
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		printf("start up failed!\n");
		return -1;
	}
	server = socket(AF_INET, SOCK_STREAM, 0);                    //创建socket
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);            //设置地址
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);                            //设置端口号
	bind(server, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));        //绑定
	listen(server, 5);                                        //设置最多连接数
	len = sizeof(SOCKADDR);
	while (1)
	{
		client = accept(server, (SOCKADDR*)&addrClient, &len);    //接收客户端连接
		//char buf[1024];
		//_snprintf(buf, 1024,"%s", );
		//sprintf(sendBuf, "Welcome %s ",
		//	inet_ntoa(addrClient.sin_addr));
		send(client, sendBuf, strlen(sendBuf) + 1, 0);            //发送信息客户端
		recv(client, recvBuf, 100, 0);                            //接收客户端数据
		printf("%s\n", recvBuf);
		string s = recvBuf;
		closesocket(client);
	}
	closesocket(client);                                    //关闭连接
	WSACleanup();
	return 0;
}

