/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : BasicButton.hpp
Description : Declares and Defines the BasicButton Class Functions and Properties. Derives from the Button Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Button.h"

class BasicButton : public Button {
public:
	// Constructor
	BasicButton() {
		// Ensure that Button Text Exists
		if (this->m_buttonText != nullptr) {
			this->m_buttonText->setString("Basic");
			this->m_buttonText->setOrigin(this->m_buttonText->getLocalBounds().getCenter()); // Center Origin
		}
	};

	// Destructor
	virtual ~BasicButton() {};

	// Execute Function
	void execute() const override {
		std::cout << "BasicButton works!\n";
	};
};