#pragma once
#include <iostream>
#include "Grid.h"
#include "Position.h"
#include "ColorDatabase.h"
#include <map>	
#include <vector>
using namespace std;
class Block
{
public:
	Block();

	int getId() const { return id; }
	void setId(int const id) { this->id = id; }

	map<int, vector<Position>>cells;
	vector<Color>colors;


	void Draw();

private:
	int id;
	int cellSize;
	int RotationState;
};

