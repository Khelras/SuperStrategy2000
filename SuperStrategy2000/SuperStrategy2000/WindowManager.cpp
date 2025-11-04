/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : WindowManager.h
Description : Defines the WindowManager Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "WindowManager.h"
#include "GameManager.h"

WindowManager::WindowManager() {
    // Main Window
    this->m_mainWindow.create(sf::VideoMode({ 800, 600 }), "SFML works!");

    // Debug Window
    this->m_debugWindow.close();
}

WindowManager::~WindowManager() {
}

bool WindowManager::process() {
    // Allow Processing ONLF IF the Main Window is open
    if (this->m_mainWindow.isOpen() == true) {
        // Return True
        return true;
    }

    // Otherwise, Return False
    return false;
}

void WindowManager::clear() {
    // Clear the Main Window
    if (this->m_mainWindow.isOpen() == true) {
        this->m_mainWindow.clear();
    }

    // Clear the Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        this->m_debugWindow.clear();
    }
}

void WindowManager::draw() {
    // Draw to Main Window
    if (this->m_mainWindow.isOpen() == true) {
        // Draw the Game Board to the Center of the Main Window
        Grid& gameBoard = GameManager::getInstance()->m_gameBoard; // Game Board
        float centerOffsetX = (this->m_mainWindow.getSize().x / 2) - (gameBoard.m_gridBackground.getSize().x / 2); // Center Offset X
        float centerOffsetY = (this->m_mainWindow.getSize().y / 2) - (gameBoard.m_gridBackground.getSize().y / 2); // Center Offset Y
        gameBoard.m_gridBackground.setPosition(sf::Vector2f(centerOffsetX, centerOffsetY)); // Setting the Position of GameBoard to the Center
        this->m_mainWindow.draw(gameBoard.m_gridBackground);

        // Draw the Tiles of the Game Board
        for (int y = 0; y < gameBoard.GRID_SIZE_Y; y++) { // Loop down the y-axis
            for (int x = 0; x < gameBoard.GRID_SIZE_X; x++) { // Loop down the x-axis
                // The Tile
                Tile* tile = gameBoard.m_grid[y][x];

                // Calculating the World Position of the Tile base on the Position of the Game Board
                float relativeTilePositionX = static_cast<float>(tile->m_tilePosition.x) * tile->TILE_SIZE.x; // Relative X
                float relativeTilePositionY = static_cast<float>(tile->m_tilePosition.y) * tile->TILE_SIZE.y; // Relative Y
                float worldTilePositionX = gameBoard.m_gridBackground.getPosition().x + relativeTilePositionX; // World X
                float worldTilePositionY = gameBoard.m_gridBackground.getPosition().y + relativeTilePositionY; // World Y

                // Setting and Drawing the Tile Shape Position
                tile->m_tileShape.setPosition(sf::Vector2f(worldTilePositionX, worldTilePositionY));
                this->m_mainWindow.draw(tile->m_tileShape); // Draw the Tile Shape
            }
        }
    }

    // Draw to Debug Window
    if (this->m_debugWindow.isOpen() == true) {

    }
}

void WindowManager::display() {
    // Display to Main Window
    if (this->m_mainWindow.isOpen() == true) {
        this->m_mainWindow.display();
    }

    // Display to Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        this->m_debugWindow.display();
    }
}