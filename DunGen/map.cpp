#include "stdafx.h"
#include "map.h"
#include <string>
#include <iostream>																										   
#include <vector>

using namespace std;

vector<Cell*> Map::dead_ends;

// Just a constructor
Map::Map(unsigned int sizeX, unsigned int sizeY) {
	this->size_x = sizeX; this->size_y = sizeY;	  // Set the private fields size_x and size_y to the sepsified parameters.
	this->map_grid = vector< vector<Cell>>(this->size_y, vector<Cell>(this->size_x));   // Initialize the map_grid with 
											    //2. dimensional vectors containing cell-objects
	for (int i = 0; i < this->map_grid.size(); i++) // Loop through the first vector
	{
		for (int j = 0; j < this->map_grid[i].size(); j++) 	// Loop through iterator
		{
			map_grid[j][i] = Cell(j, i); // Set the iterator's referenced value to a new cell-object
		}
	}
}
Map::~Map() { cout << "Deleting map!" << endl; }	// Just a destructor

													// Returns the cell at a spesified position in the map. (X and Y values)
Cell* Map::getCellAtPos(int x, int y)
{
	return &this->map_grid.at(y).at(x);	// Using .at() instead of Operator[] to throw exceptions and bypass errors!
}

Cell * Map::getCellAtPos(pair<int, int> pos)
{
	return &(this->map_grid[pos.second][pos.first]);
}

// Draws an induvidual cell at a spesific point in the grid
void Map::drawCellAtPos(int x, int y) {
	this->map_grid.at(y).at(x).drawCell();	// Draws the cell at a posistion in the map_grid.
}

// Simply draws the hole map and all of it's cell-data to the terminal
void Map::drawMap() {
	int mapX, mapY, cellRow = 0;  // Initialize the loop-counters. Optional!
	for (mapY = 0; mapY < this->size_y; mapY++) {   // Loop through map_grid rows
													// cout << "Map Y: " << mapY << endl;	 // For debugging 
		for (cellRow = 0; cellRow < 3; cellRow++) {   // Loop through the cellRows within each map_grid.
			for (mapX = 0; mapX < this->size_x; mapX++) {   // Loop through the colums in the map_grid
				vector<char> temp_char = this->map_grid[mapY][mapX].getCellRow(cellRow); // Get the char_vector of the first row in cell
				vector<char>::iterator it = temp_char.begin();	// Create iterator pointer at the begining of vector
				for (; it < temp_char.end(); ++it)	// Loop through vector using the iterator
				{
					cout << *it; // Print out the value of the iterator
				}
				cout << "";  // Used for debug-purposes!
			}
			cout << endl; // Newline for new cellrow
		}
		cout << "";
	}
}

void Map::drawSubCellMap() {
	for (int i = 0; i < this->size_y; i++) { //map y
		for (int j = 0; j < 5; j++){ //subcell row number
			for (int k = 0; k < this->size_y - 1; k++) { //map x
				this->map_grid[i][k].drawSubCellRow(j);
			}
			cout << endl;
		}
	}
}

void Map::outputMap(string filename) {
	ofstream outfile;

	outfile.open(filename + ".txt", std::ios_base::app);
	
	int mapX, mapY, cellRow = 0;  // Initialize the loop-counters. Optional!
	for (mapY = 0; mapY < this->size_y; mapY++) {   // Loop through map_grid rows
													// cout << "Map Y: " << mapY << endl;	 // For debugging 
		for (cellRow = 0; cellRow < 3; cellRow++) {   // Loop through the cellRows within each map_grid.
			for (mapX = 0; mapX < this->size_x; mapX++) {   // Loop through the colums in the map_grid
				vector<char> temp_char = this->map_grid[mapY][mapX].getCellRow(cellRow); // Get the char_vector of the first row in cell
				vector<char>::iterator it = temp_char.begin();	// Create iterator pointer at the begining of vector
				for (; it < temp_char.end(); ++it)	// Loop through vector using the iterator
				{
					outfile << *it; // Print out the value of the iterator
				}
				outfile << "";  // Used for debug-purposes!
			}
			outfile << endl; // Newline for new cellrow
		}
		outfile << ""; // Also used for debugging!
	}
}

// Returns the x,y size of map
pair<int,int> Map::getSize() {
	return{ this->size_x, this->size_y };
}
