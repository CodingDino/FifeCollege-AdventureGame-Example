#pragma once

#include <string>

class Player;

class Monster
{

public:

	// Constructors/Destructors
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Monster();

	// Actions
	void Look();
	void Attack(Player* thePlayer);

	// Getter
	std::string GetName();
	bool GetAlive();

private:

	// Data
	std::string name;
	std::string description;
	int currentHealth;
	int maxHealth;
	int attack;
};

