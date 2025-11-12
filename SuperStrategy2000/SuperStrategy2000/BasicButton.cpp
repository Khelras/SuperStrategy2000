/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : BasicButton.cpp
Description : Defines the BasicButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "BasicButton.h"
#include "TurnController.h"

BasicButton::BasicButton() {
	// Ensure that Button Text Exists
	if (this->m_buttonText != nullptr) {
		this->m_buttonText->setString("Basic");
		this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
	}
}

BasicButton::~BasicButton() {
}

void BasicButton::execute() {
	// Set the Level Turn State to Basic
	TurnController::getInstance()->m_turnState = TurnController::TurnStates::BASIC;
}