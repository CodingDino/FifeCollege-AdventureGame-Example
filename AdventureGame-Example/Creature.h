#pragma once

#include "Thing.h"

class Creature :
    public Thing
{
public:

	// Constructors/Destructors
	Creature(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Creature();

	// Actions
	virtual void Look();

	// Getter
	bool GetAlive();
	int GetAttack();
	void DealDamage(int damageToDeal);

private:

	// Data
	int currentHealth;
	int maxHealth;
	int attack;
};

