/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Tile.cpp
Description : Defines the Tile Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Tile.h"

// Defining the Tile Size
const sf::Vector2i Tile::TILE_SIZE = sf::Vector2i(32, 32);

Tile::Tile(sf::Vector2i _tilePosition) {
	this->m_tilePosition = _tilePosition;
}

Tile::~Tile() {
}
