#include "Armor.h"

Armor::Armor(std::string newName, std::string newDescription, int newArmorValue)
	: Equipment		(newName, newDescription)
	, armorValue	(newArmorValue)
{
}

Armor::~Armor()
{
}

int Armor::GetArmorValue()
{
	return armorValue;
}
