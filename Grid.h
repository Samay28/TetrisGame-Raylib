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
	bool isCellEmpty(int r, int c);
	int ClearFullRows();
	void Draw();

private:
		
	bool isRowFull(int row);
	void ClearRow(int r);
	void MoveRowDown(int r, int rownum);
	int Row;
	int Col;
	int cellSize;
	vector<Color>colors;
};

