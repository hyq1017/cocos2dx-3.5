#pragma once
#include <iostream>
#include <string>
//#include "json/json.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class TetrisMessage
{

public:

	TetrisMessage(const string cmd, const char* body);
	~TetrisMessage(void);

	//get arrry size 
	//inline const int getArraySize(const char *key) const;

	////get value int 
	//inline const int getInt(const char *key) const;
	//inline const int getInt(const char *key, const int i) const;
	//inline const int getInt(const char *key, const char *ket2) const;
	//inline const int getInt(const char *key, const int x, const char *key2) const;
	//
	////get value string 
	//inline const string getString(const char *key) const;
	//inline const string getString(const char *key, const int i) const;
	//inline const string getString(const char *key, const char *ket2) const;
	//inline const string getString(const char *key, const int x, const char *key2) const;
	//
	////get value float
	//inline const float getFloat(const char *key) const;
	//inline const float getFloat(const char *key, const int i) const;
	//inline const float getFloat(const char *key, const int x, const char *key2) const;


public:

	//messages cmd 
	const string _msgCmd;
	//messages body 
	const char* _msgBody;
	//json reader obj
	//Json::Reader _reader;
	////josn value obj
	//Json::Value _ro;

};

