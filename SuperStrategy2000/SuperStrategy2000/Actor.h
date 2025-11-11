/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Actor.h
Description : Declares the Actor Abstract Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "TileMap.h"

#pragma once
class Actor {
public:
	// Static Constant Tile Map
	static const TileMap ACTOR_TILE_MAP;

	// The Different Types of Actors
	enum class Type {
		// Static Actors
		NONE = 0,
		OBSTACLE = 1,
		// Player Units
		UNIT_PLAYER_KNIGHT = 2,
		UNIT_PLAYER_ARCHER = 3,
		UNIT_PLAYER_MAGE = 4,
		// Enemy Units
		UNIT_ENEMY_KNIGHT = 5,
		UNIT_ENEMY_ARCHER = 6,
		UNIT_ENEMY_MAGE = 7
	};

protected:
	// Actor Attributes
	sf::Vector2f m_actorPosition; // The Position of the Actor
	sf::Sprite* m_actorSprite; // The Sprite of the Actor
	Actor::Type m_actorType; // The Type of the Actor

public:
	// Constructor and Destructor
	Actor(); // Default Constructor
	Actor(sf::Vector2f _position, Actor::Type _type); // Constructor
	virtual ~Actor(); // Virtual Destructor

	// Virtual Actor Position Functions
	virtual void setActorPosition(sf::Vector2f _position); // Sets the Actor Position
	virtual const sf::Vector2f& getActorPosition() const; // Returns the Actor Position

	// Virtual Actor Sprite Functions
	virtual void setActorSprite(unsigned int _index); // Sets the Actor Sprite
	virtual const sf::Sprite* getActorSprite() const; // Returns the Actor Sprite

	// Virtual Actor Type Functions
	virtual void setActorType(Actor::Type _type); // Sets the Actor Type
	virtual const Actor::Type& getActorType() const; // Returns the Actor Type
};

