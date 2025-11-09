/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : CameraManager.h
Description : Declares the CameraManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <numeric>

class CameraManager {
public:
	// Static Constant Base Resolutions
	static const sf::Vector2f BASE_4X3; // For 4:3 Aspect Ratios
	static const sf::Vector2f BASE_16X9; // For 16:9 Aspect Rations

	// Constant Camera Move Speed
	const float CAMERA_MOVE_SPEED = 50.0f;

	// Views
	sf::View m_cameraView; // View for the Moving Camera
	sf::View m_uiView; // View for the User Interface

	// Constructor and Destructor
	CameraManager(); // Constructor
	~CameraManager(); // Destructor

	// Camera Manager Functions
	void processCameraView(); // Camera View Process Loop
	void processUIView(); // UI View Process Loop
	void centerCameraView(); // Centers Camera View to the Game Board
	sf::Vector2i getAspectRatio(sf::Vector2f _resolution); // Returns the Aspect Ratio of a given Resolution

private:
	// Private Functions
	void moveCamera(sf::Vector2f _offset); // Moves the Camera
};

