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
    // Game Settings
    GameSettings* settings = GameSettings::getInstance();

    // Apply Settings
    sf::Vector2u resolution(settings->m_windowX, settings->m_windowY);
    this->m_mainWindow.create(sf::VideoMode(resolution), "Super Strategy 2000!");
    this->m_mainWindow.setVerticalSyncEnabled(settings->m_vsync);

    // Debug Window
    this->m_debugWindow.close();
}

WindowManager::~WindowManager() {
}

bool WindowManager::process() {
    // Allow Processing ONLF IF the Main Window is open
    if (this->m_mainWindow.isOpen() == true) {
        // Game Settings
        GameSettings* settings = GameSettings::getInstance();

        // Apply Settings
        this->m_mainWindow.setSize(sf::Vector2u(settings->m_windowX, settings->m_windowY));
        this->m_mainWindow.setVerticalSyncEnabled(settings->m_vsync);

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
        // Draw the Current Level
        Level* currentLevel = GameManager::getInstance()->m_levelManager.m_currentLevel; 
        Grid* gameBoard = currentLevel->m_gameBoard;
        this->m_mainWindow.draw(gameBoard->m_gridBackground); // Draw the Background of the Board

        // Draw the Tiles of the Game Board
        for (int y = 0; y < gameBoard->m_gridSize.y; y++) { // Loop down the y-axis
            for (int x = 0; x < gameBoard->m_gridSize.x; x++) { // Loop down the x-axis
                // The Tile
                Tile* tile = gameBoard->m_grid[y][x];

                // Calculating the World Position of the Tile base on the Position of the Game Board
                float relativeTilePositionX = static_cast<float>(tile->m_tilePosition.x) * tile->TILE_SIZE.x; // Relative X
                float relativeTilePositionY = static_cast<float>(tile->m_tilePosition.y) * tile->TILE_SIZE.y; // Relative Y
                float worldTilePositionX = gameBoard->m_gridBackground.getPosition().x + relativeTilePositionX; // World X
                float worldTilePositionY = gameBoard->m_gridBackground.getPosition().y + relativeTilePositionY; // World Y

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

void WindowManager::openDebugWindow() {
    // Create Debug Window
    this->m_debugWindow.create(sf::VideoMode({ 400, 400 }), "Super Debug 2000!");

    // Move Debug Window to the right of Main Window
    sf::Vector2i mainWindowPosition = this->m_mainWindow.getPosition();
    sf::Vector2u mainWindowSize = this->m_mainWindow.getSize();
    this->m_debugWindow.setPosition(sf::Vector2i(mainWindowPosition.x + mainWindowSize.x, mainWindowPosition.y));
}
