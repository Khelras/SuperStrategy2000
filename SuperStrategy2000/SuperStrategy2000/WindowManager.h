#pragma once
#include <SFML/Graphics.hpp>

class WindowManager {
private:
	static WindowManager* m_instance; // Instance for Singleton

	sf::RenderWindow m_mainWindow;
	sf::RenderWindow m_debugWindow;

	// Make the Constructor and Destructors Private
	WindowManager(); // Constructor
	~WindowManager(); // Destructor

	// Delete the Copy Constructor and Assignment Operator
	WindowManager(const WindowManager&) = delete; // Copy Constructor
	WindowManager& operator=(const WindowManager&) = delete; // Assignment Operator

public:
	// Singleton Instance
	static WindowManager* getInstance(); // Returns the Singleton Instance

	// Window Manager Functions
	void process(); // Window Manager Process Loop

};