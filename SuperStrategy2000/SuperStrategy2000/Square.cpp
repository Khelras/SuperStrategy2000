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

Square::Square(sf::Vector2i _squareSize, sf::Vector2i _squarePosition) {
	// Square Attributes
	this->m_squareShape.setSize(sf::Vector2f(static_cast<float>(_squareSize.x), static_cast<float>(_squareSize.y)));
	this->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_DEFAULT); // Fill Color
	this->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_DEFAULT); // Outline Color
	this->m_squareShape.setOutlineThickness(-1.0f);
	this->m_squarePosition = _squarePosition;

	// Actor Related Attributes
	this->m_actorOnSquare = nullptr;
}

Square::~Square() {
}

void Square::reset() {
	// Reset the Square Shape Colors
	this->m_squareShape.setFillColor(Square::SQUARE_FILLCOLOR_DEFAULT); // Fill Color
	this->m_squareShape.setOutlineColor(Square::SQUARE_OUTLINECOLOR_DEFAULT); // Outline Color
}
