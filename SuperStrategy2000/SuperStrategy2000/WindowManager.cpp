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

WindowManager::WindowManager() {
    // Main Window
    this->m_mainWindow.create(sf::VideoMode({ 800, 600 }), "SFML works!");

    // Debug Window
    this->m_debugWindow.close();
}

WindowManager::~WindowManager() {
}

bool WindowManager::process() {
    // Allow Processing ONLF IF the Main Window is open
    if (this->m_mainWindow.isOpen() == true) {
        // Return True
        return true;
    }

    // Otherwise, Return False
    return false;
}

void WindowManager::clear() {
    // Main Window
    if (this->m_mainWindow.isOpen() == true) {
        // Clear the Main Window
        this->m_mainWindow.clear();
    }

    // Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        // Clear the Debug Window
        this->m_debugWindow.clear();
    }
}

void WindowManager::draw() {
    // Main Window
    if (this->m_mainWindow.isOpen() == true) {
        // Draw to Main Window

    }

    // Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        // Draw to Debug Window

    }
}

void WindowManager::display() {
    // Main Window
    if (this->m_mainWindow.isOpen() == true) {
        // Display to Main Window
        this->m_mainWindow.display();
    }

    // Debug Window
    if (this->m_debugWindow.isOpen() == true) {
        // Display to Debug Window
        this->m_debugWindow.display();
    }
}