#pragma once
#include <iostream>
#include "Grid.h"
#include "Blocks.cpp"
using namespace std;


class GameManager
{
public:
	GameManager();
	~GameManager();
	Grid grid;

	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	void Draw();

	void HandleInput();
	void MoveBlockDown();

	void setScore(int s) { score = s; }
	int getScore() { return score; }
	void updateScore(int linesCleared, int moveDownPoints);

	bool GameOver;
	Music music;
private:

	int score;
	void ResetGame();
	bool blockFits();
	bool isBlockOutside();	
	void LockBlock(); //after it touches the grnd
	void RotateBlock();
	void MoveBlockLeft();
	void MoveBlockRight();

	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

	Sound soundRotate;
	Sound soundClear;
};

