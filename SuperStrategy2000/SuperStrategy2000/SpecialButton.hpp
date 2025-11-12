/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : SpecialButton.hpp
Description : Declares and Defines the SpecialButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Button.h"

class SpecialButton : public Button {
public:
	// Constructor
	SpecialButton() {
		// Ensure that Button Text Exists
		if (this->m_buttonText != nullptr) {
			this->m_buttonText->setString("Special");
			this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
		}
	};

	// Destructor
	virtual ~SpecialButton() {};

	// Execute Function
	void execute() const override {
		std::cout << "SpecialButton works!\n";
	};
};