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

Grid::Grid(sf::Vector2i _gridSize, sf::Vector2i _squareSize) {
	// Resize the Square
	Square::SQUARE_SIZE = _squareSize;

	// Selected and Hover Square
	this->m_selectedSquare = nullptr;
	this->m_hoverSquare = nullptr;

	// Grid Size
	this->m_gridSize = _gridSize;
	
	// Resize the 2D Grid Array
	this->m_grid.clear(); // Clear the 2D Grid Array
	this->m_grid.resize(this->m_gridSize.y); // Resize the Columns (Down the y-axis) BEFORE the Rows
	for (auto& row : this->m_grid) { // Then, Resize each Row by going down the y-axis
		row.clear(); // Clear Row
		row.resize(this->m_gridSize.x); // Resize Row
	}

	// Creating the Grid
	for (int y = 0; y < this->m_gridSize.y; y++) { // Down the y-axis
		for (int x = 0; x < this->m_gridSize.x; x++) { // Down the x-axis
			// Creating the Square
			this->m_grid[y][x] = new Square(sf::Vector2i(x, y));
		}
	}

	// Connecting each Square of the Grid
	for (int y = 0; y < this->m_gridSize.y; y++) { // Down the y-axis
		for (int x = 0; x < this->m_gridSize.x; x++) { // Down the x-axis
			// Connecting Square to its surrounding Squares
			for (int dx = -1; dx <= 1; dx++) { // Loops through the surroundings across the x-axis
				for (int dy = -1; dy <= 1; dy++) { // Loops through the surroundings across the y-axis
					if (dx == 0 && dy == 0) continue; // Skip itself

					// Calculate the Position of this Neighboring Square
					sf::Vector2i neighborPos(x + dx, y + dy);

					// Boolean to check the Position of this Neighboring Square is within the Grid
					bool validNeighborPos = (
						neighborPos.x >= 0 &&
						neighborPos.x < this->m_gridSize.x &&
						neighborPos.y >= 0 &&
						neighborPos.y < this->m_gridSize.y
					);
					
					// Ensure the Position of this Neighboring Square is within the Grid
					if (validNeighborPos) {
						// Connect the Square to its Neighboring Square
						this->m_grid[y][x]->m_squareNeighbors.push_back(this->m_grid[neighborPos.y][neighborPos.x]);
					}
				}
			}
		}
	}

	// The Screen Space the Grid takes
	float gridSpaceX = static_cast<float>(Square::SQUARE_SIZE.x * this->m_gridSize.x); // Static Cast to Float
	float gridSpaceY = static_cast<float>(Square::SQUARE_SIZE.y * this->m_gridSize.y); // Static Cast to Float
	this->m_gridBackground.setSize(sf::Vector2f(gridSpaceX, gridSpaceY));
	this->m_gridBackground.setFillColor(sf::Color::White); // White
	this->m_gridBackground.setPosition(sf::Vector2f(Grid::MARGIN, Grid::MARGIN)); // Account for the Margin
}

Grid::~Grid() {
	// Delete all Squares in the 2D Grid Array
	for (auto& row : this->m_grid) {
		for (auto& square : row) {
			// Delete Square
			delete (square); 
			square = nullptr;
		}
	}

	// Clear the 2D Grid Array
	this->m_grid.clear();
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
		// Now find the Square the Mouse is hovering over
		sf::Vector2i squareSize = Square::SQUARE_SIZE; // The size of each Square
		
		/*
			Find which Square the Mouse is hovering over:
			- Convert the Mouse World Position into Grid Coordinates.
			- Subtract the Grid's Position Offset from World Origin.
			- Divide by Square Size to get the Square Index (x, y) within the Grid Array.
		*/

		// Square Index (x, y) within the Grid Array
		int squareX = static_cast<int>((mouseWorldPosition.x - gridSpace.position.x) / squareSize.x);
		int squareY = static_cast<int>((mouseWorldPosition.y - gridSpace.position.y) / squareSize.y);

		// Clamp indices to ensure they are within bounds
		squareX = std::clamp(squareX, 0, this->m_gridSize.x - 1);
		squareY = std::clamp(squareY, 0, this->m_gridSize.y - 1);\
		
		// Performing Hover
		if (this->m_hoverSquare == nullptr) { // There is NO pre-existing Hover
			// Hover
			this->m_hoverSquare = this->m_grid[squareY][squareX];
			this->m_hoverSquare->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_SELECTED);
		}
		else if (this->m_hoverSquare != nullptr) { // There IS a pre-existing Hover
			// Reset the pre-existing Hover
			this->m_hoverSquare->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_DEFAULT);

			// Then, set a new Hover
			this->m_hoverSquare = this->m_grid[squareY][squareX];
			this->m_hoverSquare->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_SELECTED);
		}
	}
	// Mouse is outside the bounds of the Grid Space
	else {
		// If there IS a pre-existing Hover
		if (this->m_hoverSquare != nullptr) {
			// Reset and Remove Hovers
			this->m_hoverSquare->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_DEFAULT); // Reset Hover
			this->m_hoverSquare = nullptr; // Remove Hover
		}
	}
}