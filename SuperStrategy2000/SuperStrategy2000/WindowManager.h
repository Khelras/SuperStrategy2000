/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : WindowManager.h
Description : Declares the WindowManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iterator>

class WindowManager {
public:
	// List of Supported Resolutions
	const std::list<sf::Vector2f> RESOLUTIONS = {
		{ 640, 480 }, { 800, 600 }, { 1024, 768 },
		{ 1280, 720 }, { 1280, 960 }, { 1400, 1050 },
		{ 1600, 1200 }, { 1920, 1080 }
	};

	// Iterator for Current Resolution
	std::list<sf::Vector2f>::const_iterator m_currentResolution;

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
	void openDebugWindow(); // Open the Debug Window
	void closeDebugWindow(); // Close the Debug Window

private:
	// Debug Text
	sf::Font m_debugFont;
	sf::Text* m_debugText;
};