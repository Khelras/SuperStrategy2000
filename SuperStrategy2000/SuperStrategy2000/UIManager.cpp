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

#include "UIManager.h"
#include "GameManager.h"

UIManager::UIManager() {
	this->m_buttons.push_back(new MoveButton());
	this->m_buttons[0]->setButtonPosition({ 100, 100 });
}

UIManager::~UIManager() {
}

void UIManager::process() {
	// Hover Buttons
	for (auto& button : this->m_buttons) {
		button->m_buttonShape.setOutlineColor(Button::BUTTON_OUTLINECOLOR_DEFAULT);

		// Constant References to Main Window and UI View
		const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
		const sf::View& UI_VIEW = GameManager::getInstance()->m_cameraManager.m_uiView;

		// Mouse World Position
		sf::Vector2f mouseWorldPosition = MAIN_WINDOW.mapPixelToCoords(sf::Mouse::getPosition(MAIN_WINDOW), UI_VIEW);
		if (button->m_buttonShape.getGlobalBounds().contains(mouseWorldPosition)) {
			button->m_buttonShape.setOutlineColor(Button::BUTTON_OUTLINECOLOR_SELECTED);
		}
	}
}

void UIManager::drawUI(sf::RenderWindow& _window) {
	// Draw all the Buttons
	for (auto& button : this->m_buttons) {
		button->drawButton(_window);
	}
}
