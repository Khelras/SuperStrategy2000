/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Actor.cpp
Description : Defines the Actor Abstract Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Actor.h"
#include "GameManager.h"
#include "GameSettings.h"

Actor::Actor() {
	// Default Attributes
	this->m_actorPosition = sf::Vector2f(0.0f, 0.0f);
	this->m_actorSprite = nullptr;
}

Actor::Actor(sf::Vector2f _position) {
	this->m_actorPosition = _position;
	this->m_actorSprite = nullptr;
}

Actor::~Actor() {
	// Ensure that Actor Sprite exists
	if (this->m_actorSprite != nullptr) {
		// Delete Actor Sprite
		delete (this->m_actorSprite);
		this->m_actorSprite = nullptr;
	}
}

void Actor::setActorPosition(sf::Vector2f _position) {
	// Set the Actor Position
	this->m_actorPosition = _position;
	
	// Ensure that Actor Sprite exists
	if (this->m_actorSprite != nullptr) {
		// Set the Actor Sprite Position
		this->m_actorSprite->setPosition(_position);
	}
}

const sf::Vector2f& Actor::getActorPosition() const {
	return this->m_actorPosition;
}

void Actor::setActorSprite(sf::Vector2u _tile) {
}
