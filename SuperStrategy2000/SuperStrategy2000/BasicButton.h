/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : BasicButton.h
Description : Declares the BasicButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Button.h"

class BasicButton : public Button {
public:
	// Constructor and Destructor
	BasicButton(); // Constructor
	virtual ~BasicButton(); // Destructor

	// Execute Function
	void execute() override;
};