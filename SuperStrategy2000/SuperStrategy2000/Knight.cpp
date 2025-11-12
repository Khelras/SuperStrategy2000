/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Knight.cpp
Description : Defines the Knight Class Functions and Properties. Derives from the Unit Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Knight.h"
#include "KnightsMight.hpp"

Knight::Knight(bool _isEnemy) {
	// Set the Unit Stats
	this->m_unitStrength = 10.0f; // Strength of the Unit
	this->m_unitRange = 1.0f; // Attack Range of the Unit
	this->m_unitDefense = 5.0f; // Defense of the Unit
	this->m_unitSpeed = 5.0f; // Movement Speed of the Unit
	this->m_unitHealth = 40.0f; // Health of the unit
	this->m_unitCurrentHealth = this->m_unitHealth;

	// Set the Actor Sprite and the Actor Type
	if (_isEnemy == false) {
		// Player
		this->m_unitName = "Player Knight";
		this->setActorSprite(2);
		this->setActorType(Actor::Type::UNIT_PLAYER_KNIGHT);
	}
	else if (_isEnemy == true) {
		// Enemy
		this->m_unitName = "Enemy Knight";
		this->setActorSprite(5);
		this->setActorType(Actor::Type::UNIT_ENEMY_KNIGHT);
	}

	// Add Personal Ability
	this->m_unitAbilities.push_back(new KnightsMight());
}

Knight::~Knight() {
}
