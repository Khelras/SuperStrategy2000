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

class CameraManager {
public:
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
};

