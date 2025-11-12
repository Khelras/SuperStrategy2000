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
	// Level Attributes
	unsigned int m_levelNumber;
	Grid* m_levelGameBoard;

	// Actor Attributes
	std::vector<Actor*> m_levelActors; // All Actors in the Level
	std::vector<Unit*> m_levelUnits; // All the Units in the Level

	// Constructor and Destructor
	Level(unsigned int _levelNumber, std::ifstream& _filePath);
	~Level();

	// Level Functions
	void process(); // Level Logic Loop
};

