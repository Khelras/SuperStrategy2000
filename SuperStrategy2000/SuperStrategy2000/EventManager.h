/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : EventManager.h
Description : Declares the EventManager Class Functions and Properties. Uses a Singleton Design Pattern.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "WindowManager.h"

class EventManager {
private:
	static EventManager* m_instance;

	// Private Constructor and Destructor
	EventManager(); // Constructor
	~EventManager(); // Destructor

	// Deletes the Copy Consturctor and the Assignment Operator
	EventManager(const EventManager&) = delete; // Copy Constructor
	EventManager& operator=(const EventManager&) = delete; // Assignment Operator

public:
	// Getting the Singleton Instance
	static EventManager* getInstance(); // Returns the Singleton Instance

	// Event Manager Functions
	void processMainEvents(); // Processes all Events in the Main Window
	void processDebugEvents(); // Processes all Events in the Debug Window
};

