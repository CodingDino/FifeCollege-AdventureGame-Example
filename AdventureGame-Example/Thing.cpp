#include "Thing.h"
#include <iostream>

Thing::Thing(std::string newName, std::string newDescription)
	: name			(newName)
	, description	(newDescription)
{
}

Thing::~Thing()
{
}

void Thing::Look()
{
	std::cout << "You look at " << name << "." << std::endl;
	std::cout << description << std::endl << std::endl;
}

std::string Thing::GetName()
{
	return name;
}
