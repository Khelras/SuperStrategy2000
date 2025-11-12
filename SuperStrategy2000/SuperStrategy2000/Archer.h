/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Archer.h
Description : Declares the Archer Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Unit.h"

class Archer : public Unit {
public:
	// Constructor and Destructor
	Archer(bool _isEnemy = false); // Constructor
	virtual ~Archer(); // Virtual Destructor
};

