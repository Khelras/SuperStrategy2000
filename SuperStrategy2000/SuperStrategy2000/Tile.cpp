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

// Defining the Static Constant Tile Color Attributes for ALL Tiles
const sf::Color Tile::TILE_FILLCOLOR_DEFAULT = sf::Color::Transparent;
const sf::Color Tile::TILE_FILLCOLOR_SELECTED = sf::Color::Green;
const sf::Color Tile::TILE_OUTLINECOLOR_DEFAULT = sf::Color::Black;
const sf::Color Tile::TILE_OUTLINECOLOR_SELECTED = sf::Color::Green;

// Defining the Statc Tile Size Attribute for ALL Tiles
sf::Vector2i Tile::TILE_SIZE = sf::Vector2i(32, 32); // Default to 32x32

Tile::Tile(sf::Vector2i _tilePosition) {
	// Tile Attributes
	sf::Vector2f tileSize = sf::Vector2f(static_cast<float>(Tile::TILE_SIZE.x), static_cast<float>(Tile::TILE_SIZE.y));
	this->m_tileShape.setSize(tileSize);
	this->m_tileShape.setFillColor(Tile::TILE_FILLCOLOR_DEFAULT); // Fill Color
	this->m_tileShape.setOutlineColor(Tile::TILE_OUTLINECOLOR_DEFAULT); // Outline Color
	this->m_tileShape.setOutlineThickness(-1.0f);

	// Tile Attributes
	this->m_tilePosition = _tilePosition;
}

Tile::~Tile() {
}
