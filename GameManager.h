#pragma once
#include <iostream>
#include "Grid.h"
#include "Blocks.cpp"
using namespace std;


class GameManager
{
public:
	GameManager();
	Grid grid;

	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	void Draw();
private:
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};

