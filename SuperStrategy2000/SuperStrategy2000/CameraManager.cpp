/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : CameraManager.cpp
Description : Defines the CameraManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "CameraManager.h"
#include "GameManager.h"

// Defining the Static Constant Base Resolutions
const sf::Vector2f CameraManager::BASE_4X3 = sf::Vector2f(800, 600);
const sf::Vector2f CameraManager::BASE_16X9 = sf::Vector2f(920, 540);

CameraManager::CameraManager() {
}

CameraManager::~CameraManager() {
}

void CameraManager::processCameraView() {
	// Main Window
	sf::RenderWindow& mainWindow = GameManager::getInstance()->m_windowManager.m_mainWindow;

	// Set the Camera View
	this->m_cameraView.setSize(sf::Vector2f(mainWindow.getSize())); // Setting to the Size of the Main Window
	this->m_cameraView.zoom(1.0f); // Zoom
	mainWindow.setView(this->m_cameraView); // Setting the View of Main Window
}

void CameraManager::processUIView() {
	// Main Window
	sf::RenderWindow& mainWindow = GameManager::getInstance()->m_windowManager.m_mainWindow;

	// Set the Camera View
	this->m_uiView.setSize(sf::Vector2f(mainWindow.getSize())); // Setting to the Size of the Main Window
	this->m_cameraView.setCenter(mainWindow.getDefaultView().getCenter());
	mainWindow.setView(this->m_uiView); // Setting the View of Main Window
}

void CameraManager::centerCameraView() {
	// Game Board
	Grid* gameBoard = GameManager::getInstance()->m_gameBoard;

	// Center of Game Board
	sf::Vector2f center = gameBoard->m_gridBackground.getGlobalBounds().getCenter();
	this->m_cameraView.setCenter(center);
}

sf::Vector2i CameraManager::getAspectRatio(sf::Vector2f _resolution) {
	int x = static_cast<int>(_resolution.x);
	int y = static_cast<int>(_resolution.y);

	// Getting the Greatest Common Divisor
	int gcd = std::gcd(x, y);

	// Using the GCD to get the Aspect Ratio
	sf::Vector2i aspectRatio(x / gcd, y / gcd);
	return aspectRatio;
}
