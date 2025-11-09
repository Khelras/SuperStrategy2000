

#pragma once
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
	void loadLevel(std::string _path); // Load Level
	void saveLevel(std::string _path); // Save Level
	void selectLevel(int _levelNumber); // Select Level

private:
	// Private Functions
	Level* findLevel(int _levelNumber); // Returns a Level given the Level Number
};

