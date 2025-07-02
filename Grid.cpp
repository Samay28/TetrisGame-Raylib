#include "Grid.h"


Grid::Grid()
{
	Row = 20; // Number of rows in the grid
	Col = 10; // Number of columns in the grid
	cellSize = 30; // Size of each cell in pixels
	InitializeGrid();
	colors = InitializeColors();
}

void Grid::InitializeGrid()
{
	for (int i = 0; i < Row; i++)
	{
		for(int j=0; j<Col;j++)
		{
			GridMap[i][j] = 0; 
		}
	}
}

void Grid::PrintGridValues()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cout << GridMap[i][j] << " "; 
		}
	}
}

void Grid::Draw()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			int cellValue = GridMap[i][j];	
			DrawRectangle(j * cellSize +1, i * cellSize+1, cellSize-1,cellSize-1, colors[cellValue]);
		}
	}
}

vector<Color> Grid::InitializeColors()
{	
	Color darkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 255 };
	Color orange = { 226, 116, 17, 255 };
	Color yellow = { 237, 234, 4, 255 };
	Color purple = { 166, 0, 247, 255 };
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };

	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };

}
