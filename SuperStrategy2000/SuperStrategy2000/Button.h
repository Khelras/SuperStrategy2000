/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Button.h
Description : Declares the Button Abstract Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	// Static Constant Button Colors
	static const sf::Color BUTTON_OUTLINECOLOR_DEFAULT;
	static const sf::Color BUTTON_OUTLINECOLOR_SELECTED;

	// Button Attributes
	sf::Font m_buttonFont;
	sf::Text* m_buttonText;
	sf::RectangleShape m_buttonShape;

	// Constructor and Destructor
	Button(); // Constructor
	virtual ~Button(); // Destructor

	// Button Functions
	virtual void execute() const = 0; // Abstract Function
	void setButtonPosition(sf::Vector2f _position); // Set the Button Position
	void drawButton(sf::RenderWindow& _window); // Draw the Button
};

