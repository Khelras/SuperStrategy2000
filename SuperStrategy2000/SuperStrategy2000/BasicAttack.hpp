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
#include "DebugSettings.h"

class BasicAttack : public Ability {
public:
	// Constructor
	BasicAttack() {
		// Name and Description
		this->m_abilityName = "Basic Attack";
		this->m_abilityDescription = "Simply attack an enemy.";
	};

	// Ability Type
	Type m_abilityType = Type::BASIC;

	// Virtual Destructor
	virtual ~BasicAttack() {};

	// Execute
	bool execute(Unit* _user, Unit* _target) override {
		// Ensure Target is not User
		if (_target != _user) {
			// Ensure Target is an Enemy
			if (_target->getActorType() == Actor::Type::UNIT_ENEMY_KNIGHT ||
				_target->getActorType() == Actor::Type::UNIT_ENEMY_ARCHER ||
				_target->getActorType() == Actor::Type::UNIT_ENEMY_MAGE) {
				// Calculate Damage (Strength of User minus Defense of Target)
				float damage = _user->getUnitStrength() - _target->getUnitDefense();
				if (damage < 0) damage = 0; // Clamp to 0

				// Check if Target is Marked
				if (_target->m_isMarkedForDouble) {
					damage += damage; // Double Damage
					_target->m_isMarkedForDouble = false;
				}

				// Check if Force One-Shot was Enabled
				if (DebugSettings::getInstance()->m_oneShot == true) {
					damage = 10000;
				}

				// Deal Damage to Target
				_target->damageUnit(damage);

				// Ability was Successful
				return true;
			}
		}

		// Ability Failed
		return false;
	};
};

