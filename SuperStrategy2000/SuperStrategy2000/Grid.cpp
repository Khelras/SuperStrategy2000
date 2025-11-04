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
#include "GameManager.h"

Grid::Grid() {
	// Selected and Hover Tile
	this->m_selectedTile = nullptr;
	this->m_hoverTile = nullptr;

	// Creating the Grid
	for (int y = 0; y < Grid::GRID_SIZE_Y; y++) { // Down the y-axis
		for (int x = 0; x < Grid::GRID_SIZE_X; x++) { // Down the x-axis
			// Creating the Tile
			this->m_grid[y][x] = new Tile(sf::Vector2i(x, y));
		}
	}

	// Connecting each Tile of the Grid
	for (int y = 0; y < Grid::GRID_SIZE_Y; y++) { // Down the y-axis
		for (int x = 0; x < Grid::GRID_SIZE_X; x++) { // Down the x-axis
			// Connecting Tile to its surrounding Tiles
			for (int dx = -1; dx <= 1; dx++) { // Loops through the surroundings across the x-axis
				for (int dy = -1; dy <= 1; dy++) { // Loops through the surroundings across the y-axis
					if (dx == 0 && dy == 0) continue; // Skip itself

					// Calculate the Position of this Neighboring Tile
					sf::Vector2i neighborPos(x + dx, y + dy);

					// Ensure the Position of this Neighboring Tile is within the Grid
					if (neighborPos.x >= 0 &&  neighborPos.x < Grid::GRID_SIZE_X && neighborPos.y >= 0 && neighborPos.y < Grid::GRID_SIZE_Y) {
						// Connect the Tile to its Neighboring Tile
						this->m_grid[y][x]->m_tileNeighbors.push_back(this->m_grid[neighborPos.y][neighborPos.x]);
					}
				}
			}
		}
	}

	// The Screen Space the Grid takes
	float gridSpaceX = static_cast<float>(Tile::TILE_SIZE.x * Grid::GRID_SIZE_X); // Static Cast to Float
	float gridSpaceY = static_cast<float>(Tile::TILE_SIZE.y * Grid::GRID_SIZE_Y); // Static Cast to Float
	this->m_gridBackground.setSize(sf::Vector2f(gridSpaceX, gridSpaceY));
	this->m_gridBackground.setFillColor(sf::Color::White); // White
}

Grid::~Grid() {
}

void Grid::process() {
	// Mouse Position based on the Main Window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(GameManager::getInstance()->m_windowManager.m_mainWindow);

	// Check if the Mouse Position is within the bounds of the Grid Space
	sf::FloatRect gridSpace = this->m_gridBackground.getGlobalBounds(); // The Grid Space
	bool isWithinGridSpace = ( // Check if the Mouse is within the bounds of the Grid Space
		// X-axis
		mousePosition.x > gridSpace.position.x && // Mouse is to the Right of the Left-Side of Grid Space
		mousePosition.x < (gridSpace.position.x + gridSpace.size.x) && // Mouse is to the Left of the Right-Side of Grid Space
		// Y-axis
		mousePosition.y > gridSpace.position.y && // Mouse is Below the Top-Side of Grid Space
		mousePosition.y < (gridSpace.position.y + gridSpace.size.y) // Mouse is Above the Bottom-Side of Grid Space
	);

	// Mouse is within the bounds of the Grid Space
	if (isWithinGridSpace == true) {
		// Now find the Tile the Mouse is hovering over
		sf::Vector2i tileSize = Tile::TILE_SIZE; // The size of each Tile
		
		/*
			Find the Tile X and Y by using similar logic of the modulus operator.
			Minus the Mouse-Position by the Tile Size until we reach the bounds of the Grid-Space.
			For Each time we minus Mouse-Position by Tile Size, we increment the Tile-Position by 1.
			This will get us the Tile-Position in the Grid Array :O
		*/

		// Finding the X
		float mouseX = mousePosition.x;
		int tileX = 0;
		while ((mouseX - tileSize.x) > gridSpace.position.x) { // Loops unitl we get the Tile X
			mouseX -= tileSize.x; // Decrease Mouse-X by the Tile Width
			tileX++; // Increase tile X
		}

		// Finding the Y
		float mouseY = mousePosition.y;
		int tileY = 0;
		while ((mouseY - tileSize.y) > gridSpace.position.y) { // Loops unitl we get the Tile Y
			mouseY -= tileSize.y; // Decrease Mouse-X by the Tile Height
			tileY++; // Increase tile Y
		}
		
		// Performing Hover
		if (this->m_hoverTile == nullptr) { // There is NO pre-existing Hover
			// Hover
			this->m_hoverTile = this->m_grid[tileY][tileX];
			this->m_hoverTile->m_tileShape.setOutlineColor(Tile::TILE_OUTLINECOLOR_SELECTED);
		}
		else if (this->m_hoverTile != nullptr) { // There IS a pre-existing Hover
			// Reset the pre-existing Hover
			this->m_hoverTile->m_tileShape.setOutlineColor(Tile::TILE_OUTLINECOLOR_DEFAULT);

			// Then, set a new Hover
			this->m_hoverTile = this->m_grid[tileY][tileX];
			this->m_hoverTile->m_tileShape.setOutlineColor(Tile::TILE_OUTLINECOLOR_SELECTED);
		}
	}
	// Mouse is outside the bounds of the Grid Space
	else {
		// If there IS a pre-existing Hover
		if (this->m_hoverTile != nullptr) {
			// Reset and Remove Hovers
			this->m_hoverTile->m_tileShape.setOutlineColor(Tile::TILE_OUTLINECOLOR_DEFAULT); // Reset Hover
			this->m_hoverTile = nullptr; // Remove Hover
		}
	}
}