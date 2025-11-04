#include "Tile.h"

// Defining the Tile Size
const sf::Vector2i Tile::m_tileSize = sf::Vector2i(32.0f, 32.0f);

Tile::Tile(sf::Vector2i _tilePosition) {
	this->m_tilePosition = _tilePosition;
}

Tile::~Tile() {
}
