#include "GameManager.h"

// Define the Static GameManager Instance
GameManager* GameManager::m_instance = nullptr;

GameManager::GameManager() {
    // Instantiate the Game Settings Singleton Instance
    GameSettings::getInstance();

    // --- REMOVE LATER ---
    Level* testLevel = new Level(0, sf::Vector2i(20, 20), sf::Vector2i(32, 32));
    this->m_levelManager.m_levels.push_back(testLevel);
    this->m_levelManager.m_currentLevel = testLevel;
    // --- REMOVE LATER ---

    // Delta Time
    this->m_deltaTime = 0.0f;
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
    // Top-Left Square --- REMOVE LATER ---
    sf::RectangleShape square({ 100, 100 });
    square.setPosition({ 0, 0 });
    square.setFillColor(sf::Color::Red);
    // Top-Left Square --- REMOVE LATER ---

    // Clock to Measure Delta Time
    sf::Clock deltaClock;

    // Centers the Camera View relative to Game Board
    this->m_cameraManager.centerCameraView();

    // Game Loop based on Window Manager Process
    while (this->m_windowManager.process() == true) {
        // Delta Time
        this->m_deltaTime = deltaClock.restart().asSeconds();

        // Process Events
        this->m_eventManager.process(this->m_windowManager);

        // Allow Game Processes if Debug Window is Closed
        if (this->m_windowManager.m_debugWindow.isOpen() == false) {
            // Process Level Manager
            this->m_levelManager.process();
        }

        // -------------------- Clear --------------------
        this->m_windowManager.clear(); // Clear
        // -------------------- Clear --------------------
        // -------------------- Draw --------------------
        // Draw World Actors
        this->m_cameraManager.processCameraView(); // Camera View
        this->m_windowManager.draw(); // Draw
        this->m_windowManager.m_mainWindow.draw(square); // --- REMOVE LATER ---

        // Draw UI
        this->m_cameraManager.processUIView(); // UI View
        // -------------------- Draw --------------------
        // -------------------- Display --------------------
        this->m_windowManager.display(); // Display
        // -------------------- Display --------------------
    }
}