/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Square.h
Description : Declares the Square Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Square {
public:
	// Static Constant Square Color Attributes for ALL Squares
	static const sf::Color SQUARE_FILLCOLOR_DEFAULT;
	static const sf::Color SQUARE_FILLCOLOR_SELECTED;
	static const sf::Color SQUARE_OUTLINECOLOR_DEFAULT;
	static const sf::Color SQUARE_OUTLINECOLOR_SELECTED;

	// Static Square Size Attribute for ALL Squares
	static sf::Vector2i SQUARE_SIZE;

	// Square Attributes
	sf::Vector2i m_squarePosition;
	std::vector<Square*> m_squareNeighbors;
	sf::RectangleShape m_squareShape;

	// Constructor and Destructor
	Square(sf::Vector2i _squarePosition); // Constructor
	~Square(); // Destructor
};

