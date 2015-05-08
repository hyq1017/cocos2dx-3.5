#include "Tetris.h"
#include "cocos2d.h"

using namespace cocos2d;


/*
所有方块都是4个格子
最下面的格子row为-1，上面的--
*/
Tetris* Tetris::Create(TetrisKind kind)
{
	Tetris* t = new Tetris();
	t->m_kind = kind;
	t->m_block.column = C_COLUMN / 2;

	

	switch (kind)
	{
	case E_1://田
	{//中心点为左上角第一个格子
		t->m_block.row = -2;
	}break;
	case E_2_1://竖直线
	{//中心点为第二个格子
		t->m_block.row = -3;
	}break;
	case E_2_2://横直线
	{//中心点为第二个格子
		t->m_block.row = -1;
	}break;
	case E_3_1://L形态1
	{
		t->m_block.row = -1;
	}break;
	case E_3_2://L形态2
	{
		t->m_block.row = -2;
	}break;
	case E_3_3:
	{
		t->m_block.row = -3;
	}break;
	case E_3_4:
	{
		t->m_block.row = -1;
	}break;
	case E_4_1:
	{
		t->m_block.row = -2;
	}break;
	case E_4_2:
	{
		t->m_block.row = -1;
	}break;
	case E_5_1:
	{
		t->m_block.row = -1;
	}break;
	case E_5_2:
	{
		t->m_block.row = -2;
	}break;
	case E_5_3:
	{
		t->m_block.row = -2;
	}break;
	case E_5_4:
	{
		t->m_block.row = -2;
	}break;
	default:
		break;
	}
	return t;
}

Tetris::Tetris():
m_speed(1)
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			m_marks[i][j].is_block = false;
		}
	}
}

Tetris::~Tetris()
{

}
void Tetris::Left()
{
	if (LeftOk())
	{
		m_block.column -= 1;
	}
	else
	{
	}
}

void Tetris::Right()
{
	if (RightOk())
	{
		m_block.column += 1;
	}
	else
	{
	}
}


void Tetris::Down()
{
	if (DownOk())
	{
		m_block.row += 1;
	}
	else
	{
	}
}

bool Tetris::DownOk()
{
	int ret = false;

	m_block.row += 1;
	ret = Ok() ? true: false;
	m_block.row -= 1;

	return ret;
}
bool Tetris::LeftOk()
{
	int ret = false;

	m_block.column -= 1;
	ret = Ok() ? true : false;
	m_block.column += 1;

	return ret;
}

