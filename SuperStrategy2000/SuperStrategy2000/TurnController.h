/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : TurnController.h
Description : Controls the Turn. Follows a Singleton Design Pattern.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Ability.hpp"

class TurnController {
private:
	// Singleton Instance
	static TurnController* m_instance;

	// Private Constructor and Destructor
	TurnController() {};
	~TurnController() {};

	// Delete Copy Constructor and Assignment
	TurnController(TurnController const&) = delete;
	void operator=(TurnController const&) = delete;

public:
	// Getting the Singleton Instance
	static TurnController* getInstance() {
		// If there is no Instance
		if (m_instance == nullptr) {
			// Create an Instance
			m_instance = new TurnController();
		}

		// Return the Singleton Instance
		return m_instance;
	}

	// Turn States
	enum class TurnStates {
		DECIDING,
		MOVING,
		BASIC, // Basic Attack
		SPECIAL, // Special Ability
		DONE
	};

	// Turn Order Attributes
	TurnStates m_turnState = TurnStates::DECIDING;
	bool m_hasMoved = false;
	Ability* m_ability = nullptr;

	// Turn Order Functions Functions
	void reset() {
		// Reset to Default
		this->m_turnState = TurnStates::DECIDING;
		this->m_hasMoved = false;
		this->m_ability = nullptr;
	}
};