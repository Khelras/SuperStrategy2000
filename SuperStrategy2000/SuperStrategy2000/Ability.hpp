/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Ability.hpp
Description : Declares and Defines the Ability Abstract Class Functions and Properties.
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
	unsigned int m_abilityCooldown = 0;
	unsigned int m_abilityCurrentCooldown = 0;

public:
	// Constructor and Destructor
	Ability() {}; // Constructor
	virtual ~Ability() {}; // Virtual Destructor

	// Ability Execute Function
	virtual void execute(Unit* _user, Unit* _target) const = 0;

	// Getters
	const std::string& getAbilityName() const { return this->m_abilityName; };
	const std::string& getAbilityDescription() const { return this->m_abilityDescription; };
	const unsigned int& getAbilityCooldown() const { return this->m_abilityCooldown; };
	const unsigned int& getAbilityCurrentCooldown() const { return this->m_abilityCurrentCooldown; };

	// Update Cooldown
	void updateCooldown() {
		// Check if Current Cooldown is lesser than Cooldown
		if (this->m_abilityCurrentCooldown < this->m_abilityCooldown) {
			// Increase Current Cooldown
			this->m_abilityCurrentCooldown++;
		}
	};
};

