#pragma once
#include "EventManager.h"

class GameManager {
private:
	static GameManager* m_instance;

	// Private Constructor and Destructor
	GameManager(); // Constructor
	~GameManager(); // Destructor

	// Deletes the Copy Consturctor and the Assignment Operator
	GameManager(const GameManager&) = delete; // Copy Constructor
	GameManager& operator=(const GameManager&) = delete; // Assignment Operator

public:
	// Getting Singleton Instance
	static GameManager* getInstance(); // Return the Singleton Instance

	// Game Manager Functions
	void process(); // Game Manager Process Loop
};

