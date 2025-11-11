/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : TileMap.h
Description : Declares the TileMap Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>

class TileMap {
private:
	// Tile Map Attributes
	sf::Texture m_tileMapTexture; // Tile Map Texture
	sf::Texture m_errorTexture; // Red Square Tile Texture (For Errors)
	sf::Vector2u m_tileSize; // The Size of a Single Tile
	sf::Vector2u m_tileMapSize; // The Size of the Tile Map
	sf::Vector2u m_tileMapSizeInTiles; // The Size of the Tile Map in terms of Tiles
	unsigned int m_totalTiles; // Total Number of Tiles within the Tile map
	bool m_hasLoadedTexture; // If a Tile Map Texture has been Loaded

public:
	// Constructor and Destructor
	TileMap(); // Default Constructor;
	TileMap(std::string _path, int _tileSides); // Constructor given a Path and Tile Sides (Square Tiles)
	TileMap(std::string _path, int _tileWidth, int _tileHeight); // Constructor given a Path and Tile Height and Width
	~TileMap();

	// Tile Map Functions
	bool loadTileMap(std::string _path, unsigned int _tileSides); // Load Tile Map given a Path and Tiles Sides (Square Tiles)
	bool loadTileMap(std::string _path, unsigned int _tileWidth, unsigned int _tileHeight); // Load Tile Map given a Path and Tile Height and Width
	sf::IntRect getTile(unsigned int _x, unsigned int _y) const; // Get the Tile from Tile Map given the X and Y (0-Index)
	sf::IntRect getTile(unsigned int _n) const; // Get the n'th Tile from Tile Map given N (0-Index)

	// Getters
	const sf::Texture& getTileMapTexture() const; // Returns the Tile Map Texture
	sf::Vector2u getTileSize() const; // Returns the Size of the Tile
	sf::Vector2u getTileMapSize() const; // Returns the Size of the Tile Map
	sf::Vector2u getTileMapSizeInTiles() const; // Returns the Size of Tile Map in terms of Tiles
	unsigned int getTotalTiles() const; // Returns the Total number of Tiles

private:
	// Private Helper Functions
	bool assertXY(unsigned int _x, unsigned int _y) const; // Ensures that X and Y values were given are valid (0-Index)
};

