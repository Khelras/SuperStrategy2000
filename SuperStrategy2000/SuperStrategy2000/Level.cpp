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

Level::Level(int _levelNumber, sf::Vector2i _gridSize, sf::Vector2i _tileSize) {
	this->m_levelNumber = _levelNumber;
	this->m_gameBoard = new Grid(_gridSize, _tileSize);
}

Level::~Level() {
	// Ensure Game Board exists
	if (this->m_gameBoard != nullptr) {
		// Delete Game Board
		delete (this->m_gameBoard);
	}
}
