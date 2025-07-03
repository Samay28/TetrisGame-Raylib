#include "Block.h"
#include "Position.h" 


//here all types of blocks will be listedin different classes
class LBlock : public Block
{
public:
	LBlock()
	{
		setId(1);
		cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
		cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
		Move(0, 3); //start from centre
	}
};
class JBlock : public Block
{
public:
	JBlock()
	{
		setId(1);
		cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
		cells[3] = { Position(0,1), Position(1,1), Position(2,0), Position(2,1) };
		Move(0, 3);
	}
};
class IBlock : public Block
{
public:
	IBlock()
	{
		setId(1);
		cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
		cells[1] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
		cells[2] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
		cells[3] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
		Move(-1, 3);
	}
};
class OBlock : public Block
{
public:
	OBlock()
	{
		setId(1);
		cells[0] = { Position(0,1), Position(1,0), Position(0,1), Position(1,1) };
		/*cells[1] = { Position(0,1), Position(1,0), Position(0,1), Position(1,1) };
		cells[2] = { Position(0,1), Position(1,0), Position(0,1), Position(1,1) };
		cells[3] = { Position(0,1), Position(1,0), Position(0,1), Position(1,1) };*/
		Move(0, 4);
	}
};
class SBlock : public Block
{
public:
	SBlock()
	{
		setId(1);
		cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
		cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
		cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};
class TBlock : public Block
{
public:
	TBlock()
	{
		setId(1);
		cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
		cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};
class ZBlock : public Block
{
public:
	ZBlock()
	{
		setId(1);
		cells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(2,1), Position(2,2) };
		cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,0) };
		Move(0, 3);
	}
};

	