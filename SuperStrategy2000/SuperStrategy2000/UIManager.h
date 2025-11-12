/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : UIManager.h
Description : Declares the UIManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <vector>
#include "MoveButton.hpp"

class UIManager {
public:
	// UI Manager Attributes
	std::vector<Button*> m_buttons;

	// Constructor and Destructor
	UIManager();
	~UIManager();

	// UI Manager Functions
	void process(); // UI Manager Process Loop
	void positionButtons(); // Split all the Buttons at the Bottom of the Screen.
	void drawUI(sf::RenderWindow& _window); // Draws all the UI
	bool isMouseOnUI(); // Returns whether the Mouse is hovering over UI
	Button* getButtonFromMouse(); // Return the Button the Mouse is hovering over
};

