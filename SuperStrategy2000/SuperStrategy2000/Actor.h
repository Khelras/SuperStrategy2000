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
protected:
	// Actor Attributes
	sf::Vector2f m_actorPosition;
	sf::Sprite* m_actorSprite;

public:
	// Static Constant Tile Map
	static const TileMap ACTOR_TILE_MAP;

	// The Different Types of Actors
	enum class Type {
		NONE = 0,
		OBSTACLE = 1,
		UNIT = 2,
	};
	
	// Constructor and Destructor
	Actor(); // Default Constructor
	Actor(sf::Vector2f _position); // Constructor
	virtual ~Actor(); // Virtual Destructor

	// Virtual Actor Position Functions
	virtual void setActorPosition(sf::Vector2f _position); // Sets the Actor Position
	virtual const sf::Vector2f& getActorPosition() const; // Returns the Actor Position

	// Virtual Actor Sprite Functions
	virtual void setActorSprite(unsigned int _index); // Sets the Actor Sprite
	virtual const sf::Sprite* getActorSprite() const; // Returns the Actor Sprite
};

