/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Button.cpp
Description : Defines the Button Abstract Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Button.h"

// Defining the Static Constant Button Colors
const sf::Color Button::BUTTON_OUTLINECOLOR_DEFAULT = sf::Color::Transparent;
const sf::Color Button::BUTTON_OUTLINECOLOR_SELECTED = sf::Color::Black;

Button::Button() {
	// Button Shape
	this->m_buttonShape.setSize(sf::Vector2f(250, 100)); // 500x200 Button
	this->m_buttonShape.setFillColor(sf::Color::Yellow);
	this->m_buttonShape.setOutlineColor(Button::BUTTON_OUTLINECOLOR_DEFAULT);
	this->m_buttonShape.setOutlineThickness(10.0f);

	// Load Button Font
	if (this->m_buttonFont.openFromFile("assets/fonts/arial.ttf")) {
		this->m_buttonText = new sf::Text(this->m_buttonFont);
		this->m_buttonText->setFillColor(sf::Color::Black);
		this->m_buttonText->setCharacterSize(80);
		this->m_buttonText->setOrigin(this->m_buttonText->getGlobalBounds().getCenter()); // Center Origin
	}
	// Failed to load Button Font
	else {
		// Error Message
		std::cerr << "Unable to load button font!\n";
		this->m_buttonText = nullptr;
	}
}

Button::~Button() {
	// Ensure Button Text exists
	if (this->m_buttonText != nullptr) {
		// Delete Button Text
		delete (this->m_buttonText);
		this->m_buttonText = nullptr;
	}
}

void Button::setButtonPosition(sf::Vector2f _position) {
	// Set the Button Shape Position
	this->m_buttonShape.setPosition(_position);

	// Set the Button Text Position to the Center of the Button Shape
	this->m_buttonText->setOrigin(this->m_buttonText->getGlobalBounds().getCenter());
	this->m_buttonText->setPosition(this->m_buttonShape.getGlobalBounds().getCenter());
}

void Button::drawButton(sf::RenderWindow& _window) {
	_window.draw(this->m_buttonShape);
	_window.draw(*(this->m_buttonText));
}
