/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : WindowManager.h
Description : Declares the WindowManager Class Functions and Properties. Uses a Singleton Design Pattern.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>

class WindowManager {
private:
	static WindowManager* m_instance; // Instance for Singleton

	// Make the Constructor and Destructors Private
	WindowManager(); // Constructor
	~WindowManager(); // Destructor

	// Delete the Copy Constructor and Assignment Operator
	WindowManager(const WindowManager&) = delete; // Copy Constructor
	WindowManager& operator=(const WindowManager&) = delete; // Assignment Operator

public:
	// Main and Debug Windows
	sf::RenderWindow m_mainWindow; // Main Window
	sf::RenderWindow m_debugWindow; // Debug Window

	// Getting the Singleton Instance
	static WindowManager* getInstance(); // Returns the Singleton Instance

	// Window Manager Functions
	void process(); // Window Manager Process Loop
};