#include "GameManager.h"

// Define the Static GameManager Instance
GameManager* GameManager::m_instance = nullptr;

GameManager::GameManager() {
}

GameManager::~GameManager() {
}

GameManager* GameManager::getInstance() {
    // If there is no Instance
    if (m_instance == nullptr) {
        // Create an Instance
        m_instance = new GameManager();
    }

    // Return the Singleton Instance
    return m_instance;
}

void GameManager::process() {
    // Game Loop based on Window Manager Process
    while (this->m_windowManager.process() == true) {
        // Process Events
        this->m_eventManager.process(this->m_windowManager);

        // -------------------- Clear --------------------
        // Clear using Window Manager
        this->m_windowManager.clear(); 
        // -------------------- Clear --------------------

        // -------------------- Draw --------------------
        // Draw the Game Board to the Center of the Main Window
        sf::RenderWindow& mainWindow = this->m_windowManager.m_mainWindow;
        float centerOffsetX = (mainWindow.getSize().x / 2) - (this->m_gameBoard.m_gridBackground.getSize().x / 2);
        float centerOffsetY = (mainWindow.getSize().y / 2) - (this->m_gameBoard.m_gridBackground.getSize().y / 2);
        this->m_gameBoard.m_gridBackground.setPosition(sf::Vector2f(centerOffsetX, centerOffsetY));
        mainWindow.draw(this->m_gameBoard.m_gridBackground);

        // Draw using Window Manager
        this->m_windowManager.draw(); 
        // -------------------- Draw --------------------

        // -------------------- Display 
        // Display using Window Manager
        this->m_windowManager.display(); 
        // -------------------- Display --------------------
    }
}