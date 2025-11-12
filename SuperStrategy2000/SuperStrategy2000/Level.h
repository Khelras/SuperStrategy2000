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
#include "Actor.h"

class Level {
public:
	// Level Attributes
	unsigned int m_levelNumber;
	Grid* m_levelGameBoard;
	std::vector<Actor*> _levelActors;

	// Constructor and Destructor
	Level(unsigned int _levelNumber, std::ifstream& _filePath);
	~Level();

	// Level Functions
	void process(); // Level Logic Loop
};

