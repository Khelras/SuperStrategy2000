/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : MoveButton.h
Description : Declares the MoveButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include "Button.h"

class MoveButton : public Button {
public:
	// Constructor and Destructor
	MoveButton(); // Constructor
	virtual ~MoveButton(); // Destructor

	// Execute Function
	void execute() override;
};