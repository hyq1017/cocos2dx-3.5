#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "TetrisCommon.h"

extern Block g_marks[C_ROW][C_COLUMN];

class Tetris
{
public:
	Tetris();
	~Tetris();
	static Tetris* Create(TetrisKind kind);
	void Convert();
	void Transform();
	void ConvertOnEnter();
	void ConvertOnExit();
	void Down();
	void Left();
	void Right();
	bool DownOk();
	bool LeftOk();
	bool RightOk();
	bool Ok();
	bool EdgeOk();
	bool IsBottom();
	bool CleanUp();
	void setKind(TetrisKind kind){ m_kind = kind; }
	TetrisKind getKind(){ return m_kind; }
private:
	Block m_block;
	TetrisKind m_kind;
private:
	//no copy
	Tetris(const Tetris&);
	Tetris& operator=(const Tetris&);
private:
	
};




#endif // !__TETRIS_H__

