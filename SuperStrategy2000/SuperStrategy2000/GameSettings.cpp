/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : GameSettings.cpp
Description : Defines the GameSettingsIO Load() and Save() Functions
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "GameSettings.h"

// Define the Static GameSettings Instance
GameSettings* GameSettings::m_instance = nullptr;

// Game Settings File Path
const std::string GAME_SETTINGS_FILE_PATH = "settings.txt";

bool GameSettings::loadGameSettings() {
	// Getting the File
	std::ifstream file(GAME_SETTINGS_FILE_PATH);
	if (!file) {
		// Error Message
		std::cerr << "Unable to load file '" << GAME_SETTINGS_FILE_PATH << "'!\n";
		return false; // Loading Failed
	}

	// File Values
	std::string line; // Line
	int equalsPos = -1; // The Position of '=' in the Line (-1 means not yet found)

	// -------------------- Line: "windowX=<value>" --------------------
	std::getline(file, line); // "windowX=<value>"
	std::string windowXName; // The Name
	std::string windowXValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) { 
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') { 
			// Save the Equals Position
			equalsPos = i; 
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			windowXName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				windowXValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (windowXName != "windowX") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_windowX = std::stoi(windowXValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "windowX=<value>" --------------------



	// -------------------- Line: "windowY=<value>" --------------------
	std::getline(file, line); // "windowY=<value>"
	std::string windowYName; // The Name
	std::string windowYValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) {
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') {
			// Save the Equals Position
			equalsPos = i;
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			windowYName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				windowYValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (windowYName != "windowY") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_windowY = std::stoi(windowYValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "windowY=<value>" --------------------



	// -------------------- Line: "vsync=<value>" --------------------
	std::getline(file, line); // "windowY=<value>"
	std::string vsyncName; // The Name
	std::string vsyncValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) {
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') {
			// Save the Equals Position
			equalsPos = i;
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			vsyncName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				vsyncValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (vsyncName != "vsync") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Evaluate the v-sync Value
	if (vsyncValue == "0") { // False Value
		this->m_vsync = false;
	}
	else if (vsyncValue == "1") { // True Value
		this->m_vsync = true;
	}
	else { // Invalid Value
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Reset the Position of '='
	equalsPos = -1; 
	// -------------------- Line: "vsync=<value>" --------------------



	// -------------------- Line: "masterVolume=<value>" --------------------
	std::getline(file, line); // "masterVolume=<value>"
	std::string masterVolumeName; // The Name
	std::string masterVolumeValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) {
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') {
			// Save the Equals Position
			equalsPos = i;
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			masterVolumeName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				masterVolumeValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (masterVolumeName != "masterVolume") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_masterVolume = std::stoi(masterVolumeValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "masterVolume=<value>" --------------------



	// -------------------- Line: "effectsVolume=<value>" --------------------
	std::getline(file, line); // "effectsVolume=<value>"
	std::string effectsVolumeName; // The Name
	std::string effectsVolumeValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) {
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') {
			// Save the Equals Position
			equalsPos = i;
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			effectsVolumeName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				effectsVolumeValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (effectsVolumeName != "effectsVolume") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_effectsVolume = std::stoi(effectsVolumeValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "effectsVolume=<value>" --------------------



	// -------------------- Line: "musicVolume=<value>" --------------------
	std::getline(file, line); // "musicVolume=<value>"
	std::string musicVolumeName; // The Name
	std::string musicVolumeValue; // The Value

	// Loop until '='
	for (int i = 0; i < line.length(); i++) {
		// Skip any Whitespace Characters
		if (std::isspace(static_cast<unsigned int>(line[i]))) continue;

		// If this Character is '='
		if (line[i] == '=') {
			// Save the Equals Position
			equalsPos = i;
			continue;
		}

		// Position of '=' has NOT been found
		if (equalsPos == -1) {
			// Push Back this Character to the Name
			musicVolumeName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				musicVolumeValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (musicVolumeName != "musicVolume") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_musicVolume = std::stoi(musicVolumeValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "musicVolume=<value>" --------------------


	
	// Game Settings Successfully Loaded
	return true;
}

bool GameSettings::saveGameSettings() {
	// Getting the File
	std::ofstream file(GAME_SETTINGS_FILE_PATH);
	if (!file) {
		// Error Message
		std::cerr << "Unable to save to '" << GAME_SETTINGS_FILE_PATH <<"'!\n";
		return false; // Saving Failed
	}

	// Saving
	file << "windowX=" << this->m_windowX << std::endl; // Window Width Size
	file << "windowY=" << this->m_windowY << std::endl; // Window Height Size
	file << "vsync=" << this->m_vsync << std::endl; // Enable v-sync
	file << "masterVolume=" << this->m_masterVolume << std::endl; // Master Volume
	file << "effectsVolume=" << this->m_effectsVolume << std::endl; // Sound Effects Volume
	file << "musicVolume=" << this->m_musicVolume << std::endl; // Background Music Volume
	return true; // Saving Successful
}
