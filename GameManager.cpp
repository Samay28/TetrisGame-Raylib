#include "GameManager.h"
#include <random>

GameManager::GameManager()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	GameOver = false;	

	InitAudioDevice(); // for sound initialization
	music = LoadMusicStream("Sounds/music.mp3");
	PlayMusicStream(music);

	soundRotate = LoadSound("Sounds/rotate.mp3");
	soundClear = LoadSound("Sounds/clear.mp3");
}

GameManager::~GameManager()
{
	UnloadMusicStream(music);
	UnloadSound(soundRotate);
	UnloadSound(soundClear);
	CloseAudioDevice();
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
	currentBlock.Draw(11,11);
	switch (nextBlock.getId()) //for UI
	{
	case 3 :
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}

void GameManager::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (GameOver && keyPressed != 0)
	{
		GameOver = false;
		ResetGame();
	}
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
		updateScore(0, 1);
		break;
	case KEY_UP:
			RotateBlock();
			break;
	}
}

void GameManager::MoveBlockLeft()
{	
	if (GameOver) return;
	currentBlock.Move(0, -1);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(0, 1);
	}
}

void GameManager::MoveBlockRight()
{	
	if (GameOver) return;
	currentBlock.Move(0, 1);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(0, -1);
	}
}

void GameManager::MoveBlockDown()
{	
	if (GameOver) return;
	currentBlock.Move(1, 0);
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}
}

void GameManager::updateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2 :
		score += 200;
		break;
	case 3:
		score += 300;
		break;
	default:
		break;
	}
	score += moveDownPoints;
}

void GameManager::ResetGame()
{
	grid.InitializeGrid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	setScore(0);
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
	if (!blockFits())
	{
		GameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared =  grid.ClearFullRows();
	if (rowsCleared > 0)
	{
		PlaySound(soundClear);
	}
	updateScore(rowsCleared, 0);
}

void GameManager::RotateBlock()
{	
	if (GameOver) return;	
	currentBlock.Rotate();
	if (isBlockOutside() || !blockFits())
	{
		currentBlock.undoRot();
	}
	else
	{
		PlaySound(soundRotate);
	}
}
