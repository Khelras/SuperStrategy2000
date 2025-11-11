/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : BasicAttack.hpp
Description : Declares and Defines the BasicAttack Class Functions and Properties. Derives from the Ability Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Ability.hpp"

class BasicAttack : public Ability {
public:
	// Constructor
	BasicAttack() {
		// Name and Description
		this->m_abilityName = "Basic Attack";
		this->m_abilityDescription = "Simply attack an enemy.";
	};

	// Virtual Destructor
	virtual ~BasicAttack() {};

	// Execute
	bool execute(Unit* _user, Unit* _target) const override {
		// TODO: MAKE BASIC ATTACK

		return false;
	};
};

