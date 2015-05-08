#ifndef  __TETRIS_COMMON_H__
#define __TETRIS_COMMON_H__
#include "cocos2d.h"
using namespace cocos2d;

#pragma  once

//每个方块的长度和宽度
const int C_W_RECT = 12;
const int C_H_RECT = 12;

const int C_W_RECT_2 = 5;
const int C_H_RECT_2 = 5;



//行数和列数
const int C_ROW = 20;
const int C_COLUMN = 20;

const int C_ROW_BOTTOM = C_ROW;

const int C_SPACE = 1;
const int C_SPACE_TETRIS = 1;//俄罗斯方块之间的距离

//橙色
const Color4B myColor4BOrange = Color4B(255, 127, 0, 255);

//青色
const Color4B myColor4BCyan = Color4B(0, 255, 255, 255);
//橄榄
const Color4B myColor4BOlive = Color4B(128, 128, 0, 255);
//银白
const Color4B myColor4BSilver = Color4B(192, 192, 192, 255);

//深紫罗兰的蓝色
const Color4B myColor4BBlueViolet = Color4B(138, 43, 226, 255);
//深天蓝
const Color4B myColor4BDeepSkyBlue = Color4B(0, 191, 255, 255);

//
const Color4B myColor4BDeepAqua = Color4B(60, 179, 113, 255);

//
const Color4B myColor4BYellow= Color4B(255, 255, 0, 255);

enum TetrisKind
{
	E_1,//田
	E_2_1,//竖直线
	E_2_2,//横直线
	E_3_1,//L形态1
	E_3_2,//L形态2
	E_3_3,//L形态3
	E_3_4,//L形态4
	E_4_1,//闪电形态1
	E_4_2,//闪电形态2
	E_5_1,//土形态1
	E_5_2,//土形态2
	E_5_3,//土形态3
	E_5_4,//土形态4
};

struct Block
{
	bool is_block;//当前格子是否有方块
	int row;
	int column;
	void copy(const struct Block& b)
	{
		is_block = b.is_block;
		row = b.row;
		column = b.column;
	}
};

typedef Block(*BlocksPointer)[C_COLUMN];

void CopyAllBlocks(BlocksPointer src, BlocksPointer dest);
//{
//	for (int i = 0; i < C_ROW; i++)
//	{
//		for (int j = 0; j < C_COLUMN; j++)
//		{
//			dest[i][j].copy(src[i][j]);
//		}
//	}
//}

#endif