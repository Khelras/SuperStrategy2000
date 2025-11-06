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

CameraManager::CameraManager() {
}

CameraManager::~CameraManager() {
}

void CameraManager::processCameraView() {
	// Main Window
	sf::RenderWindow& mainWindow = GameManager::getInstance()->m_windowManager.m_mainWindow;

	// Set the Camera View
	this->m_cameraView.setSize(sf::Vector2f(mainWindow.getSize())); // Setting to the Size of the Main Window
	this->m_cameraView.setCenter(mainWindow.getDefaultView().getCenter());
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
