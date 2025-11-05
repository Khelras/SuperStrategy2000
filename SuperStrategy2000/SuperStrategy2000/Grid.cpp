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
	// Constant References to Main Window and Camera View
	const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
	const sf::View& CAMERA_VIEW = GameManager::getInstance()->m_cameraManager.m_cameraView;

	// Mouse World Position
	sf::Vector2f mouseWorldPosition = MAIN_WINDOW.mapPixelToCoords(sf::Mouse::getPosition(MAIN_WINDOW), CAMERA_VIEW);

	// Check if the Mouse Position is within the bounds of the Grid Space
	sf::FloatRect gridSpace = this->m_gridBackground.getGlobalBounds(); // The Grid Space

	// Mouse is within the bounds of the Grid Space
	if (gridSpace.contains(mouseWorldPosition) == true) {
		// Now find the Tile the Mouse is hovering over
		sf::Vector2i tileSize = Tile::TILE_SIZE; // The size of each Tile
		
		/*
			Find which Tile the Mouse is hovering over:
			- Convert the Mouse World Position into Grid Coordinates.
			- Subtract the Grid's Position Offset from World Origin.
			- Divide by Tile Size to get the Tile Index (x, y) within the Grid Array.
		*/

		// Tile Index (x, y) within the Grid Array
		int tileX = static_cast<int>((mouseWorldPosition.x - gridSpace.position.x) / tileSize.x);
		int tileY = static_cast<int>((mouseWorldPosition.y - gridSpace.position.y) / tileSize.y);

		// Clamp indices to ensure they are within bounds
		tileX = std::clamp(tileX, 0, Grid::GRID_SIZE_X - 1);
		tileY = std::clamp(tileY, 0, Grid::GRID_SIZE_Y - 1);\
		
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