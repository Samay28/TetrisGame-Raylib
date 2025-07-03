#include "Grid.h"
#include "ColorDatabase.h"

Grid::Grid()
{
	Row = 20; // Number of rows in the grid
	Col = 10; // Number of columns in the grid
	cellSize = 30; // Size of each cell in pixels
	InitializeGrid();
	colors = GetAllColors();
}

bool Grid::isCellOutside(int row, int col)
{
	if (row >= 0 && row <Row && col >= 0 && col< Col)
	{
		return false;
	}
	return true;
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

bool Grid::isCellEmpty(int r, int c)
{
	if (GridMap[r][c] == 0)
	{
		return true;
	}
	return false;
}

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int r = Row - 1; r >= 0; r--)
	{	
		
		if (isRowFull(r))
		{
			ClearRow(r);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(r, completed);		
		}
	}
	return completed;
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

bool Grid::isRowFull(int row)
{	
	for (int c = 0; c < Col; c++)
	{
		if (GridMap[row][c] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int r)
{
	for (int c = 0; c < Col; c++)
	{
		GridMap[r][c] = 0;
	}
}

void Grid::MoveRowDown(int r, int rownum)
{
	for (int c = 0; c < Col; c++)
	{
		GridMap[r + rownum][c] = GridMap[r][c];
		GridMap[r][c] = 0;
	}
}

