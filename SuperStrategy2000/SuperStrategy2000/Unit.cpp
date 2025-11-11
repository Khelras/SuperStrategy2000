/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Unit.cpp
Description : Defines the Unit Abstract Class Functions and Properties. Derives from the Actor Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Unit.h"

Unit::Unit() {
	// Unit Attributes
	this->m_unitName = "Base Unit";
	this->m_unitDescription = "The Base Unit.";

	// Base Unit Stats (Default to -1)
	this->m_unitStrength = -1.0f; // Strength of the Unit
	this->m_unitRange = -1.0f; // Attack Range of the Unit
	this->m_unitDefense = -1.0f; // Defense of the Unit
	this->m_unitSpeed = -1.0f; // Movement Speed of the Unit
	this->m_unitHealth = -1.0f; // Health of the unit

	// Dynamic Unit Stats
	this->m_unitRemainingSpeed = this->m_unitSpeed; // Remaining Movement Speed of a Unit
	this->m_unitCurrentHealth = this->m_unitHealth; // Current Health of the Unit
}

Unit::~Unit() {
}
