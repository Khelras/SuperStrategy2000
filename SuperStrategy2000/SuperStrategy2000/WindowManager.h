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
public:
	// Main and Debug Windows
	sf::RenderWindow m_mainWindow; // Main Window
	sf::RenderWindow m_debugWindow; // Debug Window

	// Constructor and Destructor
	WindowManager(); // Constructor
	~WindowManager(); // Destructor

	// Window Manager Functions
	bool process(); // Window Manager Process Loop
	void clear(); // Clear the Screen
	void draw(); // Draw to Screen
	void display(); // Display to Screen
};