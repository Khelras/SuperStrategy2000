/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Mage.h
Description : Declares the Mage Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Unit.h"

class Mage : public Unit {
public:
	// Constructor and Destructor
	Mage(bool _isEnemy = false); // Constructor
	virtual ~Mage(); // Virtual Destructor
};

