/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : LevelManager.h
Description : Declares the LevelManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Level.h"

class LevelManager {
public:
	// File Paths
	const std::string LEVEL1 = "assets/levels/level1.txt";
	const std::string LEVEL2 = "assets/levels/level2.txt";
	const std::string LEVEL3 = "assets/levels/level3.txt";

	// Levels
	std::vector<Level*> m_levels; // All Levels
	int m_completedLevels; // Completed Levels
	Level* m_currentLevel; // Current Level
	bool m_gameWon = false;

	// Constructor and Destructor
	LevelManager();
	~LevelManager();

	// Level Manager Functions and Properties
	void process(); // Level Manager Process Loop
	void loadLevels(); // Load all the Levels
	bool loadLevel(unsigned int _levelNumber, std::string _path); // Load Level
	void saveLevelProgress(); // Save Level Progess
	void nextLevel(); // Next Level
	void selectLevel(unsigned int _levelNumber); // Select Level

private:
	// Private Functions
	Level* findLevel(unsigned int _levelNumber); // Returns a Level given the Level Number
};

