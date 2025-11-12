

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Level.h"

class LevelManager {
public:
	// Levels
	std::vector<Level*> m_levels; // All Levels
	std::vector<Level*> m_completedLevels; // Completed Levels
	Level* m_currentLevel; // Current Level

	// Constructor and Destructor
	LevelManager();
	~LevelManager();

	// Level Manager Functions and Properties
	void process(); // Level Manager Process Loop
	bool loadLevel(unsigned int _levelNumber, std::string _path); // Load Level
	bool saveLevel(unsigned int _levelNumber, std::string _path); // Save Level
	void selectLevel(unsigned int _levelNumber); // Select Level

private:
	// Private Functions
	Level* findLevel(unsigned int _levelNumber); // Returns a Level given the Level Number
};

