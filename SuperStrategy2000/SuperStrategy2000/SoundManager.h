/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : SoundManager.h
Description : Declares the SoundManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <map>

class SoundManager {
private:
	// Sound Manager Attributes
	std::unordered_map<std::string, sf::SoundBuffer> m_soundBuffers; // Sound Buffers
	std::list<sf::Sound> m_activeSounds; // Active Playing SFX
	sf::Music* m_backgroundMusic; // Singular Background Music

public:
	// Constructor and Destructor
	SoundManager(); // Constructor
	~SoundManager(); // Destructor

	// Sound Manager Functions
	void process(); // Sound Manager Process Loop
	bool loadSound(std::string _soundName, std::string _soundFilePath); // Load a Sound File and store it into the Buffer Map
	bool playSound(std::string _soundName, float _pitch = 1.0f); // Play a Sound from the Sound Buffer
	void playMusic(std::string _musicFilePath, bool _loop = true); // Play Background Music from a sound file
	void stopMusic(); // Stop and Deletes the Music currently playing
};

