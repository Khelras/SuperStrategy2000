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
}

Level::~Level() {
	// Ensure Game Board exists
	if (this->m_levelGameBoard != nullptr) {
		// Delete Game Board
		delete (this->m_levelGameBoard);
	}
}

void Level::process() {
	// Process the Game Board
	this->m_levelGameBoard->process();
}
