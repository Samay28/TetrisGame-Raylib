#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;
class Grid
{
public:
	Grid();
	int GridMap[20][10];

	bool isCellOutside(int row, int col);
	void InitializeGrid();
	void PrintGridValues();
	void Draw();

private:
	
	int Row;
	int Col;
	int cellSize;
	vector<Color>colors;
};

