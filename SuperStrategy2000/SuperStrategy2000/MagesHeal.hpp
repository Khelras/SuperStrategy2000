/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : MagesHeal.hpp
Description : Declares and Defines the MagesHeal Class Functions and Properties. Derives from the Ability Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Ability.hpp"
#include "Mage.h"

class MagesHeal : public Ability {
public:
	// Constructor
	MagesHeal() {
		// Name and Description
		this->m_abilityName = "Mage's Heal";
		this->m_abilityDescription =
			"Heal yourself, or another ally unit.\n"
			"Based on your ATK and DEF stats.\n"
			"Heal = ATK + DEF";

		// Ability Type
		Type m_abilityType = Type::MAGE;

		// Ability Cooldown
		this->m_abilityCooldown = 3; // Ability can only be used after 3 Turns
		this->m_abilityCurrentCooldown = 3; // Player to can use Ability as soon as the game starts
	};

	// Virtual Destructor
	virtual ~MagesHeal() {};

	// Execute
	bool execute(Unit* _user, Unit* _target) override {
		if (this->m_abilityCurrentCooldown != this->m_abilityCooldown) {
			std::cout << "Mage's Heal on Cooldown! ";
			std::cout << this->m_abilityCurrentCooldown << "/" << this->m_abilityCooldown;
			std::cout << std::endl;
			return false;
		}

		// Target is NOT itself
		if (_target != _user) {
			// Target is an Ally
			if (_target->getActorType() == Actor::Type::UNIT_PLAYER_KNIGHT || 
				_target->getActorType() == Actor::Type::UNIT_PLAYER_ARCHER || 
				_target->getActorType() == Actor::Type::UNIT_PLAYER_MAGE ) {
				// Downcast User to Mage
				Mage* mage = dynamic_cast<Mage*>(_user);

				// Heal the target based on the Mages Strength and Defense Stats
				_target->healUnit(mage->getUnitStrength() * mage->getUnitDefense());

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

