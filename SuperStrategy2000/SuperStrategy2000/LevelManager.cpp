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

	// Process the Game Board of the Current Selected Level
	this->m_currentLevel->m_gameBoard->process();
}

bool LevelManager::loadLevel(int _levelNumber, std::string _path) {
	// Open File
	std::ifstream levelFile(_path);

	// If the Level File failed to Open
	if (levelFile.is_open() == false) {
		// Error Message
		std::cout << "Unable to load level file from '" << _path << "'!\n";
		return false;
	}

	/*
		Level Files are expected to have a width and height and a 2D Grid of double-digit numbers.
		Each number are spaced out so that we can use the '<<' operator to read those numbers.
		Each number will represent an actor or space in the world.
	*/

	// Attributes from File
	std::string line; // Line
	int width, height; // Width and Height
	levelFile >> width >> height; // Read the Width and the Height

	// TODO: READ EACH NUMBER TO LOAD THEIR RESPECTIVE ACTOR

	// Create the Level
	Level* level = new Level(_levelNumber, sf::Vector2i(width, height));

	// Add Level to the Levels Array
	this->m_levels.push_back(level); 

	// Select this Level if there is no Selected Level
	if (this->m_currentLevel == nullptr) {
		this->m_currentLevel = level;
	}

	// Level Loaded Successfully
	return true;
}

bool LevelManager::saveLevel(int _levelNumber, std::string _path) {
	// TODO: MAKE LEVEL SAVING
	return true;
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
