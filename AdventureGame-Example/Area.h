#pragma once

#include <string>
#include <vector>

// Forward declaration for Player
class Player;
class Monster;

class Area
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

	// Getters
	std::string GetName();

private:

	// Data
	std::string name;
	std::string description;
	std::vector<Area*> exits;
	std::vector<Monster*> monsters;
};

