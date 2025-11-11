/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Unit.h
Description : Declares the Unit Abstract Class Functions and Properties. Derives from the Actor Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <string>
#include "Actor.h"

class Unit {
protected:
	// Unit Attributes
	std::string m_unitName; // Name of the Unit
	std::string m_unitDescription; // Description of the Unit

	// Base Unit Stats
	float m_unitStrength; // Strength of the Unit
	float m_unitRange; // Attack Range of the Unit
	float m_unitDefense; // Defense of the Unit
	float m_unitSpeed; // Movement Speed of the Unit
	float m_unitHealth; // Health of the unit

	// Dynamic Unit Stats
	float m_unitRemainingSpeed; // Remaining Movement Speed of a Unit
	float m_unitCurrentHealth; // Current Health of the Unit

public:
	// Constructor and Destructor
	Unit();
	virtual ~Unit();
};

