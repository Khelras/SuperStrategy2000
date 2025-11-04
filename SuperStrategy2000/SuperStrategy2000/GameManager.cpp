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

        // Process Game Boar
        this->m_gameBoard.process();

        // Clear, Draw, and Display
        this->m_windowManager.clear(); // Clear
        this->m_windowManager.draw(); // Draw
        this->m_windowManager.display(); // Display
    }
}