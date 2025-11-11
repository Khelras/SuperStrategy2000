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

// Defining the Static Constant Tile Map
const TileMap Actor::ACTOR_TILE_MAP = TileMap();

Actor::Actor() {
	// Default Attributes
	this->m_actorPosition = sf::Vector2f(0.0f, 0.0f);
	this->m_actorSprite = nullptr;
	this->m_actorType = Actor::Type::NONE;
}

Actor::Actor(sf::Vector2f _position, Actor::Type _type) {
	this->m_actorPosition = _position;
	this->m_actorSprite = nullptr;
	this->m_actorType = _type;
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

void Actor::setActorSprite(unsigned int _index) {
	// If Actor Sprite DOES Exist
	if (this->m_actorSprite != nullptr) {
		// ONLY Set the TextureRect
		this->m_actorSprite->setTextureRect(
			Actor::ACTOR_TILE_MAP.getTile(_index) // Set the TextureRect given the Tile Index
		);
	}
	// If Actor Sprite does NOT Exist
	else if (this->m_actorSprite == nullptr) {
		// Create a new Actor Sprite
		this->m_actorSprite = new sf::Sprite(
			Actor::ACTOR_TILE_MAP.getTileMapTexture(), // Set the Texture
			Actor::ACTOR_TILE_MAP.getTile(_index) // Set the TextureRect given the Tile Index
		);
	}
}

const sf::Sprite* Actor::getActorSprite() const {
	return this->m_actorSprite;
}

void Actor::setActorType(Actor::Type _type) {
	this->m_actorType = _type;
}

const Actor::Type& Actor::getActorType() const {
	return this->m_actorType;
}
