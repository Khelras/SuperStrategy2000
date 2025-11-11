/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Ability.hpp
Description : Declares the Ability Abstract Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Unit.h"

class Ability {
protected:
	// Ability Attributes
	std::string m_abilityName;
	std::string m_abilityDescription;

public:
	// Constructor and Destructor
	Ability() {}; // Constructor
	virtual ~Ability() {}; // Virtual Destructor

	// Ability Functions
	virtual void execute(Unit* _user, Unit* _target) const = 0;

	// Getters
	const std::string& getAbilityName() const { return this->m_abilityName; };
	const std::string& getAbilityDescription() const { return this->m_abilityDescription; };
};

