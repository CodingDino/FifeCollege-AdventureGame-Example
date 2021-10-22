#pragma once

#include <string>
#include <vector>
#include "Thing.h"

// Forward declaration for Player
class Player;
class Monster;

class Area : public Thing
{
public:

	// Constructors/Destructors
	Area(std::string newName, std::string newDescription);
	~Area();

	// Actions
	void Look();
	void LookAtContents(std::string target);
	void Go(Player* thePlayer, std::string target);
	void AttackContents(std::string target, Player* thePlayer);

	// Setup
	void AddExit(Area* exitToAdd);
	void AddMonster(Monster* monsterToAdd);

private:

	// Data
	std::vector<Area*> exits;
	std::vector<Monster*> monsters;
};

