/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Grid.h
Description : Declares the Grid Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Tile.h"

class Grid {
private:
	// Grid Size
	static const int GRID_SIZE_X = 10;
	static const int GRID_SIZE_Y = 12;

public:
	// Grid Attributes
	sf::RectangleShape m_gridBackground;
	Tile* m_grid[GRID_SIZE_Y][GRID_SIZE_X];
	Tile* m_selectedTile;

	// Constructor and Destructor
	Grid(); // Constructor
	~Grid(); // Destructor
};

