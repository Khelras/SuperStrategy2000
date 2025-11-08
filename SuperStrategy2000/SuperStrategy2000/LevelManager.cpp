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

}

void LevelManager::loadLevel(std::string _path) {
	// TODO: MAKE LEVEL LOADING
}

void LevelManager::saveLevel(std::string _path) {
	// TODO: MAKE LEVEL SAVING
}

void LevelManager::selectLevel(int _levelNumber) {
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

Level* LevelManager::findLevel(int _levelNumber) {
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
