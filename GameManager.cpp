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
