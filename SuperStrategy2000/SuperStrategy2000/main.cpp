/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : main.cpp
Description : Starts the Game
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "GameManager.h"

int main() {
    // Start the Game Manager Process
    GameManager::getInstance()->process();

    return 0;
}