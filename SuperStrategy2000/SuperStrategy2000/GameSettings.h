/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : GameSettings.h
Description : Holds all the Game Settings information. Follows a Singleton Design Pattern
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

struct GameSettings {
private:
	// Singleton Instance
	static GameSettings* m_instance;

	// Private Constructor
	GameSettings() {}; 

	// Delete Copy Constructor and Assignment
	GameSettings(GameSettings const&) = delete;
	void operator=(GameSettings const&) = delete;

public:
	// Getting the Singleton Instance
	static GameSettings* getInstance() {
		// If there is no Instance
		if (m_instance == nullptr) {
			// Create an Instance
			m_instance = new GameSettings();
		}

		// Return the Singleton Instance
		return m_instance;
	}

	// Game Settings Values
	int m_windowX = 0; // Width of Window
	int m_windowY = 0; // Height of Window
	bool m_vsync = false; // Enable v-sync?
	int m_masterVolumn = 50; // Volumn of the Game
};

// Game Settings Input (Loading) and Output (Saving)
class GameSettingsIO {
public:
	static bool LoadGameSettings();
	static bool SaveGameSettings();
};