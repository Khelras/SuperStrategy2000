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
#include "BasicAttack.hpp" // Forward Declaration

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
	this->m_unitCurrentHealth = this->m_unitHealth; // Current Health of the Unit

	// Add the Basic Attack Ability
	this->m_unitAbilities.push_back(new BasicAttack());

	// Marked for Double Damage
	this->m_isMarkedForDouble = false;
}

Unit::~Unit() {
	// Loop through the Abilites
	for (auto& ability : this->m_unitAbilities) {
		// Ensure Ability exists
		if (ability != nullptr) {
			// Delete Ability
			delete (ability);
			ability = nullptr;
		}
	}
}

void Unit::updateAbilityCooldowns() {
	for (auto& ability : this->m_unitAbilities) {
		ability->updateCooldown();
	}
}

void Unit::damageUnit(float _damage) {
	// Check if this Unit will die from this
	if (this->m_unitCurrentHealth - _damage <= 0) {
		this->m_unitCurrentHealth = 0;
	}
	else if (this->m_unitCurrentHealth - _damage > 0) {
		this->m_unitCurrentHealth -= _damage;
	}
}

void Unit::healUnit(float _heal) {
	// Check if the Heal amount is greater than the Max Health
	if (this->m_unitCurrentHealth + _heal > this->m_unitHealth) {
		this->m_unitCurrentHealth = this->m_unitHealth;
	}
	else if (this->m_unitCurrentHealth + _heal <= this->m_unitHealth) {
		this->m_unitCurrentHealth += _heal;
	}
}
