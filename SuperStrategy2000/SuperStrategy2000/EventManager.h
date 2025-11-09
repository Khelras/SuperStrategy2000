/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : EventManager.h
Description : Declares the EventManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "WindowManager.h"

class EventManager {
public:
	// Constructor and Destructor
	EventManager(); // Constructor
	~EventManager(); // Destructor

	// Event Manager Functions
	void process(WindowManager& _windowManager); // Processes all the Events

private:
	bool m_isShiftPressed;
};

