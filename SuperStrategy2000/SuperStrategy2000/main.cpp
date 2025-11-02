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

#include "WindowManager.h"

int main() {
    // Start the Window Manager Process
    WindowManager::getInstance()->process();

    return 0;
}