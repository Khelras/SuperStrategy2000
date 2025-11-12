/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Knight.h
Description : Declares the Knight Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Unit.h"

class Knight : public Unit {
public:
	// Constructor and Destructor
	Knight(bool _isEnemy = false); // Constructor
	virtual ~Knight(); // Virtual Destructor
};

