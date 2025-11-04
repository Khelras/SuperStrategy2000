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

// Defining the Static Constant Tile Size
const sf::Vector2i Tile::TILE_SIZE = sf::Vector2i(32, 32);

Tile::Tile(sf::Vector2i _tilePosition) {
	// Tile Attributes
	this->m_tileShape.setSize(sf::Vector2f(this->TILE_SIZE.x, this->TILE_SIZE.y));
	this->m_tileShape.setFillColor(sf::Color::Transparent); // Fill Color
	this->m_tileShape.setOutlineColor(sf::Color::Black); // Outline Color
	this->m_tileShape.setOutlineThickness(1.0f);

	// Tile Attributes
	this->m_tilePosition = _tilePosition;
}

Tile::~Tile() {
}
