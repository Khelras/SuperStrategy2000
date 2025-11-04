/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : EventManager.cpp
Description : Defines the EventManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "EventManager.h"
#include "GameManager.h"

EventManager::EventManager() {
}

EventManager::~EventManager() {
}

void EventManager::process(WindowManager& _windowManager) {
    // Windows
    sf::RenderWindow& mainWindow = _windowManager.m_mainWindow; // Main Window
    sf::RenderWindow& debugWindow = _windowManager.m_debugWindow; // Debug Window

    // Only Process Events if the Main Window is Open
    if (mainWindow.isOpen() == true) {
        // If the Debug Window is Open
        if (debugWindow.isOpen() == true) {
            // Main Window Event Processing (Only allow the Close Event)
            while (const std::optional event = mainWindow.pollEvent()) {
                // Close Event
                if (event->is<sf::Event::Closed>()) {
                    // Close Debug Window
                    mainWindow.close();
                }
            }

            // Debug Window Events
            while (const std::optional event = debugWindow.pollEvent()) {
                // Close Event
                if (event->is<sf::Event::Closed>()) {
                    // Close Debug Window
                    debugWindow.close();
                }
            }
        }
        // If the Debug Window is Closed
        else if (debugWindow.isOpen() == false) {
            // Main Window Events
            while (const std::optional event = mainWindow.pollEvent()) {
                // Close Event
                if (event->is<sf::Event::Closed>()) {
                    // Close Debug Window
                    mainWindow.close();
                }

                // Mouse Pressed Events
                if (const auto mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                    // Left-Button Mouse Pressed Event
                    if (mousePressed->button == sf::Mouse::Button::Left) {
                        // Refernece to Game Board
                        Grid& gameBoard = GameManager::getInstance()->m_gameBoard;

                        // If there is a pre-exisiting Selection
                        if (gameBoard.m_selectedTile != nullptr) {  
                            // Reset Selection
                            gameBoard.m_selectedTile->m_tileShape.setFillColor(Tile::TILE_FILLCOLOR_DEFAULT);
                        }

                        // There is NO Tile being Hovered
                        if (gameBoard.m_hoverTile == nullptr) {
                            // Remove Selection
                            gameBoard.m_selectedTile = nullptr;
                        }
                        // There IS a Tile being Hovered
                        else if (gameBoard.m_hoverTile != nullptr) {
                            // New Selection
                            gameBoard.m_selectedTile = gameBoard.m_hoverTile;
                            gameBoard.m_selectedTile->m_tileShape.setFillColor(Tile::TILE_FILLCOLOR_SELECTED);
                        }
                    }
                }
            }
        }
    }

    

    
}