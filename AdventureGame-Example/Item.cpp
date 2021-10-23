#include "Item.h"
#include <iostream>

Item::Item(std::string newName, std::string newDescription)
	: Thing		(newName, newDescription)
{
}

Item::~Item()
{
}

void Item::Use(Thing* target)
{
	std::cout << "You use the " << GetName() << " on " << target->GetName() << "." << std::endl;
	std::cout << "Nothing happens." << std::endl << std::endl;
}
