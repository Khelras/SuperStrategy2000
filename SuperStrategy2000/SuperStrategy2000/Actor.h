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
	sf::Vector2i m_actorPositionOnGrid; // The Position of the Actor on the Grid
	sf::Sprite* m_actorSprite; // The Sprite of the Actor
	Actor::Type m_actorType; // The Type of the Actor

public:
	// Constructor and Destructor
	Actor(); // Default Constructor
	Actor(sf::Vector2i _positionOnGrid, Actor::Type _type); // Constructor
	virtual ~Actor(); // Virtual Destructor

	// Virtual Actor Position Functions
	virtual void setActorPositionOnGrid(sf::Vector2i _positionOnGrid); // Sets the Actor Position-On-Grid
	virtual const sf::Vector2i& getActorPositionOnGrid() const; // Returns the Actor Position-On-Grid

	// Virtual Actor Sprite Functions
	virtual void setActorSprite(unsigned int _index); // Sets the Actor Sprite
	virtual const sf::Sprite* getActorSprite() const; // Returns the Actor Sprite

	// Virtual Actor Type Functions
	virtual void setActorType(Actor::Type _type); // Sets the Actor Type
	virtual const Actor::Type& getActorType() const; // Returns the Actor Type

private:
	bool assertPositionOnGrid(sf::Vector2i _positionOnGrid); // Asserts a given Position-On-Grid
};

