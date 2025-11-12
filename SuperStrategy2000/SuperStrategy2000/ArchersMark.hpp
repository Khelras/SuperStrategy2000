/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : ArchersMark.hpp
Description : Declares and Defines the ArchersMark Class Functions and Properties. Derives from the Ability Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Ability.hpp"

class ArchersMark : public Ability {
public:
	// Constructor
	ArchersMark() {
		// Name and Description
		this->m_abilityName = "Archers's Might";
		this->m_abilityDescription =
			"Mark an enemy.\n"
			"The marked enemy will take double damage the next time they take damage.";

		// Ability Type
		Type m_abilityType = Type::ARCHER;

		// Ability Cooldown
		this->m_abilityCooldown = 5; // Ability can only be used after 3 Turns
		this->m_abilityCurrentCooldown = 5; // Player to can use Ability as soon as the game starts
	};

	// Virtual Destructor
	virtual ~ArchersMark() {};

	// Execute
	bool execute(Unit* _user, Unit* _target) override {
		// Ensure Target is not User
		if (_target != _user) {
			// Ensure Target is an Enemy
			if (_target->getActorType() == Actor::Type::UNIT_PLAYER_KNIGHT ||
				_target->getActorType() == Actor::Type::UNIT_PLAYER_ARCHER ||
				_target->getActorType() == Actor::Type::UNIT_PLAYER_MAGE) {
				// Mark the Target
				_target->m_isMarkedForDouble = true;

				// Ability Cooldown
				this->m_abilityCurrentCooldown = 0;

				// Ability was Successful
				return true;
			}
		}

		// Ability Failed
		return false;
	};
};

