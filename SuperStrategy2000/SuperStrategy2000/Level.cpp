/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Level.cpp
Description : Defines the Level Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Level.h"

Level::Level(unsigned int _levelNumber, std::ifstream& _gridFile) {
	this->m_levelNumber = _levelNumber;
	this->m_levelGameBoard = new Grid(_gridFile);

	// After constructing the Game Board Grid
	if (this->m_levelGameBoard != nullptr) {
		// Loop through each Square on the Game Board and collect the Actors
		const auto& grid = this->m_levelGameBoard->m_grid;
		for (const auto& row : grid) { // Loop down each Row
			for (const auto& square : row) { // Loop through each Square on this Row
				// Square has an Actor on it
				if (square->m_actorOnSquare != nullptr) {
					// Add the Actor to the Actors Array
					this->m_levelActors.push_back(square->m_actorOnSquare);

					// Check if this is a Unit
					if (square->m_actorOnSquare->getActorType() != Actor::Type::OBSTACLE) {
						// Downcast Actor Class to Unit Class
						Unit* unit = dynamic_cast<Unit*>(square->m_actorOnSquare);

						// Add the Unit to the Units Array
						this->m_levelUnits.push_back(unit);
					}
				}
			}
		}
	}
	else {
		// Error Message
		std::cerr << "Game Board Grid in Level " << this->m_levelNumber << " failed to construct!\n";
	}
}

Level::~Level() {
	// Ensure Game Board exists
	if (this->m_levelGameBoard != nullptr) {
		// Delete Game Board
		delete (this->m_levelGameBoard);
	}

	// Delete all the Actors
	for (auto& actor : this->m_levelActors) {
		// Ensure Actor exists
		if (actor != nullptr) {
			// Delete Actor
			delete(actor);
			actor = nullptr;
		}
	}

	// Clear Actor and Unit Arrays
	this->m_levelActors.clear();
	this->m_levelUnits.clear();
}

void Level::process() {
	// Game Board Grid Process Loop
	this->m_levelGameBoard->process();

	// Check if there is a Selected Square
	if (this->m_levelGameBoard->m_selectedSquare != nullptr) {
		// Check if that Selected Square has an Actor
		Actor* actor = this->m_levelGameBoard->m_selectedSquare->m_actorOnSquare;
		if (actor != nullptr) {
			// Check if that Actor is a Player Unit
			if (actor->getActorType() == Actor::Type::UNIT_PLAYER_KNIGHT ||
				actor->getActorType() == Actor::Type::UNIT_PLAYER_ARCHER ||
				actor->getActorType() == Actor::Type::UNIT_PLAYER_MAGE) {
				// Downcast to Unit
				Unit* unit = dynamic_cast<Unit*>(actor);

				// Show the Range
				this->m_levelGameBoard->breadthFirstSearch(
					this->m_levelGameBoard->m_selectedSquare,
					unit->getUnitSpeed()
				);
			}
		}
	}
}

void Level::drawLevel(sf::RenderWindow& _window) {
	// First draw the Game Board Grid Background
	_window.draw(this->m_levelGameBoard->m_gridBackground);

	// Draw each Square on the Game Board Grid and any Actors sitting on it
	for (int y = 0; y < this->m_levelGameBoard->m_gridSize.y; y++) { // Loop down the y-axis
		for (int x = 0; x < this->m_levelGameBoard->m_gridSize.x; x++) { // Loop down the x-axis
			// The Square
			Square* square = this->m_levelGameBoard->m_grid[y][x];
			_window.draw(square->m_squareShape); // Draw the Square Shape

			// If an Actor is sitting on this Square
			if (square->m_actorOnSquare != nullptr) {
				// Ensure that the Actor Sprite exists
				if (square->m_actorOnSquare->getActorSprite() != nullptr) {
					// Draw the Actor Sprite
					_window.draw(*(square->m_actorOnSquare->getActorSprite()));
				}
			}
		}
	}
}
