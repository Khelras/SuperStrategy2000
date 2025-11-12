/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : SpecialButton.cpp
Description : Defines the SpecialButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "SpecialButton.h"
#include "TurnController.h"

SpecialButton::SpecialButton() {
	// Ensure that Button Text Exists
	if (this->m_buttonText != nullptr) {
		this->m_buttonText->setString("Special");
		this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
	}
}

SpecialButton::~SpecialButton() {
}

void SpecialButton::execute() {
	// Set the Level Turn State to Special
	TurnController::getInstance()->m_turnState = TurnController::TurnStates::SPECIAL;
}
