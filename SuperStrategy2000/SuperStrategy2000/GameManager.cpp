/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : GameManager.h
Description : Defines the GameManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "GameManager.h"
#include "GameSettings.h"

// Define the Static GameManager Instance
GameManager* GameManager::m_instance = nullptr;

GameManager::GameManager() {
    // Instantiate the Game Settings Singleton Instance
    GameSettings::getInstance();

    // Delta Time
    this->m_deltaTime = 0.0f;

    // Background Music Sound
    this->m_soundManager.playMusic("assets/sounds/bg/background.wav");
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
    // Clock to Measure Delta Time
    sf::Clock deltaClock;

    // Load Levels
    this->m_levelManager.loadLevel(1, "assets/levels/level1.txt");

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
            // Process UI Manager
            this->m_uiManager.process();

            // Process Level Manager
            this->m_levelManager.process();

            // Process Sound Manager
            this->m_soundManager.process();
        }

        // -------------------- Clear --------------------
        this->m_windowManager.clear(); // Clear
        // -------------------- Clear --------------------
        // -------------------- Draw --------------------
        // Draw World Objects
        this->m_cameraManager.processCameraView(); // Camera View
        this->m_windowManager.draw(); // Draw World Objects

        // Draw UI
        this->m_cameraManager.processUIView(); // UI View
        this->m_uiManager.drawUI(this->m_windowManager.m_mainWindow); // Draw UI
        // -------------------- Draw --------------------
        // -------------------- Display --------------------
        this->m_windowManager.display(); // Display
        // -------------------- Display --------------------
    }
}