/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : DebugSettings.h
Description : Holds all the Debug Settings information. Follows a Singleton Design Pattern.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once

struct DebugSettings {
private:
	// Singleton Instance
	static DebugSettings* m_instance;

	// Private Constructor
	DebugSettings() {};
	~DebugSettings() {};

	// Delete Copy Constructor and Assignment
	DebugSettings(DebugSettings const&) = delete;
	void operator=(DebugSettings const&) = delete;

public:
	// Getting the Singleton Instance
	static DebugSettings* getInstance() {
		// If there is no Instance
		if (m_instance == nullptr) {
			// Create an Instance
			m_instance = new DebugSettings();
		}

		// Return the Singleton Instance
		return m_instance;
	}

	// Game Settings Values (Defaulted)
	bool m_oneShot = false;
};