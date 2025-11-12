/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Grid.h
Description : Declares the Grid Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include "Square.h"
#include "Obstacle.h"
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"

class Grid {
public:
	// Grid Attributes
	sf::RectangleShape m_gridBackground; // Grid Space
	std::vector<std::vector<Square*>> m_grid; // 2D Grid Array
	sf::Vector2i m_gridSize; // Size of Grid Array
	sf::Vector2i m_squareSize; // Size of each Square on the Grid
	Square* m_selectedSquare; // The Selected Square on the Grid
	Square* m_hoverSquare; // The Hovered Square on the Grid

	// Constructor and Destructor
	Grid(std::ifstream& _gridFile); // Constructor
	~Grid(); // Destructor

	// Grid Functions
	void process(); // Grid Process Loop
	void clear(); // Resets every Square on the Grid by to its Default Colours
	void selectSquare(Actor* _actor); // Select the Square of the given Actor
	void breadthFirstSearch(Square* _start, int _depth, bool _checkActors = false); // Level-Ordered Search with a given Depth

	// Math
	float getManhattanDistance(Square* _start, Square* _end);
};