bool Tetris::RightOk()
{
	int ret = false;

	m_block.column += 1;
	ret = Ok() ? true : false;
	m_block.column -= 1;

	return ret;
}
bool Tetris::Ok()
{
	
	if (!EdgeOk())
	{
		return false;
	}

	bool ret = true;;
	switch (m_kind)
	{
	case E_1://田
	{ 
		if ((m_block.row + 1>=0) && 
								(m_marks[m_block.row + 1][m_block.column].is_block 
								|| m_marks[m_block.row + 1][m_block.column+1].is_block))
		{
			CCLOG("E1:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}
		break;
	case E_2_1://竖直线
	{
		if ((m_block.row + 2 >= 0) &&
									(  m_marks[m_block.row + 2][m_block.column].is_block //底部ok
									// ||m_marks[m_block.row ][m_block.column + 1].is_block//右边ok
									 //|| m_marks[m_block.row + 2][m_block.column - 1].is_block//左边ok
									 ))
		{
			CCLOG("E1:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}
		break;
	case E_2_2:
		if ((m_block.row  >= 0)
								&&(m_marks[m_block.row][m_block.column].is_block 
									|| m_marks[m_block.row][m_block.column-1].is_block
									|| m_marks[m_block.row][m_block.column+1].is_block
									|| m_marks[m_block.row][m_block.column + 2].is_block))
		{
			CCLOG("E1:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
		break;
	case E_3_1:
	{
		if ((m_block.row >= 0)
			&& (m_marks[m_block.row][m_block.column].is_block
			//|| m_marks[m_block.row][m_block.column - 1].is_block
			|| m_marks[m_block.row][m_block.column + 1].is_block))
			//|| m_marks[m_block.row][m_block.column + 2].is_block))
		{
			CCLOG("E4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_3_2:
	{
		if ((m_block.row >= 0)
			&& (m_marks[m_block.row+1][m_block.column].is_block
			|| m_marks[m_block.row][m_block.column + 1].is_block
			|| m_marks[m_block.row][m_block.column + 2].is_block))
		{
			CCLOG("E4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_3_3:
	{
		if ((m_block.row >= 0)
			&& (m_marks[m_block.row ][m_block.column-1].is_block
			|| m_marks[m_block.row+2][m_block.column ].is_block))
		{
			CCLOG("E4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_3_4:
	{
		if ((m_block.row >= 0)
			&& (m_marks[m_block.row][m_block.column - 1].is_block
			|| m_marks[m_block.row][m_block.column -2].is_block
			|| m_marks[m_block.row][m_block.column].is_block))
		{
			CCLOG("E4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_4_1:
	{
		if ((m_block.row-1 >= 0)
			&& (m_marks[m_block.row][m_block.column].is_block
			|| m_marks[m_block.row][m_block.column +1].is_block
			|| m_marks[m_block.row + 1][m_block.column + 1].is_block
			|| m_marks[m_block.row -1][m_block.column ].is_block))
		{
			CCLOG("E4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_4_2:
	{
		if ((m_block.row-1  >= 0)
			&& (m_marks[m_block.row][m_block.column].is_block
			|| m_marks[m_block.row][m_block.column - 1].is_block
			|| m_marks[m_block.row - 1][m_block.column + 1].is_block
			|| m_marks[m_block.row - 1][m_block.column].is_block))
		{
			CCLOG("E_4_2:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_5_1:
	{
		if ((m_block.row  >= 0)
			&& (m_marks[m_block.row][m_block.column].is_block
			|| m_marks[m_block.row][m_block.column - 1].is_block
			|| m_marks[m_block.row][m_block.column + 1].is_block))
		{
			CCLOG("E_5_1:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
	}break;
	case E_5_2:
	{
		
		if ((m_block.row >= 0)
			&& m_marks[m_block.row][m_block.column + 1].is_block)
		{
			CCLOG("E_5_2:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
		if (m_block.row + 1 >= 0 && (m_marks[m_block.row + 1][m_block.column].is_block))
		{
			CCLOG("E_5_2:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}

	}break;
	case E_5_3:
	{

		if ((m_block.row >= 0)
			&& (m_marks[m_block.row][m_block.column + 1].is_block
				|| m_marks[m_block.row][m_block.column -1].is_block))
		{
			CCLOG("E_5_3:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
		if (m_block.row + 1 >= 0 && (m_marks[m_block.row + 1][m_block.column].is_block))
		{
			CCLOG("E_5_3:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}

	}break;
	case E_5_4:
	{

		if ((m_block.row >= 0)
			&& (m_marks[m_block.row][m_block.column ].is_block
			|| m_marks[m_block.row][m_block.column - 1].is_block))
		{
			CCLOG("E_5_4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}
		if (m_block.row + 1 >= 0 && (m_marks[m_block.row + 1][m_block.column].is_block))
		{
			CCLOG("E_5_4:no ok, row:%d column:%d", m_block.row, m_block.column);
			ret = false;
		}

	}break;
	default:
		break;
	}
	return ret;
}

void Tetris::Convert()
{
	switch (m_kind)
	{
	case E_1:
	{
		if (m_block.row >=0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column + 1] = m_block;
		}
		if (m_block.row + 1 >=0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
			m_marks[m_block.row + 1][m_block.column + 1] = m_block;
		}
	}
	break;
	case E_2_1:
	{
		if (m_block.row-1 >= 0)
		{
			m_marks[m_block.row-1][m_block.column] = m_block;
		}
		if (m_block.row  >= 0)
		{
			m_marks[m_block.row ][m_block.column] = m_block;
		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
		if (m_block.row + 2 >= 0)
		{
			m_marks[m_block.row + 2][m_block.column] = m_block;
		}
	}
		break;
	case E_2_2:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column-1] = m_block;
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column+1] = m_block;
			m_marks[m_block.row][m_block.column+2] = m_block;
		}
	}
		break;
	case E_3_1://竖l
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column+1] = m_block;
		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
		if (m_block.row - 2 >= 0)
		{
			m_marks[m_block.row - 2][m_block.column] = m_block;
		}
	}break;
	case E_3_2:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column + 1] = m_block;
			m_marks[m_block.row][m_block.column + 2] = m_block;
		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
	}break;
	case E_3_3:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column - 1] = m_block;
		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
		if (m_block.row + 2 >= 0)
		{
			m_marks[m_block.row + 2][m_block.column] = m_block;
		}
	}break;
	case E_3_4:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column - 1] = m_block;
			m_marks[m_block.row][m_block.column - 2] = m_block;
		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
	}break;
	case E_4_1:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column +1] = m_block;
			
		}
		if (m_block.row + 1)
		{
			m_marks[m_block.row + 1][m_block.column + 1] = m_block;
		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
	}break;
	case E_4_2:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column - 1] = m_block;

		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
			m_marks[m_block.row - 1][m_block.column+1] = m_block;
		}
	}break;
	case E_5_1:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column - 1] = m_block;
			m_marks[m_block.row][m_block.column + 1] = m_block;

		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
	}break;
	case E_5_2:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column + 1] = m_block;

		}
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
	}break;
	case E_5_3:
	{
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column-1] = m_block;
			m_marks[m_block.row][m_block.column] = m_block;
			m_marks[m_block.row][m_block.column + 1] = m_block;

		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
	}break;
	case E_5_4:
	{
		if (m_block.row - 1 >= 0)
		{
			m_marks[m_block.row - 1][m_block.column] = m_block;
		}
		if (m_block.row >= 0)
		{
			m_marks[m_block.row][m_block.column - 1] = m_block;
			m_marks[m_block.row][m_block.column] = m_block;

		}
		if (m_block.row + 1 >= 0)
		{
			m_marks[m_block.row + 1][m_block.column] = m_block;
		}
	}break;
	default:
		break;
	}
}

void Tetris::ConvertOnEnter()
{
	m_block.is_block = false;
	Convert();
}

void Tetris::ConvertOnExit()
{
	m_block.is_block = true;
	Convert();
}

bool Tetris::EdgeOk()
{
	bool ret = true;
	switch (m_kind)
	{
	case E_1:
		if (m_block.column + 1 >= C_COLUMN || m_block.column < 0|| m_block.row + 1 >= C_ROW)
		{
			ret = false;
		}
		break;
	case E_2_1:
		if (m_block.column >= C_COLUMN || m_block.column < 0 || m_block.row + 2 >= C_ROW)
		{
			ret = false;
		}
		break;
	case E_2_2:
		if (m_block.column +2 >= C_COLUMN || m_block.column-1 < 0 || m_block.row  >= C_ROW)
		{
			ret = false;
		}
		break;
	case E_3_1:
	{
		if (m_block.column + 1 >= C_COLUMN || m_block.column < 0 || m_block.row >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_3_2:
	{
		if (m_block.column + 2 >= C_COLUMN || m_block.column < 0 || m_block.row+1 >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_3_3:
	{
		if (m_block.column  >= C_COLUMN || m_block.column-1 < 0 || m_block.row + 2 >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_3_4:
	{
		if (m_block.column >= C_COLUMN || m_block.column - 2 < 0 || m_block.row >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_4_1:
	{
		if (m_block.column+1 >= C_COLUMN || m_block.column  < 0 || m_block.row+1 >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_4_2:
	{
		if (m_block.column + 1 >= C_COLUMN || m_block.column -1 < 0 || m_block.row  >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_5_1:
	{
		if (m_block.column + 1 >= C_COLUMN || m_block.column - 1 < 0 || m_block.row >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_5_2:
	{
		if (m_block.column + 1 >= C_COLUMN || m_block.column  < 0 || m_block.row+1 >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_5_3:
	{
		if (m_block.column + 1 >= C_COLUMN || m_block.column-1 < 0 || m_block.row + 1 >= C_ROW)
		{
			ret = false;
		}
	}break;
	case E_5_4:
	{
		if (m_block.column  >= C_COLUMN || m_block.column-1 < 0 || m_block.row + 1 >= C_ROW)
		{
			ret = false;
		}
	}break;
	default:
		break;
	}

	return ret;
}

void Tetris::Transform()
{
	
	switch (m_kind)
	{
	case E_1:
		break;
	case E_2_1:
	{
		m_kind = E_2_2;

		if (Ok())
		{
			//return;
		}
		else
		{
			m_kind = E_2_1;
			//return;
		}
	}
		break;
	case E_2_2:
	{
		m_kind = E_2_1;
		//m_block.row

		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_2_2;
			return;
		}
	}
		break;
	case E_3_1:
	{
		int tmp = m_kind + 1;
		if (tmp > E_3_4 || tmp == E_3_1)
		{
			tmp = E_3_2;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_3_1;
			return;
		}
	}break;
	case E_3_2:
	{
		int tmp = m_kind + 1;
		if (tmp > E_3_4 || tmp == E_3_2)
		{
			tmp = E_3_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_3_2;
			return;
		}
	}break;
	case E_3_3:
	{
		int tmp = m_kind + 1;
		if (tmp > E_3_4 || tmp == E_3_3)
		{
			tmp = E_3_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_3_3;
			return;
		}
	}break;
	case E_3_4:
	{
		int tmp = m_kind + 1;
		if (tmp > E_3_3)
		{
			tmp = E_3_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_3_4;
			return;
		}
	}break;
	case E_4_1:
	{
		m_kind = E_4_2;
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_4_1;
			return;
		}
	}break;
	case E_4_2:
	{
		m_kind = E_4_1;
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_4_2;
			return;
		}
	}break;
	case E_5_1:
	{
		int tmp = m_kind + 1;
		if (tmp > E_5_4 || tmp == E_5_1)
		{
			tmp = E_5_2;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_5_1;
			return;
		}
	}break;
	case E_5_2:
	{
		int tmp = m_kind + 1;
		if (tmp > E_5_4 || tmp == E_5_2)
		{
			tmp = E_5_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_5_2;
			return;
		}
	}break;
	case E_5_3:
	{
		int tmp = m_kind + 1;
		if (tmp > E_5_4 || tmp == E_5_3)
		{
			tmp = E_5_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_5_3;
			return;
		}
	}break;
	case E_5_4:
	{
		int tmp = m_kind + 1;
		if (tmp > E_5_3)
		{
			tmp = E_5_1;
		}
		m_kind = TetrisKind(tmp);
		if (Ok())
		{
			return;
		}
		else
		{
			m_kind = E_5_4;
			return;
		}
	}break;
	default:
		break;
	}
	ConvertOnExit();
}

bool Tetris::IsBottom()
{
	bool ret = false;
	switch (m_kind)
	{
	case E_1://田
	{
		if (m_block.row + 2 >= C_ROW_BOTTOM
			|| m_marks[m_block.row + 2][m_block.column].is_block
			|| m_marks[m_block.row + 2][m_block.column+1].is_block)
		{
			ret = true;
		}
	}
		break;
	case E_2_1://竖直线
	{
		if (m_block.row + 3 >= C_ROW_BOTTOM || m_marks[m_block.row + 3][m_block.column].is_block)
		{
			ret = true;
		}
	}
		break;
	case E_2_2://横直线
	{
		if (m_block.row + 1 >= C_ROW_BOTTOM
			|| m_marks[m_block.row + 1][m_block.column-1].is_block
			|| m_marks[m_block.row + 1][m_block.column].is_block
			|| m_marks[m_block.row + 1][m_block.column+1].is_block
			|| m_marks[m_block.row + 1][m_block.column+2].is_block)
		{
			ret = true;
		}
	}
		break;
	case E_3_1://竖L
	{
		if (m_block.row + 1 >= C_ROW_BOTTOM
			//|| m_marks[m_block.row + 1][m_block.column - 1].is_block
			|| m_marks[m_block.row + 1][m_block.column].is_block
			|| m_marks[m_block.row + 1][m_block.column + 1].is_block)
			//|| m_marks[m_block.row + 1][m_block.column + 2].is_block)
		{
			ret = true;
		}
	}break;
	case E_3_2://
	{
		if (m_block.row + 2 >= C_ROW_BOTTOM
			|| m_marks[m_block.row + 2][m_block.column].is_block
			|| m_marks[m_block.row+1][m_block.column+1].is_block
			|| m_marks[m_block.row+1][m_block.column + 2].is_block)
			//|| m_marks[m_block.row + 1][m_block.column + 2].is_block)
		{
			ret = true;
		}
	}break;
	case E_3_3://
	{
		if (m_block.row + 3 >= C_ROW_BOTTOM
			|| m_marks[m_block.row + 3][m_block.column].is_block
			//|| m_marks[m_block.row ][m_block.column -1].is_block
			|| m_marks[m_block.row +1][m_block.column -1].is_block)
			//|| m_marks[m_block.row + 1][m_block.column + 2].is_block)
		{
			ret = true;
		}
	}break;
	case E_3_4://
	{
		if (m_block.row +1 >= C_ROW_BOTTOM
			|| m_marks[m_block.row + 1][m_block.column].is_block
			|| m_marks[m_block.row +1][m_block.column -1].is_block
			|| m_marks[m_block.row + 1][m_block.column - 2].is_block)
			//|| m_marks[m_block.row + 1][m_block.column + 2].is_block)
		{
			ret = true;
		}
	}break;
	case E_4_1://
	{
		if (m_block.row +2 >= C_ROW_BOTTOM
			|| m_marks[m_block.row +1][m_block.column].is_block
			|| m_marks[m_block.row + 2][m_block.column +1].is_block)
		{
			ret = true;
		}
	}break;
	case E_4_2://
	{
		if (m_block.row + 1 >= C_ROW_BOTTOM
			|| m_marks[m_block.row ][m_block.column+1].is_block
			|| m_marks[m_block.row + 1][m_block.column].is_block
			|| m_marks[m_block.row + 1][m_block.column -1].is_block)
		{
			ret = true;
		}
	}break;
	case E_5_1://
	{
		if (m_block.row + 1 >= C_ROW_BOTTOM
			|| m_marks[m_block.row+1][m_block.column + 1].is_block
			|| m_marks[m_block.row +1][m_block.column].is_block
			|| m_marks[m_block.row +1][m_block.column - 1].is_block)
		{
			ret = true;
		}
	}break;
	case E_5_2://
	{
		if (m_block.row + 2 >= C_ROW_BOTTOM || (m_block.row + 2 >= 0 && m_marks[m_block.row + 2][m_block.column].is_block))
		{
			ret = true;
		}
	}break;
	case E_5_3://
	{
		if (m_block.row + 2 >= C_ROW_BOTTOM || (m_block.row + 2 >= 0 && m_marks[m_block.row + 2][m_block.column].is_block))
		{
			ret = true;
		}
	}break;
	case E_5_4://
	{
		if (m_block.row + 2 >= C_ROW_BOTTOM || (m_block.row + 2 >= 0 && m_marks[m_block.row + 2][m_block.column].is_block))
		{
			ret = true;
		}
	}break;
	default:
		break;
	}
	return ret;
}

bool Tetris::CleanUp()
{
	bool ret = false;
	
	int row = -1;
	for (int i = 0; i < C_ROW; i++)
	{
		bool bClean = true;
		for (int j = 0; j < C_COLUMN; j++)
		{
			if (!m_marks[i][j].is_block)
			{
				bClean = false;
			}
		}
		if (bClean)
		{
			ret = true;
			for (int k = 0; k < C_COLUMN; k++)
			{
				m_marks[i][k].is_block = false;
				//m_marks[0][k] = m_marks[i][k];
			}
			for (int m = i-1; m >= 0; m--)
			{
				for (int n = 0; n < C_COLUMN; n++)
				{
					if (m+1< C_ROW_BOTTOM)
					{
						m_marks[m+1][n] = m_marks[m][n];
					}
				}
			}
		}
	}
	return ret;
}

void Tetris::setBlocksPointer(BlocksPointer tmp)
{
	for (int i = 0; i < C_ROW; i++)
	{
		for (int j = 0; j < C_COLUMN; j++)
		{
			m_marks[i][j].copy(tmp[i][j]);
		}
	}
}



