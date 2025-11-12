/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Square.h
Description : Declares the Square Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Actor.h"

class Square {
public:
	// Static Constant Square Color Attributes for ALL Squares
	static const sf::Color SQUARE_FILLCOLOR_DEFAULT;
	static const sf::Color SQUARE_FILLCOLOR_SELECTED;
	static const sf::Color SQUARE_OUTLINECOLOR_DEFAULT;
	static const sf::Color SQUARE_OUTLINECOLOR_SELECTED;

	// Square Attributes
	sf::RectangleShape m_squareShape; // The Square Shape
	sf::Vector2i m_squarePosition; // Position on the Grid (not World Space)
	std::vector<Square*> m_squareNeighbors; // Surrounding Squares

	// Actor Related Attributes
	Actor* m_actorOnSquare; // The Current Actor sitting on the Square

	// Constructor and Destructor
	Square(sf::Vector2i _squareSize, sf::Vector2i _squarePosition); // Constructor
	~Square(); // Destructor

	// Square Functions
	void reset(); // Reset this Square back to its Default Colours
};

