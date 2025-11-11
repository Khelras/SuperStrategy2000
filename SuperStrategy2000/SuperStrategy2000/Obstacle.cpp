/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Obstacle.h
Description : Declares the Obstacle Class Functions and Properties. Derives from the Actor Class.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Obstacle.h"
#include "GameManager.h"
#include "GameSettings.h"

Obstacle::Obstacle() {
	// Set the Actor Type and the Actor Sprite
	this->setActorType(Actor::Type::OBSTACLE);
	this->setActorSprite(1); 
}

Obstacle::~Obstacle() {
}
