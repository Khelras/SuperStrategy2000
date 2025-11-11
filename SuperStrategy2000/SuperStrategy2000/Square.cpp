/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Square.cpp
Description : Defines the Square Class Functions and Properties
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Square.h"

// Defining the Static Constant Square Color Attributes for ALL Squares
const sf::Color Square::SQUARE_FILLCOLOR_DEFAULT = sf::Color::Transparent;
const sf::Color Square::SQUARE_FILLCOLOR_SELECTED = sf::Color::Green;
const sf::Color Square::SQUARE_OUTLINECOLOR_DEFAULT = sf::Color::Black;
const sf::Color Square::SQUARE_OUTLINECOLOR_SELECTED = sf::Color::Green;

// Defining the Statc Square Size Attribute for ALL Squares
sf::Vector2i Square::SQUARE_SIZE = sf::Vector2i(32, 32); // Default to 32x32

Square::Square(sf::Vector2i _squarePosition) {
	// Square Attributes
	sf::Vector2f squareSize = sf::Vector2f(static_cast<float>(Square::SQUARE_SIZE.x), static_cast<float>(Square::SQUARE_SIZE.y));
	this->m_squareShape.setSize(squareSize);
	this->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_DEFAULT); // Fill Color
	this->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_DEFAULT); // Outline Color
	this->m_squareShape.setOutlineThickness(-1.0f);

	// Square Attributes
	this->m_squarePosition = _squarePosition;
}

Square::~Square() {
}
