/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : GameSettings.h
Description : Holds all the Game Settings information. Follows a Singleton Design Pattern.
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
	// File Path to the Game Settings
	const std::string GAME_SETTINGS_FILE_PATH = "assets/settings.txt";

	// Singleton Instance
	static GameSettings* m_instance;

	// Private Constructor
	GameSettings() {
		if (this->loadGameSettings() == false) {
			// Generate a Settings File
			std::cout << "Generated a 'settings.txt' file..." << std::endl;
			this->saveGameSettings();
		}
	}; 

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

	// Game Settings Values (Defaulted)
	int m_windowX = 1920; // Width of Window
	int m_windowY = 1080; // Height of Window
	bool m_vsync = false; // Enable v-sync?
	int m_masterVolume = 50; // Volume of the Game
	int m_effectsVolume = 100; // Volume of Sound Effects
	int m_musicVolume = 100; // Volume of Background Music
	int m_completedLevels = 0; // Total Completed Level

	// Game Settings Load and Save Functions
	bool loadGameSettings(); 
	bool saveGameSettings();
};