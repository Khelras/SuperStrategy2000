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

    // Apply Settings to Main Window
    sf::Vector2u resolution(settings->m_windowX, settings->m_windowY);
    this->m_mainWindow.create(sf::VideoMode(resolution), "Super Strategy 2000!");
    this->m_mainWindow.setVerticalSyncEnabled(settings->m_vsync);

    // Get the Current Resolution to match the Resolution of the Main Window
    for (this->m_currentResolution = this->RESOLUTIONS.begin();
        this->m_currentResolution != this->RESOLUTIONS.end();
        this->m_currentResolution++) {
        // Found matching Resolution
        if (this->m_currentResolution->x == settings->m_windowX &&
            this->m_currentResolution->y == settings->m_windowY) {
            // Break out of loop
            break;
        }
    }

    // If the Current Resolution Iterator reached the End
    if (this->m_currentResolution == this->RESOLUTIONS.end()) {
        // Go back to the Start
        this->m_currentResolution = this->RESOLUTIONS.begin();

        // Set the Resolution of the Main Window to this Current Resolution
        settings->m_windowX = this->m_currentResolution->x;
        settings->m_windowY = this->m_currentResolution->y;

        // Save Game Settings
        settings->saveGameSettings();
    }

    // Center Mouse and Clamp Cursor to Main Window
    sf::Mouse::setPosition(sf::Vector2i(settings->m_windowX / 2, settings->m_windowY / 2));
    this->m_mainWindow.setMouseCursorGrabbed(true); // Prevent Mouse from Exiting the Main Window

    // Debug Window
    this->m_debugWindow.close();

    // Debug Text
    if (this->m_debugFont.openFromFile("fonts/arial.ttf")) {
        // Font Loaded Successfully
        this->m_debugText = new sf::Text(this->m_debugFont);
        this->m_debugText->setCharacterSize(20); // Set Text Size to 20px
        this->m_debugText->setFillColor(sf::Color::White); // Set Text Color to White
        
        // Debug Text String
        std::string debugText =
            "Game Settings:\n"
            "[R] Increase Resolution\n"
            "[V] Enable V-Sync\n"
            "[S] Increase Master Volume\n"
            "[E] Increase Effects Volume\n"
            "[M] Increase Music Volume\n"
            "[SHIFT + ...] Inverts\n"
            "\n"
            "Press [ENTER] to Save Changes!\n"
            "Press [ESC] to Exit!";

        // Set the Debug Text to the Debug Text String
        this->m_debugText->setString(debugText);
    }
    else {
        // Loading Failed
        this->m_debugText = nullptr;
    }
}

WindowManager::~WindowManager() {
    // Ensure Debug Text Exists
    if (this->m_debugText != nullptr) {
        // Delete Debug Text
        delete(this->m_debugText);
        this->m_debugText = nullptr;
    }
}

bool WindowManager::process() {
    // Allow Processing ONLF IF the Main Window is open
    if (this->m_mainWindow.isOpen() == true) {
        // Only Process if Debug Window is Closed
        if (this->m_debugWindow.isOpen() == false) {
            // Game Settings
            GameSettings* settings = GameSettings::getInstance();

            // Apply Settings
            this->m_mainWindow.setSize(sf::Vector2u(settings->m_windowX, settings->m_windowY));
            this->m_mainWindow.setVerticalSyncEnabled(settings->m_vsync);
        }

        // Return True
        return true;
    }

    // Otherwise, Return False
    return false;
}

void WindowManager::clear() {
    // Clear the Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        this->m_debugWindow.clear();
        return; // Only Process Debug Window
    }

    // Clear the Main Window
    if (this->m_mainWindow.isOpen() == true) {
        this->m_mainWindow.clear();
    }
}

void WindowManager::draw() {
    // Draw to Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        // Ensure Debug Text Exists
        if (this->m_debugText != nullptr) {
            // Draw the Debug Text
            float textCenterX = (this->m_debugWindow.getSize().x - this->m_debugText->getLocalBounds().size.x) / 2.0f;
            float textCenterY = (this->m_debugWindow.getSize().y - this->m_debugText->getLocalBounds().size.y) / 2.0f;
            this->m_debugText->setPosition(sf::Vector2f(textCenterX, textCenterX));
            this->m_debugWindow.draw(*(this->m_debugText));
        }

        return; // Only Process Debug Window
    }

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
}

void WindowManager::display() {
    // Display to Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        this->m_debugWindow.display();
        return; // Only Process Debug Window
    }

    // Display to Main Window
    if (this->m_mainWindow.isOpen() == true) {
        this->m_mainWindow.display();
    }
}

void WindowManager::openDebugWindow() {
    // Create Debug Window
    this->m_debugWindow.create(sf::VideoMode({ 400, 400 }), "Super Debug 2000!", sf::Style::Titlebar);

    // Disable the Mouse Clamp to Main Window
    this->m_mainWindow.setMouseCursorGrabbed(false);

    // Move Debug Window to the right of Main Window
    sf::Vector2i mainWindowPosition = this->m_mainWindow.getPosition();
    sf::Vector2u mainWindowSize = this->m_mainWindow.getSize();
    this->m_debugWindow.setPosition(sf::Vector2i(mainWindowPosition.x + mainWindowSize.x, mainWindowPosition.y));
}

void WindowManager::closeDebugWindow() {
    // Close Debug Window
    this->m_debugWindow.close();

    // Request Focus to Main Window
    this->m_mainWindow.requestFocus();

    // Re-Center and Clamp the Mouse to Main Window
    GameSettings* settings = GameSettings::getInstance(); // Game Settings
    settings->loadGameSettings(); // Load Settings from File
    sf::Mouse::setPosition(sf::Vector2i(settings->m_windowX / 2, settings->m_windowY / 2));
    this->m_mainWindow.setMouseCursorGrabbed(true); // Prevent Mouse from Exiting the Main Window
}
