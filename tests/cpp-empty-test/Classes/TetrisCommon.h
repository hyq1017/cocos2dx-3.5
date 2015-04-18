#ifndef  __TETRIS_COMMON_H__
#define __TETRIS_COMMON_H__

#pragma  once

//每个方块的长度和宽度
const int C_W_RECT = 30;
const int C_H_RECT = 30;

//行数和列数
const int C_ROW = 20;
const int C_COLUMN = 20;

const int C_ROW_BOTTOM = C_ROW;

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
	/*struct Block Copy(struct Block b)
	{

	}*/
};



#endif