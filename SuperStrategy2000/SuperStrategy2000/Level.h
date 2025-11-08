/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Level.h
Description : Declares the Level Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Grid.h"

class Level {
public:
	int m_levelNumber;
	Grid* m_gameBoard;

	// Constructor and Destructor
	Level(int _levelNumber, sf::Vector2i _gridSize, sf::Vector2i _tileSize);
	~Level();
};

