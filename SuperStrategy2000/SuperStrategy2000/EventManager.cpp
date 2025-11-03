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
            }
        }
    }

    

    
}