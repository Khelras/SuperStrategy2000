#include "WindowManager.h"

// Defining the Static WindowManager Instance
WindowManager* WindowManager::m_instance = nullptr;

WindowManager::WindowManager() {
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
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}