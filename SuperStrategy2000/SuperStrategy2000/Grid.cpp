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
	// Selected Tile
	this->m_selectedTile = nullptr;

	// Creating the Grid
	for (int y = 0; y < this->GRID_SIZE_Y; y++) { // Down the y-axis
		for (int x = 0; x < this->GRID_SIZE_X; x++) { // Down the x-axis
			// Creating the Tile
			this->m_grid[y][x] = new Tile(sf::Vector2i(x, y));
		}
	}

	// Connecting each Tile of the Grid
	for (int y = 0; y < this->GRID_SIZE_Y; y++) { // Down the y-axis
		for (int x = 0; x < this->GRID_SIZE_X; x++) { // Down the x-axis
			// Connecting Tile to its surrounding Tiles
			for (int dx = -1; dx <= 1; dx++) { // Loops through the surroundings across the x-axis
				for (int dy = -1; dy <= 1; dy++) { // Loops through the surroundings across the y-axis
					if (dx == 0 && dy == 0) continue; // Skip itself

					// Calculate the Position of this Neighboring Tile
					sf::Vector2i neighborPos(x + dx, y + dy);

					// Ensure the Position of this Neighboring Tile is within the Grid
					if (neighborPos.x >= 0 &&  neighborPos.x < this->GRID_SIZE_X && neighborPos.y >= 0 && neighborPos.y < this->GRID_SIZE_Y) {
						// Connect the Tile to its Neighboring Tile
						this->m_grid[y][x]->m_tileNeighbors.push_back(this->m_grid[neighborPos.y][neighborPos.x]);
					}
				}
			}
		}
	}

	// The Screen Space the Grid takes
	float gridSpaceX = static_cast<float>(this->m_selectedTile->TILE_SIZE.x * this->GRID_SIZE_X); // Static Cast to Float
	float gridSpaceY = static_cast<float>(this->m_selectedTile->TILE_SIZE.y * this->GRID_SIZE_Y); // Static Cast to Float
	this->m_gridBackground.setSize(sf::Vector2f(gridSpaceX, gridSpaceY));
	this->m_gridBackground.setFillColor(sf::Color::White); // White
}

Grid::~Grid() {
}
