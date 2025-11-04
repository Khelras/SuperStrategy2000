/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Grid.cpp
Description : Defines the Grid Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Grid.h"

Grid::Grid() {
	// Creating the Grid
	for (int y = 0; y < this->GRID_SIZE_Y; y++) { // Down the y-axis
		for (int x = 0; x < this->GRID_SIZE_X; x++) { // Down the x-axis
			// Creating the Tile
			this->m_grid[y][x] = new Tile(sf::Vector2i(x, y));
		}
	}
}

Grid::~Grid() {
}
