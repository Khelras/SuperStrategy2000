/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : SoundManager.cpp
Description : Defines the SoundManager Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "SoundManager.h"
#include "GameManager.h"
#include "GameSettings.h"

SoundManager::SoundManager() {
	this->m_backgroundMusic = nullptr;
}

SoundManager::~SoundManager() {
	// Ensure Background Music exists
	if (this->m_backgroundMusic != nullptr) {
		// Delete Background Music
		delete (this->m_backgroundMusic);
		this->m_backgroundMusic = nullptr;
	}
}

void SoundManager::process() {

}

bool SoundManager::loadSound(std::string _soundName, std::string _soundFilePath) {
	// Sound Buffer
	sf::SoundBuffer soundBuffer;

	// Load Sound Buffer from the given File path
	if (soundBuffer.loadFromFile(_soundFilePath) == false) {
		// Error Message
		std::cerr << "Unable to load sound from file '" << _soundFilePath << "'!\n";
		return false; // Loading Failed
	}

	// Add the Sound Buffer to the Sound Buffer Map
	this->m_soundBuffers[_soundName] = soundBuffer;

	// Loading Successful
	return true;
}

bool SoundManager::playSound(std::string _soundName, float _pitch) {
	// Iterate through the Sound Buffer Map to find the given Sound Name
	std::unordered_map<std::string, sf::SoundBuffer>::iterator soundBufferIterator = this->m_soundBuffers.find(_soundName);

	// Iterator did NOT find a matching key to the given Sound Name
	if (soundBufferIterator == this->m_soundBuffers.end()) {
		// Error Message
		std::cerr << "Unable to find '" << _soundName << "' in the Sound Buffer Map!\n";
		return false; // Sound Failed to Play
	}

	// Create Sound from the Sound Buffer
	sf::Sound sound(soundBufferIterator->second);

	// Set the Volume and Pitch
	GameSettings* settings = GameSettings::getInstance(); // Game Setings
	float masterVolumePercentage = static_cast<float>(settings->m_masterVolume) / 100.0f; // Master Volume Percentage Float
	float effectsVolume = static_cast<float>(settings->m_effectsVolume); // Effects Volume Float
	sound.setVolume(effectsVolume / masterVolumePercentage); // Setting the Volume
	sound.setPitch(_pitch); // Setting the Pitch
	sound.play(); // Playing the Sound

	// Add to the Active Playing Sounds list
	this->m_activeSounds.push_back(sound);

	// Sound Successfully Played
	return true;
}

void SoundManager::playMusic(std::string _musicFilePath, bool _loop) {
	// Stop and Delete any existing Playing Music
	this->stopMusic();

	// Background Music
	this->m_backgroundMusic = new sf::Music();

	// Load Music from the given File Path
	if (this->m_backgroundMusic->openFromFile(_musicFilePath) == false) {
		// Error Message
		std::cerr << "Unable to load music from file '" << _musicFilePath << "'!\n";
		return; // Loading Failed
	}

	// Setting the Volume and the Loop
	GameSettings* settings = GameSettings::getInstance(); // Game Setings
	float masterVolumePercentage = static_cast<float>(settings->m_masterVolume) / 100.0f; // Master Volume Percentage Float
	float musicVolume = static_cast<float>(settings->m_musicVolume); // Music Volume Float
	this->m_backgroundMusic->setVolume(musicVolume / masterVolumePercentage); // Setting the Volume
	this->m_backgroundMusic->setLooping(_loop); // Setting the Loop
	this->m_backgroundMusic->play(); // Play the Background Music
}

void SoundManager::stopMusic() {
	// Ensure that Background Music exists
	if (this->m_backgroundMusic != nullptr) {
		// Stop Music
		this->m_backgroundMusic->stop();

		// Delete Background Music
		delete(this->m_backgroundMusic);
		this->m_backgroundMusic = nullptr;
	}
}
