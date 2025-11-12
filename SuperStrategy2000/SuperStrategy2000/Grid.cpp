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

Grid::Grid(std::ifstream& _gridFile) {
	/*
		Level Files are expected to have a width and height and a 2D Grid of double-digit numbers.
		The first 2 numbers will represent the width and the height of the Grid respectively.
		the next 2 numbers will represent the width and the height of each Square respectively.
		Afterwards, the file loader will expect to see 'w*h' amount of numbers.
		Each of those numbers (after the width and height) will represent an actor or space in the world.
		Each number are spaced out so that we can use the '<<' operator to read those numbers.
	*/
	
	// Read the Size of the Grid and the Size of each Square
	_gridFile >> this->m_gridSize.x >> this->m_gridSize.y; // Reading Size of the Grid
	_gridFile >> this->m_squareSize.x >> this->m_squareSize.y; // Reading Size of each Square

	// The World Space the Grid takes
	float gridWorldSpaceX = static_cast<float>(this->m_squareSize.x * this->m_gridSize.x); // Static Cast to Float
	float gridWorldSpaceY = static_cast<float>(this->m_squareSize.y * this->m_gridSize.y); // Static Cast to Float
	this->m_gridBackground.setSize(sf::Vector2f(gridWorldSpaceX, gridWorldSpaceY));
	this->m_gridBackground.setFillColor(sf::Color(220, 220, 220)); // Faded-White
	this->m_gridBackground.setPosition(sf::Vector2f(0.0f, 0.0f)); // Set at Origin

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
			this->m_grid[y][x] = new Square(this->m_squareSize, sf::Vector2i(x, y));

			// Setting the World Position of the Square
			this->m_grid[y][x]->m_squareShape.setPosition( 
				sf::Vector2f(
					static_cast<float>(x * this->m_squareSize.x),
					static_cast<float>(y * this->m_squareSize.y)
				)
			);

			// Checking the Number for the Actor Type
			int actorType;
			_gridFile >> actorType;
			Actor*& actor = this->m_grid[y][x]->m_actorOnSquare;

			// 0 means it is an empty Square
			if (actorType == 0) continue;

			// Evalutate the Actor Type
			switch (actorType) {
				// Obstacle
				case 1: { actor = new Obstacle(); } break;

				// Knight
				case 2: 
				case 5: { actor = new Knight(actorType == 5); } break;

				// Archer
				case 3: 
				case 6: { actor = new Archer(actorType == 6); } break;

				// Mage
				case 4: 
				case 7: { actor = new Mage(actorType == 7); } break;
			}

			// Update the Actor's Grid Position
			actor->setActorSpritePosition(this->m_grid[y][x]->m_squareShape.getGlobalBounds().getCenter());
		}
	}

	// Connecting each Square of the Grid
	for (int y = 0; y < this->m_gridSize.y; y++) { // Down the y-axis
		for (int x = 0; x < this->m_gridSize.x; x++) { // Down the x-axis
			// List of Orthogonal Directions (no Corners)
			const std::vector<sf::Vector2i> directions = {
				{ 0, -1 }, // Up
				{ 0, 1 }, // Down
				{ -1, 0 }, // Left
				{ 1, 0 } // Right
			};

			for (auto direction : directions) {
				// Calculate the Position of this Neighboring Square
				sf::Vector2i neighborPos(x + direction.x, y + direction.y);

				// Boolean to check the Position of this Neighboring Square is within the Grid
				bool validNeighborPos = (
					neighborPos.x >= 0 &&
					neighborPos.x < this->m_gridSize.x &&
					neighborPos.y >= 0 &&
					neighborPos.y < this->m_gridSize.y
					);

				// Ensure the Position of this Neighboring Square is within the Grid
				if (validNeighborPos) {
					// Neighboring Square
					Square* neighboringSquare = this->m_grid[neighborPos.y][neighborPos.x];

					// If there is an Actor on this Neighboring Square
					if (neighboringSquare->m_actorOnSquare != nullptr) {
						// Prevent pointing to Obstacles
						if (neighboringSquare->m_actorOnSquare->getActorType() == Actor::Type::OBSTACLE) {
							// Skip this Neighboring Square
							continue;
						}
					}

					// Connect the Square to its Neighboring Square
					this->m_grid[y][x]->m_squareNeighbors.push_back(neighboringSquare);
				}
			}
		}
	}

	// Default
	this->m_selectedSquare = nullptr;
	this->m_hoverSquare = nullptr;
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
		/*
			Find which Square the Mouse is hovering over:
			- Convert the Mouse World Position into Grid Coordinates.
			- Subtract the Grid's Position Offset from World Origin.
			- Divide by Square Size to get the Square Index (x, y) within the Grid Array.
		*/

		// Square Index (x, y) within the Grid Array
		int squareX = static_cast<int>((mouseWorldPosition.x - gridSpace.position.x) / this->m_squareSize.x);
		int squareY = static_cast<int>((mouseWorldPosition.y - gridSpace.position.y) / this->m_squareSize.y);

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

void Grid::clear() {
	// Loop through each Square on the Grid
	for (int y = 0; y < this->m_gridSize.y; y++) { // Down the y-axis
		for (int x = 0; x < this->m_gridSize.x; x++) { // Down the x-axis
			// If this Square is not Selected or Hovered
			if (this->m_grid[y][x] != this->m_selectedSquare) {
				// Reset the Square
				this->m_grid[y][x]->reset();
			}
		}
	}
}

void Grid::breadthFirstSearch(Square* _start, int _depth, bool _checkActors) {
	std::vector<Square*> visited; // List of Visited Squares
	std::queue<Square*> toVisit; // Queue of Squares to Visit
	toVisit.push(_start); // Add the Start
	int depth = 0; // Start at 0

	// Loop until reaching the given Depth
	while (depth <= _depth) {
		// List of Neighbors at this Depth
		std::vector<Square*> nextToVisit;

		// Loop until the to Visit Queue is Empty
		while (toVisit.empty() == false) {
			// Dequeue the Front
			Square* square = toVisit.front();
			toVisit.pop();

			// Loop through the Neighbors
			for (auto& neighbor : square->m_squareNeighbors) {
				// Skip Neighor Squares with an Actor
				if (_checkActors == true && neighbor->m_actorOnSquare != nullptr) continue;

				// Check if this Neighbor Square has been Visited
				bool hasVisited = false;
				for (auto& visitedSquare : visited) {
					// This Neighbor Square has already been Visisted
					if (neighbor == visitedSquare) {
						hasVisited = true;
						break;
					}
				}

				// If this Neighbor Square has not already been Visited
				if (hasVisited == false) {
					// Add to the Next to Visit List
					nextToVisit.push_back(neighbor);
				}
			}

			// Highlight Square
			square->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_SELECTED);
			visited.push_back(square); // This Square has now been Visited
		}

		// Next to Visit List into the to Visit Queue
		for (auto& toVisitSquare : nextToVisit) {
			toVisit.push(toVisitSquare);
		}

		// Increase Depth
		depth++;
	}
}