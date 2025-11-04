#pragma once
#include <SFML/Graphics.hpp>

class Tile {
private:
	// Tile Attributes
	sf::Vector2i m_tilePosition;

public:
	// Static Constant Tile Size
	static const sf::Vector2i m_tileSize;

	// Constructor and Destructor
	Tile(sf::Vector2i _tilePosition); // Constructor
	~Tile(); // Destructor
};

