#include "Equipment.h"
#include <iostream>

Equipment::Equipment(std::string newName, std::string newDescription)
	: Item(newName, newDescription)
{
}

Equipment::~Equipment()
{
}

void Equipment::Use(Thing* target)
{
	std::cout << "This " << GetName() << " is Equipment. You can't use it, but you can \"equip\" it!" << std::endl << std::endl;
}
