/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : TileMap.cpp
Description : Defines the TileMap Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "TileMap.h"
#include "GameManager.h"
#include "GameSettings.h"

TileMap::TileMap() {
	// Load the Test Tile Map
	this->loadTileMap("assets/tilesets/test.png", 32);

	// Error Tile Texture
	sf::Image redImage({ 32, 32 }, sf::Color::Red); // Creates a Red 32x32 Image
	if (this->m_errorTexture.loadFromImage(redImage)); // Loads the Texture from the Red 16x16 Image
}

TileMap::TileMap(std::string _path, int _tileSides) {
	// Load Tile Map
	this->loadTileMap(_path, _tileSides, _tileSides);

	// Error Tile Texture
	sf::Image RedImage({ 32, 32 }, sf::Color::Red); // Creates a Red 32x32 Image
	if (this->m_errorTexture.loadFromImage(RedImage)); // Loads the Texture from the Red 16x16 Image
}

TileMap::TileMap(std::string _path, int _tileWidth, int _tileHeight) {
	// Load Tile Map
	this->loadTileMap(_path, _tileWidth, _tileHeight);

	// Error Tile Texture
	sf::Image RedImage({ 32, 32 }, sf::Color::Red); // Creates a Red 32x32 Image
	if (this->m_errorTexture.loadFromImage(RedImage)); // Loads the Texture from the Red 16x16 Image
}

TileMap::~TileMap() {
}

bool TileMap::loadTileMap(std::string _path, unsigned int _tileSides) {
	// Loading was Successful
	if (this->loadTileMap(_path, _tileSides, _tileSides) == true) {
		return true;
	}

	// Returns false otherwise (File Loading Failed)
	return false;
}

bool TileMap::loadTileMap(std::string _path, unsigned int _tileWidth, unsigned int _tileHeight) {
	// Validate Tile Map Texture successfully loads from File Path
	if (this->m_tileMapTexture.loadFromFile(_path)) {
		// Tile Map Attributes
		this->m_tileSize.x = _tileWidth;
		this->m_tileSize.y = _tileHeight;
		this->m_tileMapSize.x = this->m_tileMapTexture.getSize().x;
		this->m_tileMapSize.y = this->m_tileMapTexture.getSize().y;
		this->m_tileMapSizeInTiles.x = this->m_tileMapTexture.getSize().x / _tileWidth;
		this->m_tileMapSizeInTiles.y = this->m_tileMapTexture.getSize().y / _tileHeight;
		this->m_totalTiles = this->m_tileMapSizeInTiles.x * this->m_tileMapSizeInTiles.y;

		// Loading Successful
		this->m_hasLoadedTexture = true;
		return true;
	}

	// Returns false otherwise (File Loading Failed)
	return false;
}

sf::IntRect TileMap::getTile(unsigned int _x, unsigned int _y) const {
	// First check if a Tile Map has loaded and the given X and Y values are valid
	if (this->m_hasLoadedTexture && this->assertXY(_x, _y)) {
		// Return a FloatRect Section on the Tile Map
		return sf::IntRect(
			sf::Vector2i( // Position
				_x * static_cast<int>(this->m_tileSize.x),
				_y * static_cast<int>(this->m_tileSize.y)
			),
			sf::Vector2i( // Size
				static_cast<int>(this->m_tileSize.x),
				static_cast<int>(this->m_tileSize.y)
			)
		);
	}
	// There is no Loaded Texture
	else {
		// Return the Default
		return sf::IntRect(
			sf::Vector2i( // Position
				0, 0
			),
			sf::Vector2i( // Size
				static_cast<int>(this->m_tileSize.x),
				static_cast<int>(this->m_tileSize.y)
			)
		);
	}
}

sf::IntRect TileMap::getTile(unsigned int _n) const {
	// Convert to X and Y
	unsigned int tileX = _n % this->m_tileMapSize.x;
	unsigned int tileY = _n / this->m_tileMapSize.x;

	// Return using the GetTile() function and pass in the X and Y
	return this->getTile(tileX, tileY);
}

const sf::Texture& TileMap::getTileMapTexture() const {
	// If a Tile Map has been Loaded
	if (this->m_hasLoadedTexture == true) {
		return this->m_tileMapTexture;
	}

	// Otherwise, Return the Error Texture
	return this->m_errorTexture;
}

sf::Vector2u TileMap::getTileSize() const {
	return this->m_tileSize;
}

sf::Vector2u TileMap::getTileMapSize() const {
	return this->m_tileMapSize;
}

sf::Vector2u TileMap::getTileMapSizeInTiles() const {
	return this->m_tileMapSizeInTiles;
}

unsigned int TileMap::getTotalTiles() const {
	return this->m_totalTiles;
}

bool TileMap::assertXY(unsigned int _x, unsigned int _y) const {
	// Check if the given X and Y are within the Tile Map X and Y (in Terms of Tiles)
	if (_x < this->m_tileMapSizeInTiles.x && _y < this->m_tileMapSizeInTiles.y) {
		// Return true (Assertion successful)
		return true;
	}

	// Otherwise, Return False (Assertion failed)
	return false;
}
