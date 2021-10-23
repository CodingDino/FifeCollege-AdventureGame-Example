#pragma once
#include "Equipment.h"
class Weapon :
    public Equipment
{

public:

	// Constructors/Destructors
	Weapon(std::string newName, std::string newDescription, int newAttackValue);
	virtual ~Weapon();

	// Getters
	int GetAttackValue();

private:

	int attackValue;
};

