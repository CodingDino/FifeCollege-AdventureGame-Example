#include "Monster.h"

#include <iostream>
#include "Player.h"

Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: name(newName)
	, description(newDescription)
	, maxHealth(newHealth)
	, currentHealth(newHealth)
	, attack(newAttack)
{

}

Monster::~Monster()
{
}

void Monster::Look()
{
	std::cout << "You look at the " << name << "." << std::endl;
	std::cout << description << std::endl;
	if (currentHealth <= 0)
	{
		std::cout << "It is dead."<< std::endl << std::endl;
	}
	else
	{
		std::cout << "Heath: " << currentHealth << "/" << maxHealth << std::endl;
		std::cout << "Attack: " << attack << std::endl << std::endl;
	}

}

void Monster::Attack(Player* thePlayer)
{
	if (currentHealth <= 0)
	{
		// It's dead! announce it.
		std::cout << "It's already dead, Jim! You can't attack it anymore!" << std::endl << std::endl;
		return;
	}

	std::cout << "You attack " << name << "!" << std::endl;
	int damageToMonster = thePlayer->GetAttack();
	std::cout << "You deal " << damageToMonster << " damage." << std::endl;
	currentHealth -= damageToMonster;
	if (currentHealth <= 0)
	{
		// It's dead! announce it.
		std::cout << name << " is killed!" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The " << name << " attacks you for " << attack << " damage." << std::endl << std::endl;
		thePlayer->DealDamage(attack);
	}
}

std::string Monster::GetName()
{
	return name;
}

bool Monster::GetAlive()
{
	return currentHealth > 0;
}


