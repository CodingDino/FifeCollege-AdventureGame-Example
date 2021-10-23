#include "Creature.h"
#include <iostream>

Creature::Creature(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Thing(newName, newDescription)
	, maxHealth(newHealth)
	, currentHealth(newHealth)
	, attack(newAttack)
{
}

Creature::~Creature()
{
}

void Creature::Look()
{
	// Call base class
	Thing::Look();

	if (currentHealth <= 0)
	{
		std::cout << "It is dead." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Heath: " << currentHealth << "/" << maxHealth << std::endl;
		std::cout << "Attack: " << attack << std::endl << std::endl;
	}
}

bool Creature::GetAlive()
{
	return currentHealth > 0;
}

int Creature::GetAttack()
{
	return attack;
}

void Creature::DealDamage(int damageToDeal)
{
	currentHealth -= damageToDeal;
}

void Creature::Heal(int healthToHeal)
{
	currentHealth += healthToHeal;
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}
