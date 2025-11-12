/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : MoveButton.cpp
Description : Defines the MoveButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "MoveButton.h"
#include "TurnController.h"

MoveButton::MoveButton() {
	// Ensure that Button Text Exists
	if (this->m_buttonText != nullptr) {
		this->m_buttonText->setString("Move");
		this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
	}
}

MoveButton::~MoveButton() {
}

void MoveButton::execute() {
	// Check if this Unit has already Moved
	if (TurnController::getInstance()->m_hasMoved == false ) {
		// Set the Level Turn State to moving
		TurnController::getInstance()->m_turnState = TurnController::TurnStates::MOVING;
	}
}
