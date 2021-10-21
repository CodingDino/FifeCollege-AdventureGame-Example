#include "Area.h"

#include <iostream>
#include "Player.h"

Area::Area(std::string newName, std::string newDescription)
	: name			(newName)
	, description	(newDescription)
	, exits			()
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
	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << "     " << exits[i]->name << std::endl;
	}
	std::cout << std::endl;
}

void Area::Go(Player* thePlayer, std::string target)
{
	for (int i = 0; i < exits.size(); ++i)
	{
		if (target == exits[i]->name)
		{
			std::cout << "You go to " << target << std::endl << std::endl;
			thePlayer->currentArea = exits[i];
			return;
		}
	}
	std::cout << "Sorry, I didn't understand the target \"" << target << "\"" << std::endl;
	std::cout << "Try looking at the area around you and going to one of the connected areas." << std::endl << std::endl;
}
