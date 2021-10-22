#pragma once

#include <string>
#include "Creature.h"

class Player;

class Monster : public Creature
{

public:

	// Constructors/Destructors
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);
	virtual ~Monster();

	// Actions
	void Attack(Player* thePlayer);

};

