/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : EventManager.cpp
Description : Defines the EventManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "EventManager.h"

// Define the Static EventManager Instance
EventManager* EventManager::m_instance = nullptr;

EventManager::EventManager() {
}

EventManager::~EventManager() {
}

EventManager* EventManager::getInstance() {
    // If there is no Instance
    if (m_instance == nullptr) {
        // Create an Instance
        m_instance = new EventManager();
    }

    // Return the Singleton Instance
    return m_instance;
}