/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name   : Level.cpp
Description : Defines the Level Class Functions and Properties.
Author      : Angelo Joseph Arawiran Bohol
Mail        : angelo.bohol@mds.ac.nz
**************************************************************************/

#include "Level.h"
#include "TurnController.h"

Level::Level(unsigned int _levelNumber, std::ifstream& _gridFile) {
	this->m_levelNumber = _levelNumber;
	this->m_levelGameBoard = new Grid(_gridFile);
	this->m_levelCurrentUnit = nullptr;

	// After constructing the Game Board Grid
	if (this->m_levelGameBoard != nullptr) {
		// Loop through each Square on the Game Board and collect the Actors
		for (const auto& row : this->m_levelGameBoard->m_grid) { // Loop down each Row
			for (const auto& square : row) { // Loop through each Square on this Row
				// Square has an Actor on it
				if (square->m_actorOnSquare != nullptr) {
					// Add the Actor to the Actors Array
					this->m_levelActors.push_back(square->m_actorOnSquare);

					// Check if this is a Unit
					if (square->m_actorOnSquare->getActorType() != Actor::Type::OBSTACLE) {
						// Downcast Actor Class to Unit Class
						Unit* unit = dynamic_cast<Unit*>(square->m_actorOnSquare);

						// Add the Unit to the Units Array
						this->m_levelUnits.push_back(unit);
					}
				}
			}
		}

		// Queues
		std::queue<Unit*> playerKnights; // All Player Knights Present
		std::queue<Unit*> enemyKnights; // All Enemy Knights Present
		std::queue<Unit*> playerArchers; // All Player Archers Present
		std::queue<Unit*> enemyArchers; // All Enemy Archers Present
		std::queue<Unit*> playerMages; // All Player Mages Present
		std::queue<Unit*> enemyMages; // All Enemy Mages Present

		// Sort into their repsective queue
		for (const auto& unit : this->m_levelUnits) {
			switch (unit->getActorType()) {
				case (Actor::Type::UNIT_PLAYER_KNIGHT): { playerKnights.push(unit); } break;
				case (Actor::Type::UNIT_ENEMY_KNIGHT): { enemyKnights.push(unit); } break;
				case (Actor::Type::UNIT_PLAYER_ARCHER): { playerArchers.push(unit); } break;
				case (Actor::Type::UNIT_ENEMY_ARCHER): { enemyArchers.push(unit); } break;
				case (Actor::Type::UNIT_PLAYER_MAGE): { playerMages.push(unit); } break;
				case (Actor::Type::UNIT_ENEMY_MAGE): { enemyMages.push(unit); } break;
				default: { continue; } break;
			}
		}

		// Unit Count
		this->m_totalEnemies = static_cast<int>(enemyKnights.size() + enemyArchers.size() + enemyMages.size());
		this->m_totalPlayers = static_cast<int>(playerKnights.size() + playerArchers.size() + playerMages.size());

		// Construct the Turn Order
		while (playerKnights.empty() == false || enemyKnights.empty() == false ||
			playerArchers.empty() == false || enemyArchers.empty() == false ||
			playerMages.empty() == false || enemyMages.empty() == false) {
			// Player Knights
			if (playerKnights.empty() == false) {
				this->m_levelTurnOrder.push(playerKnights.front());
				playerKnights.pop();
			}
			
			// Enemy Knights
			if (enemyKnights.empty() == false) {
				this->m_levelTurnOrder.push(enemyKnights.front());
				enemyKnights.pop();
			}
			
			// Player Archers
			if (playerArchers.empty() == false) {
				this->m_levelTurnOrder.push(playerArchers.front());
				playerArchers.pop();
			}
			
			// Enemy Archers
			if (enemyArchers.empty() == false) {
				this->m_levelTurnOrder.push(enemyArchers.front());
				enemyArchers.pop();
			}
			
			// Player Mages
			if (playerMages.empty() == false) {
				this->m_levelTurnOrder.push(playerMages.front());
				playerMages.pop();
			}
			
			// Enemy Mages
			if (enemyMages.empty() == false) {
				this->m_levelTurnOrder.push(enemyMages.front());
				enemyMages.pop();
			}
		}

		this->m_levelCurrentUnit = this->m_levelTurnOrder.front();
	}
	else {
		// Error Message
		std::cerr << "Game Board Grid in Level " << this->m_levelNumber << " failed to construct!\n";
	}
}

Level::~Level() {
	// Ensure Game Board exists
	if (this->m_levelGameBoard != nullptr) {
		// Delete Game Board
		delete (this->m_levelGameBoard);
	}

	// Delete all the Actors
	for (auto& actor : this->m_levelActors) {
		// Ensure Actor exists
		if (actor != nullptr) {
			// Delete Actor
			delete(actor);
			actor = nullptr;
		}
	}

	// Clear Actor and Unit Arrays
	this->m_levelActors.clear();
	this->m_levelUnits.clear();
}

