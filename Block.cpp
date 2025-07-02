#include "Block.h"

Block::Block()
{
	cellSize = 30;
	RotationState = 0;
	colors = GetAllColors();
}

void Block::Draw()
{
	vector<Position>Tiles = cells[RotationState];
	for (Position item : Tiles)
	{
		DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}
