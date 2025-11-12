/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : DoneButton.h
Description : Declares the DoneButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Button.h"

class DoneButton : public Button {
public:
	// Constructor and Destructor
	DoneButton(); // Constructor
	virtual ~DoneButton(); // Destructor

	// Execute Function
	void execute() override;
};

