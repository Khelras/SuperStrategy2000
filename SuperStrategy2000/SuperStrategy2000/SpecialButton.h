/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : SpecialButton.h
Description : Declares the SpecialButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Button.h"

class SpecialButton : public Button {
public:
	// Constructor and Destructor
	SpecialButton(); // Constructor
	virtual ~SpecialButton(); // Destructor

	// Execute Function
	void execute() override;
};