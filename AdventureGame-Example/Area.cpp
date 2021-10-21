#include "Area.h"

#include <iostream>

Area::Area(std::string newName, std::string newDescription)
	: name			(newName)
	, description	(newDescription)
	, exit			("")
{
}

Area::~Area()
{
}

void Area::Look()
{
	std::cout << "You look around at the " << name << "." << std::endl;
	std::cout << description << std::endl;
	std::cout << "Exits:" << std::endl;
	std::cout << "     " << exit << std::endl << std::endl;
}
