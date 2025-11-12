/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : LevelManager.cpp
Description : Defines the LevelManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "LevelManager.h"
#include "GameManager.h"

LevelManager::LevelManager() {
	this->m_currentLevel = nullptr;
}

LevelManager::~LevelManager() {
	// Loop through the Levels
	for (auto& level : this->m_levels) {
		// Ensure Level exists
		if (level != nullptr) {
			// Delete Level
			delete(level);
			level = nullptr;
		}
	}
}

void LevelManager::process() {
	// Ensure there is a Selected Level
	if (this->m_currentLevel == nullptr) return;

	// Process the Current Selected Level
	this->m_currentLevel->process();
}

bool LevelManager::loadLevel(unsigned int _levelNumber, std::string _path) {
	/*
		Level Files are expected to have a width and height and a 2D Grid of double-digit numbers.
		The first 2 numbers will represent the width and the height of the Grid respectively.
		the next 2 numbers will represent the width and the height of each Square respectively.
		Afterwards, the file loader will expect to see 'w*h' amount of numbers.
		Each of those numbers (after the width and height) will represent an actor or space in the world.
		Each number are spaced out so that we can use the '<<' operator to read those numbers.
	*/

	// Open File
	std::ifstream levelFile(_path);

	// If the Level File failed to Open
	if (levelFile.is_open() == false) {
		// Error Message
		std::cout << "Unable to load level file from '" << _path << "'!\n";
		return false;
	}
	
	// Create the Level
	Level* level = new Level(_levelNumber, levelFile);

	// Add Level to the Levels Array
	this->m_levels.push_back(level); 

	// Select this Level if there is no Selected Level
	if (this->m_currentLevel == nullptr) {
		this->m_currentLevel = level;
	}

	// Level Loaded Successfully
	return true;
}

bool LevelManager::saveLevel(unsigned int _levelNumber, std::string _path) {
	// TODO: MAKE LEVEL SAVING
	return true;
}

void LevelManager::selectLevel(unsigned int _levelNumber) {
	// Level
	Level* level = this->findLevel(_levelNumber);

	// Level Exists
	if (level != nullptr) {
		this->m_currentLevel = level;
	}
	// Level does NOT Exists
	else if (level == nullptr) {
		std::cerr << "Unknown Level..?" << std::endl;
	}
}

Level* LevelManager::findLevel(unsigned int _levelNumber) {
	// Result
	Level* result = nullptr; // Default to nullptr

	// Loop through the List of Levels
	for (auto& level : this->m_levels) {
		// Check the Level Number
		if (level->m_levelNumber == _levelNumber) {
			// Update Result
			result = level;
			break; // End Loop
		}
	}

	// Return the Result
	return result;
}
