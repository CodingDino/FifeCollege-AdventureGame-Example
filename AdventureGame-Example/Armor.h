#pragma once
#include "Equipment.h"

class Armor :
    public Equipment
{

public:

	// Constructors/Destructors
	Armor(std::string newName, std::string newDescription, int newArmorValue);
	virtual ~Armor();

	// Getters
	int GetArmorValue();

private:

	int armorValue;
};

