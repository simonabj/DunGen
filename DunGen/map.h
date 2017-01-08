#pragma once
#ifndef MAP_H
#define MAP_H

#include "stdafx.h"
#include "cell.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Map {
private:
	unsigned int size_x, size_y; //Declaration for the size of the map
	vector< vector<Cell>> map_grid; //The map itself
	
public:
	static vector<pair<int, int> > dead_ends;
	
	Map::Map(unsigned int sizeX, unsigned int sizeY);
	Map::~Map();

	// Returns the cell at xy-coordinates
	Cell* Map::getCellAtPos(int x, int y);

	// Draws the cell at a specific xy-coordinate
	void Map::drawCellAtPos(int x, int y);

	// Draws the entire map.
	void Map::drawMap();

	void Map::drawSubCellMap();

	// Writes the enitre map to .txt file
	void Map::outputMap(string filename);

	/* The following functions is used for generating algorithms and indirect methods of changing cells. */
	// Set cell-struct at a spesific position
	void Map::setCellStructureAtPos(int x, int y, string newCellStruct);
	// Toggles a specific side of cell. Indirect method of Cell::toggleSide()
	void Map::toggleCellSideAtPos(int x, int y, int side, bool state);
	// Sets the cell at [y][x] to be visited. Indirect method of Cell::setVisited(true)
	void Map::visitCell(int x, int y);
	// Returns the visited-state of cell at [y][x] coordinates.
	bool Map::cellVisited(int x, int y);
	// Returns all the opened sides of a cell at a position
	vector<int> Map::getCellopeningsAtPos(int x, int y);

	//Returns the size of the map
	pair<int, int> Map::getSize();
};

#endif // !MAP_H