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
}

void Level::process() {
	// Update all Actor Positions
	this->m_levelGameBoard->updateActorGridPositions();

	// Game Board Grid Process Loop
	this->m_levelGameBoard->process();
}