void Level::process() {
	// Game Board Grid Process Loop
	this->m_levelGameBoard->process();

	// Until Turn is Done
	if (TurnController::getInstance()->m_turnState != TurnController::TurnStates::DONE && 
		this->m_levelCurrentUnit->getActorType() != Actor::Type::UNIT_ENEMY_KNIGHT &&
		this->m_levelCurrentUnit->getActorType() != Actor::Type::UNIT_ENEMY_ARCHER &&
		this->m_levelCurrentUnit->getActorType() != Actor::Type::UNIT_ENEMY_MAGE) {
		// Ensure that the Current Unit is the First in the Turn Order
		this->m_levelCurrentUnit = this->m_levelTurnOrder.front();

		// Select the Square with the Current Unit
		this->m_levelGameBoard->selectSquare(this->m_levelCurrentUnit);

		// Moving Turn State
		if (TurnController::getInstance()->m_turnState == TurnController::TurnStates::MOVING) {
			// Select the Square with the Current Unit
			this->m_levelGameBoard->selectSquare(this->m_levelCurrentUnit);

			// Show this Units Movement Range
			this->m_levelGameBoard->breadthFirstSearch(
				this->m_levelGameBoard->m_selectedSquare,
				static_cast<int>(this->m_levelCurrentUnit->getUnitSpeed()),
				true
			);
		}
		// Basic Attack Turn State
		else if (TurnController::getInstance()->m_turnState == TurnController::TurnStates::BASIC) {
			// Select the Square
			this->m_levelGameBoard->selectSquare(this->m_levelCurrentUnit);

			// Show this Units Attack Range
			this->m_levelGameBoard->breadthFirstSearch(
				this->m_levelGameBoard->m_selectedSquare,
				static_cast<int>(this->m_levelCurrentUnit->getUnitRange()),
				false
			);
		}
	}
	// Turn is Done
	else {
		// Output to Console
		std::cout << this->m_levelCurrentUnit->getUnitName() << " turn ended!" << std::endl;

		// Put the Front Unit to the Back of the Queue
		this->m_levelTurnOrder.push(this->m_levelTurnOrder.front()); // Push Front Unit to the Back
		this->m_levelTurnOrder.pop(); // Remove the Front Unit

		// Evaluate the next Unit whether they are dead or not
		while (this->m_levelTurnOrder.front()->getUnitCurrentHealth() <= 0) {
			// Death Message
			std::cout << this->m_levelTurnOrder.front()->getUnitName();
			std::cout << " is dead!" << std::endl;

			// Update Death Count
			if (this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_PLAYER_KNIGHT ||
				this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_PLAYER_ARCHER ||
				this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_PLAYER_MAGE) {
				// Player Death Count
				this->m_deadPlayers++;
			} 
			else if (this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_ENEMY_KNIGHT ||
				this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_ENEMY_ARCHER ||
				this->m_levelTurnOrder.front()->getActorType() == Actor::Type::UNIT_ENEMY_MAGE) {
				// Enemy Death Count
				this->m_deadEnemies++;
			}

			// Remove the Front Unit
			this->m_levelTurnOrder.pop(); 
		}

		// Death Count Message
		std::cout << this->m_totalEnemies - this->m_deadEnemies << " enemies remain!" << std::endl;
		std::cout << this->m_totalPlayers - this->m_deadPlayers << " players remain!" << std::endl;

		this->m_levelCurrentUnit = this->m_levelTurnOrder.front(); // New Current Unit
		TurnController::getInstance()->reset(); // Reset the Turn Controller

		// Output to Console
		std::cout << std::endl << std::endl << std::endl;
		std::cout << this->m_levelCurrentUnit->getUnitName() << " turn!" << std::endl;
	}
}

void Level::drawLevel(sf::RenderWindow& _window) {
	// First draw the Game Board Grid Background
	_window.draw(this->m_levelGameBoard->m_gridBackground);

	// Draw each Square on the Game Board Grid and any Actors sitting on it
	for (int y = 0; y < this->m_levelGameBoard->m_gridSize.y; y++) { // Loop down the y-axis
		for (int x = 0; x < this->m_levelGameBoard->m_gridSize.x; x++) { // Loop down the x-axis
			// The Square
			Square* square = this->m_levelGameBoard->m_grid[y][x];
			_window.draw(square->m_squareShape); // Draw the Square Shape

			// If an Actor is sitting on this Square
			if (square->m_actorOnSquare != nullptr) {
				// Ensure that the Actor Sprite exists
				if (square->m_actorOnSquare->getActorSprite() != nullptr) {

					// Draw the Actor Sprite
					_window.draw(*(square->m_actorOnSquare->getActorSprite()));
				}
			}
		}
	}
}
