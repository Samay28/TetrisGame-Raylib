#include "Block.h"

Block::Block()
{
	cellSize = 30;
	RotationState = 0;
	colors = GetAllColors();
	rowOffset = 0;
	columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	vector<Position>Tiles = GetCellPosition();
	for (Position item : Tiles)
	{
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int r, int c)
{
	rowOffset += r;
	columnOffset += c;
}

void Block::Rotate()
{
	RotationState++;
	if (RotationState == (int)cells.size())
	{
		RotationState = 0;
	}
}

void Block::undoRot()
{
	RotationState--;
}

vector<Position> Block::GetCellPosition() //modifying occupied cells
{
	vector<Position>tiles = cells[RotationState]; //current
	vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}
