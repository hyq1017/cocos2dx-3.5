#include "TetrisMessage.h"

using namespace cocos2d;

//
//TetrisMessage::TetrisMessage( const string cmd, const char* body):
//	_msgCmd(cmd),
//	_msgBody(body)
//{
//	_reader.parse(_msgBody, _ro);
//}
//
//TetrisMessage::~TetrisMessage(void)
//{
//	delete _msgBody;
//	_msgBody = NULL;
//}
//
//const int TetrisMessage::getInt( const char *key ) const
//{
//	return _ro[key].asInt();
//}
//
//const int TetrisMessage::getInt( const char *key, const int i ) const
//{
//	return _ro[key][i].asInt();
//}
//
//const int TetrisMessage::getInt( const char *key, const char *ket2 ) const
//{
//	return _ro[key][ket2].asInt();
//}
//
//const int TetrisMessage::getInt( const char *key, const int x, const char *key2 ) const
//{
//	int len = _ro[key].size();
//	int temp;
//	for (int i =0; i < len; i++) {
//
//		if(i == x){
//			temp = _ro[key][i][key2].asInt();
//			break;
//		}
//	}
//	return temp;
//}
//
//const string TetrisMessage::getString( const char *key ) const
//{
//	return _ro[key].asString();
//}
//
//const string TetrisMessage::getString( const char *key, const int i ) const
//{
//	return _ro[key][i].asString();
//}
//
//const string TetrisMessage::getString( const char *key, const char *ket2 ) const
//{
//	return _ro[key][ket2].asString();
//}
//
//const string TetrisMessage::getString( const char *key, const int x, const char *key2 ) const
//{
//	int len = _ro[key].size();
//	std::string temp;
//	for (int i = 0; i < len; i++) {
//
//		if(i == x){
//			temp = _ro[key][i][key2].asString();
//			break;
//		}
//	}
//	return temp;
//}
//
//const int TetrisMessage::getArraySize( const char *key ) const
//{
//	return _ro[key].size();
//}
//
//const float TetrisMessage::getFloat( const char *key ) const
//{
//	return _ro[key].asDouble();
//}
//
//const float TetrisMessage::getFloat( const char *key, const int i ) const
//{
//	return _ro[key][i].asDouble();
//}
//
//const float TetrisMessage::getFloat( const char *key, const int x, const char *key2 ) const
//{
//	int len = _ro[key].size();
//	float temp;
//	for (int i =0; i < len; i++) {
//
//		if(i == x){
//			temp = _ro[key][i][key2].asDouble();
//			break;
//		}
//	}
//	return temp;
//}


TetrisMessage::TetrisMessage(const string cmd, const char* body)
{

}

TetrisMessage::~TetrisMessage(void)
{

}
