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
const sf::Vector2f CameraManager::BASE_4X3 = sf::Vector2f(400, 300);
const sf::Vector2f CameraManager::BASE_16X9 = sf::Vector2f(480, 270);

CameraManager::CameraManager() {
}

CameraManager::~CameraManager() {
}

void CameraManager::processCameraView() {
	// Main Window
	sf::RenderWindow& mainWindow = GameManager::getInstance()->m_windowManager.m_mainWindow;
	float mainWindowX = static_cast<float>(mainWindow.getSize().x);
	float mainWindowY = static_cast<float>(mainWindow.getSize().y);
	sf::Vector2f resolution = sf::Vector2f(mainWindowX, mainWindowY); // Resolution of Main Window

	// Getting the Base Resolution based on the Aspect Ratio
	sf::Vector2f baseResolution;
	sf::Vector2i aspectRatio = this->getAspectRatio(resolution);

	// 4:3
	if (aspectRatio == sf::Vector2i(4, 3)) { 
		// 4:3 Base Resolution
		baseResolution = CameraManager::BASE_4X3;
	}
	// 16:9
	else if (aspectRatio == sf::Vector2i(16, 9)) {
		// 16:9 Base Resolution
		baseResolution = CameraManager::BASE_16X9;
	}
	// Other
	else {
		// Just use the Main Window Resolution
		baseResolution = resolution;
	}

	// Set the Camera View
	this->m_cameraView.setSize(baseResolution); // Setting the Size to the Base Resolution
	this->m_cameraView.zoom(1.0f); // Zoom
	mainWindow.setView(this->m_cameraView); // Setting the View of Main Window

	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(mainWindow); // Mouse Position relative to the Main Window
	
	// Mouse Camera based on the Mouse Position relative to the Window Resolution
	float move = this->CAMERA_MOVE_SPEED;
	if (mousePosition.x <= 0) { // Mouse is at the Left of the Window
		this->moveCamera(sf::Vector2f(-move, 0));
	}
	if (mousePosition.x >= static_cast<float>(resolution.x)) { // Mouse is at the Right of the Window
		this->moveCamera(sf::Vector2f(move, 0));
	}
	if (mousePosition.y <= 0) { // Mouse is at the Top of the Window
		this->moveCamera(sf::Vector2f(0, -move));
	}
	if (mousePosition.y >= static_cast<float>(resolution.y)) { // Mouse is at the Bottom of the Window
		this->moveCamera(sf::Vector2f(0, move));
	}
}

void CameraManager::processUIView() {
	// Main Window
	sf::RenderWindow& mainWindow = GameManager::getInstance()->m_windowManager.m_mainWindow;

	// Set the Camera View
	this->m_uiView.setSize(sf::Vector2f(mainWindow.getSize())); // Setting to the Size of the Main Window
	this->m_cameraView.setCenter(this->m_cameraView.getCenter()); // Use the Center of the Camera View
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
	// Static Cast Float to Int
	int x = static_cast<int>(_resolution.x);
	int y = static_cast<int>(_resolution.y);

	// Getting the Greatest Common Divisor
	int gcd = std::gcd(x, y);

	// Using the GCD to get the Aspect Ratio
	sf::Vector2i aspectRatio(x / gcd, y / gcd);
	return aspectRatio;
}

void CameraManager::moveCamera(sf::Vector2f _offset) {
	// Perform Movement
	this->m_cameraView.move(_offset);

	// Game Board
	Grid* gameBoard = GameManager::getInstance()->m_gameBoard;
	sf::FloatRect gameBoardBounds = gameBoard->m_gridBackground.getGlobalBounds();

	// Camera Position
	sf::Vector2f cameraCenter = this->m_cameraView.getCenter();

	// Evaluate the Movement along the x-axis
	if (cameraCenter.x <= gameBoardBounds.position.x) { // Beyond the Left Side of Game Board
		// Restrict to the Left Side of Game Board
		this->m_cameraView.setCenter(sf::Vector2f(gameBoardBounds.position.x, cameraCenter.y));
	}
	if (cameraCenter.x >= gameBoardBounds.size.x) { // Beyond the Right Side of Game Board
		// Restrict to the Right Side of Game Board
		this->m_cameraView.setCenter(sf::Vector2f(gameBoardBounds.size.x, cameraCenter.y));
	}
	
	// Camera Position
	cameraCenter = this->m_cameraView.getCenter();

	// Evaluate the Movement along the y-axis
	if (cameraCenter.y <= gameBoardBounds.position.y) { // Beyond the Top Side of Game Board
		// Restrict to the Top Side of Game Board
		this->m_cameraView.setCenter(sf::Vector2f(cameraCenter.x, gameBoardBounds.position.y));
	}
	if (cameraCenter.y >= gameBoardBounds.size.y) { // Beyond the Bottom Side of Game Board
		// Restrict to the Bottom Side of Game Board
		this->m_cameraView.setCenter(sf::Vector2f(cameraCenter.x, gameBoardBounds.size.y));
	}
}
