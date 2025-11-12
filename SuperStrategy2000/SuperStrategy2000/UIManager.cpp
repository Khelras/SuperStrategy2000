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
#include "GameSettings.h"

UIManager::UIManager() {
	// Move Button
	this->m_buttons.push_back(new MoveButton());
}

UIManager::~UIManager() {
}

void UIManager::process() {
	// Constant References to Main Window and UI View
	const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
	const sf::View& UI_VIEW = GameManager::getInstance()->m_cameraManager.m_uiView;

	// Loop through all the Buttons
	for (auto& button : this->m_buttons) {
		// Reset Hover
		button->m_buttonShape.setOutlineColor(Button::BUTTON_OUTLINECOLOR_DEFAULT);

		// Mouse World Position
		sf::Vector2f mouseWorldPosition = MAIN_WINDOW.mapPixelToCoords(sf::Mouse::getPosition(MAIN_WINDOW), UI_VIEW);
		
		// Check if Mouse is hovering over this Button
		if (button->m_buttonShape.getGlobalBounds().contains(mouseWorldPosition)) {
			// Hover over this Button
			button->m_buttonShape.setOutlineColor(Button::BUTTON_OUTLINECOLOR_SELECTED);
		}
	}
}

void UIManager::positionButtons() {
	
}

void UIManager::drawUI(sf::RenderWindow& _window) {
	// Constant References to Main Window and UI View
	const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
	const sf::View& UI_VIEW = GameManager::getInstance()->m_cameraManager.m_uiView;

	// Evenly spread all the Buttons on the Bottom of the Screen
	int xSplit = static_cast<int>(MAIN_WINDOW.getSize().x) / (static_cast<int>(this->m_buttons.size()) + 1);
	int yPosition = static_cast<int>(MAIN_WINDOW.getSize().y) - 100;
	
	// Loop through all the Buttons
	for (int i = 0; i < this->m_buttons.size(); i++) {
		// Set the Button Position and Draw the Button
		sf::Vector2f buttonPosition = MAIN_WINDOW.mapPixelToCoords(sf::Vector2i(xSplit * (i + 1), yPosition), UI_VIEW);
		this->m_buttons[i]->setButtonPosition(buttonPosition);
		this->m_buttons[i]->drawButton(_window);
	}
}

bool UIManager::isMouseOnUI() {
	// Loop through all the Buttons
	for (auto& button : this->m_buttons) {
		// Constant References to Main Window and UI View
		const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
		const sf::View& UI_VIEW = GameManager::getInstance()->m_cameraManager.m_uiView;

		// Mouse World Position
		sf::Vector2f mouseWorldPosition = MAIN_WINDOW.mapPixelToCoords(sf::Mouse::getPosition(MAIN_WINDOW), UI_VIEW);

		// Check if Mouse is hovering over this Button
		if (button->m_buttonShape.getGlobalBounds().contains(mouseWorldPosition)) {
			// Mouse is hovering over UI
			return true;
		}
	}

	// Otherwise, Mouse is NOT hovering over UI
	return false;
}

Button* UIManager::getButtonFromMouse() {
	// Loop through all the Buttons
	for (auto& button : this->m_buttons) {
		// Constant References to Main Window and UI View
		const sf::RenderWindow& MAIN_WINDOW = GameManager::getInstance()->m_windowManager.m_mainWindow;
		const sf::View& UI_VIEW = GameManager::getInstance()->m_cameraManager.m_uiView;

		// Mouse World Position
		sf::Vector2f mouseWorldPosition = MAIN_WINDOW.mapPixelToCoords(sf::Mouse::getPosition(MAIN_WINDOW), UI_VIEW);

		// Check if Mouse is hovering over this Button
		if (button->m_buttonShape.getGlobalBounds().contains(mouseWorldPosition)) {
			// Mouse is hovering over a Button
			return button;
		}
	}

	// Otherwise, Mouse is NOT hovering over a Button
	return nullptr;
}
