/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Archer.cpp
Description : Defines the Archer Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Archer.h"
#include "ArchersMark.hpp"

Archer::Archer(bool _isEnemy) {
	// Set the Actor Sprite and the Actor Type
	if (_isEnemy == false) {
		// Player
		this->setActorSprite(3);
		this->setActorType(Actor::Type::UNIT_PLAYER_ARCHER);
	}
	else if (_isEnemy == true) {
		// Enemy
		this->setActorSprite(6);
		this->setActorType(Actor::Type::UNIT_ENEMY_ARCHER);
	}

	// Add Personal Ability
	this->m_unitAbilities.push_back(new ArchersMark());
}

Archer::~Archer() {
}
