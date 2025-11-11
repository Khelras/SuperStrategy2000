/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Grid.h
Description : Declares the Grid Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <cmath>
#include "Square.h"

class Grid {
public:
	// Static Constant Margin
	static const int MARGIN = 100;

	// Grid Attributes
	sf::RectangleShape m_gridBackground; // Grid Space
	std::vector<std::vector<Square*>> m_grid; // 2D Grid Array
	sf::Vector2i m_gridSize; // Size of Grid Array
	Square* m_selectedSquare; // The Selected Square on the Grid
	Square* m_hoverSquare; // The Hovered Square on the Grid

	// Constructor and Destructor
	Grid(sf::Vector2i _gridSize, sf::Vector2i _squareSize); // Constructor
	~Grid(); // Destructor

	// Grid Functions
	void process();
};

