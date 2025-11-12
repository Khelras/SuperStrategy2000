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
#include "GameSettings.h"

LevelManager::LevelManager() {
	this->m_currentLevel = nullptr;

	if (GameSettings::getInstance()->m_completedLevels > 3 ||
		GameSettings::getInstance()->m_completedLevels < 0) {
		this->m_completedLevels = 0;
	}
	else {
		this->m_completedLevels = GameSettings::getInstance()->m_completedLevels;
	}
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
	if (this->m_currentLevel != nullptr) {
		// If Level Won
		if (this->m_currentLevel->m_levelHasWon == true) {
			this->m_completedLevels++;
			this->saveLevelProgress();
			this->nextLevel();

			return;
		}

		// Process the Current Selected Level
		this->m_currentLevel->process();
	};

	
}

void LevelManager::loadLevels() {
	this->loadLevel(1, this->LEVEL1);
	this->loadLevel(2, this->LEVEL2);
	this->loadLevel(3, this->LEVEL3);

	// Load Last Level
	this->m_completedLevels = GameSettings::getInstance()->m_completedLevels;
	if (this->m_completedLevels = 0) {
		this->m_currentLevel = this->m_levels[0];
	}
	else if (this->m_completedLevels = 1) {
		this->m_currentLevel = this->m_levels[1];
	}
	else if (this->m_completedLevels = 2) {
		this->m_currentLevel = this->m_levels[2];
	}
	// Reset Progress
	else {
		this->m_currentLevel = this->m_levels[0];
		GameSettings::getInstance()->m_completedLevels = 0;
		this->m_completedLevels = 0;
	}
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

void LevelManager::saveLevelProgress() {
	GameSettings::getInstance()->m_completedLevels = this->m_completedLevels;
}

void LevelManager::nextLevel() {
	int currentLevelPosition = 0;
	for (int i = 0; i < this->m_levels.size(); i++) {
		if (this->m_levels[i] == this->m_currentLevel) {
			currentLevelPosition = i;
			break;
		}
	}

	if (currentLevelPosition + 1 >= this->m_levels.size()) {
		// Won the Game
		this->m_gameWon = true;
	}
	else {
		// Select new Level
		this->m_currentLevel = this->m_levels[currentLevelPosition + 1];
	}
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
