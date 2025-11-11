/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : KnightsMight.hpp
Description : Declares and Defines the KnightsMight Class Functions and Properties. Derives from the Ability Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Ability.hpp"

class KnightsMight : public Ability {
public:
	// Constructor
	KnightsMight() {
		// Name and Description
		this->m_abilityName = "Knight's Might";
		this->m_abilityDescription =
			"Defend an ally.\n"
			"Take the damage they were supposed to take and deal it to you instead.\n"
			"The damage absorbed will be halved.\n";

		// Ability Cooldown
		this->m_abilityCooldown = 3; // Ability can only be used after 3 Turns
		this->m_abilityCurrentCooldown = 3; // Player to can use Ability as soon as the game starts
	};

	// Virtual Destructor
	virtual ~KnightsMight() {};

	// Execute
	bool execute(Unit* _user, Unit* _target) const override {
		// TODO: MAKE KNIGHTS MIGHT
		return false;
	};
};

