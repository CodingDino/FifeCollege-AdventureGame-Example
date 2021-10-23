#include "Weapon.h"

Weapon::Weapon(std::string newName, std::string newDescription, int newAttackValue)
	: Equipment		(newName, newDescription)
	, attackValue	(newAttackValue)
{
}

Weapon::~Weapon()
{
}

int Weapon::GetAttackValue()
{
	return attackValue;
}
