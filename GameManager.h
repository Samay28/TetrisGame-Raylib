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

	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
private:

	bool isBlockOutside();	
	void LockBlock(); //after it touches the grnd
	void RotateBlock();
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};

