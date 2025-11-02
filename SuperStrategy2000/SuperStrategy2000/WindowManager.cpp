#include "WindowManager.h"

// Defining the Static WindowManager Instance
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
    // Simple Grean Circle Shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Main Window Loop
    while (this->m_mainWindow.isOpen()) {
        // Main Window Event Loop
        while (const std::optional event = this->m_mainWindow.pollEvent()) {
            // When the Main Window is Closed
            if (event->is<sf::Event::Closed>()) {
                this->m_mainWindow.close();
            }
        }

        // Clear, Draw, and Display to Main Window
        this->m_mainWindow.clear(); // Clear
        this->m_mainWindow.draw(shape); // Draw
        this->m_mainWindow.display(); // Display
    }
}