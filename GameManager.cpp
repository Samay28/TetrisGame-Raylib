#include "GameManager.h"
#include <random>

GameManager::GameManager()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block GameManager::GetRandomBlock()
{	
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int indx = rand() % blocks.size();
	Block block = blocks[indx];
	blocks.erase(blocks.begin() + indx);
	return block;
}

vector<Block> GameManager::GetAllBlocks()
{
	return { IBlock(), JBlock(),LBlock(), OBlock(), SBlock(),TBlock(), ZBlock() };
}
void GameManager::Draw()
{
	grid.Draw();
	currentBlock.Draw();
}

void GameManager::HandleInput()
{
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		break;
	case KEY_UP:
			RotateBlock();
			break;
	}
}

void GameManager::MoveBlockLeft()
{	
	currentBlock.Move(0, -1);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(0, 1);
	}
}

void GameManager::MoveBlockRight()
{
	currentBlock.Move(0, 1);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(0, -1);
	}
}

void GameManager::MoveBlockDown()
{	

	currentBlock.Move(1, 0);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}
}

bool GameManager::blockFits()
{
	vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.isCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
		return true;
}

bool GameManager::isBlockOutside()
{
	vector<Position>tiles = currentBlock.GetCellPosition();
	for (Position i : tiles)
	{
		if (grid.isCellOutside(i.row, i.column))
		{
			return true;
		}
	}
	return false;
}

void GameManager::LockBlock()
{
	vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position i : tiles)
	{
		//now we will change the index of the cells 
		grid.GridMap[i.row][i.column] = currentBlock.getId();
	}
	currentBlock = nextBlock;
	nextBlock = GetRandomBlock();
	grid.ClearFullRows();
}

void GameManager::RotateBlock()
{
	currentBlock.Rotate();
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.undoRot();
	}
}
