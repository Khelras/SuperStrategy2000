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
    this->m_isShiftPressed = false;
}

EventManager::~EventManager() {
}

void EventManager::process(WindowManager& _windowManager) {
    // Windows
    sf::RenderWindow& mainWindow = _windowManager.m_mainWindow; // Main Window
    sf::RenderWindow& debugWindow = _windowManager.m_debugWindow; // Debug Window

    // Only Process Events if the Main Window is Open
    if (mainWindow.isOpen() == false) return;

    // -------------------- Debug Window is CLOSED --------------------
    if (debugWindow.isOpen() == false) {
        // Main Window Events
        while (const std::optional event = mainWindow.pollEvent()) {
            // Close Event
            if (event->is<sf::Event::Closed>()) {
                // Close Windows
                mainWindow.close();
                debugWindow.close();
            }

            // Mouse Pressed Events
            if (const auto mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                // Left-Button Mouse Pressed Event
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    // Pointer to the Game Board of the Current Selected Level
                    Grid* gameBoard = GameManager::getInstance()->m_levelManager.m_currentLevel->m_levelGameBoard;
                    gameBoard->clear(); // Clear the Grid

                    // Check if Mouse clicked on a Button UI
                    UIManager uiManager = GameManager::getInstance()->m_uiManager;
                    if (uiManager.isMouseOnUI() == true) { // Mouse IS hovering over UI
                        // Check if User clicked on a Button
                        Button* button = uiManager.getButtonFromMouse();
                        if (button != nullptr) { 
                            // Execute Button
                            button->execute();
                        }
                    }
                    else if (uiManager.isMouseOnUI() == false) { // Mouse is NOT hovering over UI
                        // If there is a pre-exisiting Selection
                        if (gameBoard->m_selectedSquare != nullptr) {
                            // Reset Selection
                            gameBoard->m_selectedSquare->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_DEFAULT);
                        }

                        // There is NO Square being Hovered
                        if (gameBoard->m_hoverSquare == nullptr) {
                            // Remove Selection
                            gameBoard->m_selectedSquare = nullptr;
                        }
                        // There IS a Square being Hovered
                        else if (gameBoard->m_hoverSquare != nullptr) {
                            // New Selection
                            gameBoard->m_selectedSquare = gameBoard->m_hoverSquare;
                            gameBoard->m_selectedSquare->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_SELECTED);
                        }
                    }
                }
            }

            // Keyboard Pressed Events
            if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                // Escape Key Pressed Event
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    // Open Debug Window
                    _windowManager.openDebugWindow();
                }
            }
        }
    }
    // -------------------- Debug Window is CLOSED --------------------
    // 
    // 
    // 
    // -------------------- Debug Window is OPEN --------------------
    else if (debugWindow.isOpen() == true) {
        // Main Window Event Processing (Only allow the Close Event)
        while (const std::optional event = mainWindow.pollEvent()) {
            // Close Event
            if (event->is<sf::Event::Closed>()) {
                // Close Windows
                mainWindow.close();
                debugWindow.close();
            }

            // Keyboard Pressed Events
            if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                // Escape Key Pressed Event
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    // Close Debug Window
                    _windowManager.closeDebugWindow();
                }
            }
        }

        // Debug Window Events
        while (const std::optional event = debugWindow.pollEvent()) {
            // Debug Window lost Focus
            if (event->getIf<sf::Event::FocusLost>()) {
                // Request Focus
                debugWindow.requestFocus();

                // Reset Shift Press
                this->m_isShiftPressed = false;
            }

            // Keyboard Pressed Events
            if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                // Escape Key Pressed Event
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    // Close Debug Window
                    _windowManager.closeDebugWindow();
                }

                // Enter Key Pressed Event
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
                    // Save Game Settings
                    if (GameSettings::getInstance()->saveGameSettings() == true) {
                        // Output to Console
                        std::cout << "Successfully Saved Settings!" << std::endl;
                    }
                }

                // Left-Shift Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::LShift) {
                    this->m_isShiftPressed = true;
                }

                // R Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::R) {
                    // Increase Resolution
                    if (this->m_isShiftPressed == false) {
                        // Ensure Increasing Resolution is Possible
                        if (_windowManager.m_currentResolution != std::prev(_windowManager.RESOLUTIONS.end())) {
                            // Increase Resolution
                            _windowManager.m_currentResolution++;
                        }
                    }
                    // Decrease Resolution
                    else if (this->m_isShiftPressed == true) {
                        // Ensure Decrease Resolution is Possible
                        if (_windowManager.m_currentResolution != _windowManager.RESOLUTIONS.begin()) {
                            // Decrease Resolution
                            _windowManager.m_currentResolution--;
                        }
                    }

                    // Change the Game Settings
                    GameSettings::getInstance()->m_windowX = static_cast<int>(_windowManager.m_currentResolution->x);
                    GameSettings::getInstance()->m_windowY = static_cast<int>(_windowManager.m_currentResolution->y);

                    // Print Resolution to the Console
                    std::cout << "Resolution: ";
                    std::cout << _windowManager.m_currentResolution->x << "x, ";
                    std::cout << _windowManager.m_currentResolution->y << "y" << std::endl;
                }

                // V Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::V) {
                    // Ternary
                    GameSettings::getInstance()->m_vsync = (this->m_isShiftPressed == false) ? true : false;

                    // Print V-Sync to the Console
                    std::cout << "V-Sync: ";
                    std::cout << (GameSettings::getInstance()->m_vsync == true) ? "True" : "False";
                    std::cout << std::endl;
                }

                // S Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
                    // Increase Master Volume
                    if (this->m_isShiftPressed == false) {
                        // Clamp to 100
                        if (GameSettings::getInstance()->m_masterVolume != 100) {
                            GameSettings::getInstance()->m_masterVolume++;
                        }
                    }
                    // Decrease Master Volume
                    else if (this->m_isShiftPressed == true) {
                        // Clamp to 0
                        if (GameSettings::getInstance()->m_masterVolume != 0) {
                            GameSettings::getInstance()->m_masterVolume--;
                        }
                    }

                    // Print Master Volume to Console
                    std::cout << "Master Volume: " << GameSettings::getInstance()->m_masterVolume;
                    std::cout << std::endl;
                }

                // E Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::E) {
                    // Increase Effects Volume
                    if (this->m_isShiftPressed == false) {
                        // Clamp to 100
                        if (GameSettings::getInstance()->m_effectsVolume != 100) {
                            GameSettings::getInstance()->m_effectsVolume++;
                        }
                    }
                    // Decrease Effects Volume
                    else if (this->m_isShiftPressed == true) {
                        // Clamp to 0
                        if (GameSettings::getInstance()->m_effectsVolume != 0) {
                            GameSettings::getInstance()->m_effectsVolume--;
                        }
                    }

                    // Print Effects Volume to Console
                    std::cout << "Effects Volume: " << GameSettings::getInstance()->m_effectsVolume;
                    std::cout << std::endl;
                }

                // M Key Pressed
                if (keyPressed->scancode == sf::Keyboard::Scancode::M) {
                    // Increase Music Volume
                    if (this->m_isShiftPressed == false) {
                        // Clamp to 100
                        if (GameSettings::getInstance()->m_musicVolume != 100) {
                            GameSettings::getInstance()->m_musicVolume++;
                        }
                    }
                    // Decrease Music Volume
                    else if (this->m_isShiftPressed == true) {
                        // Clamp to 0
                        if (GameSettings::getInstance()->m_musicVolume != 0) {
                            GameSettings::getInstance()->m_musicVolume--;
                        }
                    }

                    // Print Music Volume to Console
                    std::cout << "Music Volume: " << GameSettings::getInstance()->m_musicVolume;
                    std::cout << std::endl;
                }
            }

            // Key Released Event
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                // Left-Shift Key Released
                if (keyReleased->scancode == sf::Keyboard::Scancode::LShift) {
                    this->m_isShiftPressed = false;
                }
            }
        }
    }
    // -------------------- Debug Window is OPEN --------------------
}