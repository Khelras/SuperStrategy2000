#include "GameManager.h"

// Define the Static GameManager Instance
GameManager* GameManager::m_instance = nullptr;

GameManager::GameManager() {
    this->m_gameBoard = new Grid(sf::Vector2i(20, 20), sf::Vector2i(32, 32));
}

GameManager::~GameManager() {
    delete(this->m_gameBoard);
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
    // Top-Left Square --- REMOVE LATER ---
    sf::RectangleShape square({ 100, 100 });
    square.setPosition({ 0, 0 });
    square.setFillColor(sf::Color::Red);

    // Centers the Camera View relative to Game Board
    this->m_cameraManager.centerCameraView();

    // Game Loop based on Window Manager Process
    while (this->m_windowManager.process() == true) {
        // Process Events
        this->m_eventManager.process(this->m_windowManager);

        // Process Game Board
        this->m_gameBoard->process();

        // Camera View
        this->m_cameraManager.processCameraView();

        // Clear, Draw, and Display
        this->m_windowManager.clear(); // Clear
        this->m_windowManager.draw(); // Draw
        this->m_windowManager.m_mainWindow.draw(square); // --- REMOVE LATER ---
        this->m_windowManager.display(); // Display
    }
}