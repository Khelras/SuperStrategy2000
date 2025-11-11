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
	// Set the Actor Sprite and the Actor Type
	if (_isEnemy == false) {
		// Player
		this->setActorSprite(2);
		this->setActorType(Actor::Type::UNIT_PLAYER_KNIGHT);
	}
	else if (_isEnemy == true) {
		// Enemy
		this->setActorSprite(5);
		this->setActorType(Actor::Type::UNIT_ENEMY_KNIGHT);
	}

	// Add Personal Ability
	this->m_unitAbilities.push_back(new KnightsMight());
}

Knight::~Knight() {
}
