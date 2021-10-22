#include "Monster.h"

#include <iostream>
#include "Player.h"

Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Creature (newName, newDescription, newHealth, newAttack)
{

}

Monster::~Monster()
{
}


void Monster::Attack(Player* thePlayer)
{
	if (!GetAlive())
	{
		// It's dead! announce it.
		std::cout << "It's already dead, Jim! You can't attack it anymore!" << std::endl << std::endl;
		return;
	}

	std::cout << "You attack " << GetName() << "!" << std::endl;
	int damageToMonster = thePlayer->GetAttack();
	std::cout << "You deal " << damageToMonster << " damage." << std::endl;
	DealDamage(damageToMonster);
	if (!GetAlive())
	{
		// It's dead! announce it.
		std::cout << GetName() << " is killed!" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The " << GetName() << " attacks you for " << GetAttack() << " damage." << std::endl << std::endl;
		thePlayer->DealDamage(GetAttack());
	}
}


