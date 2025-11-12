/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : DoneButton.cpp
Description : Defines the DoneButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "DoneButton.h"
#include "TurnController.h"

DoneButton::DoneButton() {
	// Ensure that Button Text Exists
	if (this->m_buttonText != nullptr) {
		this->m_buttonText->setString("Done");
		this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
	}
}

DoneButton::~DoneButton() {
}

void DoneButton::execute() {
	// Set the Level Turn State to moving
	TurnController::getInstance()->m_turnState = TurnController::TurnStates::DONE;
}