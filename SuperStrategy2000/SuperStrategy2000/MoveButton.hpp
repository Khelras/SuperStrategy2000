/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : MoveButton.hpp
Description : Declares and Defines the MoveButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Button.h"

class MoveButton : public Button {
public:
	// Constructor
	MoveButton() { 
		// Ensure that Button Text Exists
		if (this->m_buttonText != nullptr) {
			this->m_buttonText->setString("Move");
			this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
		}
	};

	// Destructor
	virtual ~MoveButton() {};

	// Execute Function
	void execute() const override {
		std::cout << "MoveButton works!\n";
	};
};