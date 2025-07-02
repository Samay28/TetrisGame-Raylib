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

	void InitializeGrid();
	void PrintGridValues();
	void Draw();

private:
	vector<Color>InitializeColors();
	int Row;
	int Col;
	int cellSize;
	vector<Color>colors;
};

