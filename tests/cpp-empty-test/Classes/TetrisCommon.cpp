#include "TetrisCommon.h"
//Block g_marks[C_ROW][C_COLUMN] = { 0 };


//Block g_marks_wifi_1[C_ROW][C_COLUMN] = { 0 };
void CopyAllBlocks(BlocksPointer src, BlocksPointer dest)
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			dest[i][j].copy(src[i][j]);
		}
	}
}