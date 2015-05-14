#include "TetrisCommon.h"






TetrisCommon::TetrisCommon()
{
}

TetrisCommon::~TetrisCommon()
{
}

void TetrisCommon::CopyAllBlocks(BlocksPointer src, BlocksPointer dest)
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			dest[i][j].copy(src[i][j]);
		}
	}
}

