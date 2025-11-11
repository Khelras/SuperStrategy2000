/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Mage.cpp
Description : Defines the Mage Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Mage.h"
#include "MagesHeal.hpp"

Mage::Mage(bool _isEnemy) {
	// Set the Actor Sprite and the Actor Type
	if (_isEnemy == false) {
		// Player
		this->setActorSprite(4);
		this->setActorType(Actor::Type::UNIT_PLAYER_MAGE);
	}
	else if (_isEnemy == true) {
		// Enemy
		this->setActorSprite(7);
		this->setActorType(Actor::Type::UNIT_ENEMY_MAGE);
	}

	// Add Personal Ability
	this->m_unitAbilities.push_back(new MagesHeal());
}

Mage::~Mage() {
}
