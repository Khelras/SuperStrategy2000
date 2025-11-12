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

// Defining the Static Constant Tile Map
const TileMap Actor::ACTOR_TILE_MAP = TileMap();

Actor::Actor() {
	// Default Attributes
	this->m_actorPositionOnGrid = sf::Vector2i(-1, -1); // Not on the Grid
	this->m_actorSprite = nullptr;
	this->m_actorType = Actor::Type::NONE;
}

Actor::Actor(sf::Vector2i _positionOnGrid, Actor::Type _type) {
	this->m_actorPositionOnGrid = _positionOnGrid;
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

void Actor::setActorPositionOnGrid(sf::Vector2i _positionOnGrid) {
	// Assert the given Position-On-Grid
	if (this->assertPositionOnGrid(_positionOnGrid) == true) {
		// Set the Actor Position-On-Grid
		this->m_actorPositionOnGrid = _positionOnGrid;
	}
}

const sf::Vector2i& Actor::getActorPositionOnGrid() const {
	return this->m_actorPositionOnGrid;
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

bool Actor::assertPositionOnGrid(sf::Vector2i _positionOnGrid) {
	// Ensure there is a Loaded Level
	const Level* const& level = GameManager::getInstance()->m_levelManager.m_currentLevel;
	if (level != nullptr) {
		// Assert the given Position-On-Grid
		const Grid* const& gameBoard = level->m_levelGameBoard;
		if ((_positionOnGrid.x >= 0 && _positionOnGrid.x < gameBoard->m_gridSize.x) ||
			(_positionOnGrid.y >= 0 && _positionOnGrid.y < gameBoard->m_gridSize.y)) {
			// Check if the Square on 'Position-On-Grid' already does NOT have an Actor sitting on it
			if (gameBoard->m_grid[_positionOnGrid.y][_positionOnGrid.x]->m_actorOnSquare == nullptr) {
				// Assert Passed
				return true;
			}
			// Assertion Failed
			else {
				// Error Message
				std::cerr << "An Actor already sits on the given 'Position-On-Grid'!'\n";
				return false;
			}
		}
		// Assertion Failed
		else {
			// Error Message
			std::cerr << "Invalid 'Position-On-Grid' was given!'\n";
			return false;
		}
	}
	// Assertion Failed
	else {
		// Error Message
		std::cerr << "There is no level present, unable to assert 'Position-On-Grid'!\n";
		return false;
	}
}
