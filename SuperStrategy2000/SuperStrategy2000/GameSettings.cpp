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
	std::string masterVolumnName; // The Name
	std::string masterVolumnValue; // The Value

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
			masterVolumnName.push_back(line[i]);
		}
		// Position of '=' HAS been found
		else {
			// If i is greater than the Position of '='
			if (i > equalsPos) {
				// Push Back this Character to the Value
				masterVolumnValue.push_back(line[i]);
			}
		}
	}

	// If the Name is wrong
	if (masterVolumnName != "masterVolumn") {
		// Error Message
		std::cerr << "Invalid settings file!\n";
		return false; // Loading Failed
	}

	// Afterwards
	this->m_masterVolumn = std::stoi(masterVolumnValue);
	equalsPos = -1; // Reset the Position of '='
	// -------------------- Line: "masterVolumn=<value>" --------------------


	
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
	file << "masterVolumn=" << this->m_masterVolumn << std::endl; // Master Volumn
	return true; // Saving Successful
}
