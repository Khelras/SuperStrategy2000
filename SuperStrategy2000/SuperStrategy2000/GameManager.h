#pragma once
#include "GameSettings.h"
#include "EventManager.h"
#include "CameraManager.h"
#include "LevelManager.h"
#include "SoundManager.h"

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
	// Managers
	WindowManager m_windowManager; // Window Manager
	EventManager m_eventManager; // Event Manager
	CameraManager m_cameraManager; // Camera Manager
	LevelManager m_levelManager; // Level Manager
	SoundManager m_soundManager; // Sound Manager

	// Delta Time
	float m_deltaTime;

	// Getting Singleton Instance
	static GameManager* getInstance(); // Return the Singleton Instance

	// Game Manager Functions
	void process(); // Game Manager Process Loop
};

