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
#include "EventManager.h"

// Define the Static WindowManager Instance
WindowManager* WindowManager::m_instance = nullptr;

WindowManager::WindowManager() {
    // Main Window
    this->m_mainWindow.create(sf::VideoMode({ 800, 600 }), "SFML works!");

    // Debug Window
    this->m_debugWindow.close();
}

WindowManager::~WindowManager() {
}

WindowManager* WindowManager::getInstance() {
    // If there is no Instance
    if (m_instance == nullptr) {
        // Create an Instance
        m_instance = new WindowManager();
    }

    // Return the Singleton Instance
    return m_instance;
}

void WindowManager::process() {
    // Simple Green Circle Shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Main Window Loop
    while (this->m_mainWindow.isOpen()) {
        // Main Window Event Loop
        EventManager::getInstance()->processMainEvents();

        // Clear, Draw, and Display to Main Window
        this->m_mainWindow.clear(); // Clear
        this->m_mainWindow.draw(shape); // Draw
        this->m_mainWindow.display(); // Display
    }
}