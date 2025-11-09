/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Tile.h
Description : Declares the Tile Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tile {
public:
	// Static Constant Tile Color Attributes for ALL Tiles
	static const sf::Color TILE_FILLCOLOR_DEFAULT;
	static const sf::Color TILE_FILLCOLOR_SELECTED;
	static const sf::Color TILE_OUTLINECOLOR_DEFAULT;
	static const sf::Color TILE_OUTLINECOLOR_SELECTED;

	// Static Tile Size Attribute for ALL Tiles
	static sf::Vector2i TILE_SIZE;

	// Tile Attributes
	sf::Vector2i m_tilePosition;
	std::vector<Tile*> m_tileNeighbors;
	sf::RectangleShape m_tileShape;

	// Constructor and Destructor
	Tile(sf::Vector2i _tilePosition); // Constructor
	~Tile(); // Destructor
};

