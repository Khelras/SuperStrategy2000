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
#include <vector>
#include "Actor.h"

// Forward Declaration
class Ability;

class Unit : public Actor {
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
	float m_unitCurrentHealth; // Current Health of the Unit

	// Abilities
	std::vector<Ability*> m_unitAbilities;

public:
	// Turn Attributes
	bool m_hasMoved;
	bool m_hasAttacked;

	// Constructor and Destructor
	Unit();
	virtual ~Unit();

	// Getters
	std::string getUnitName() const { return this->m_unitName; };
	float getUnitStrength() const { return this->m_unitStrength; };
	float getUnitRange() const { return this->m_unitRange; };
	float getUnitDefense() const { return this->m_unitDefense; };
	float getUnitSpeed() const { return this->m_unitSpeed; };
	float getUnitMaxHeatlh() const { return this->m_unitHealth; };
	float getUnitCurrentHeatlh() const { return this->m_unitCurrentHealth; };
};

