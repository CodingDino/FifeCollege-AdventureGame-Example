#include "Area.h"

#include <iostream>
#include "Player.h"
#include "Monster.h"

Area::Area(std::string newName, std::string newDescription)
	: Thing		(newName, newDescription)
	, exits		()
{
}

Area::~Area()
{
}

void Area::Look()
{
	// Call base class
	Thing::Look();

	for (int i = 0; i < monsters.size(); ++i)
	{
		std::cout << "There is a ";
		if (!monsters[i]->GetAlive())
			std::cout << "dead ";
		std::cout << monsters[i]->GetName() << " here." << std::endl;

	}
	std::cout << "Exits:" << std::endl;
	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << "     " << exits[i]->GetName() << std::endl;
	}
	std::cout << std::endl;
}

void Area::LookAtContents(std::string target)
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (target == monsters[i]->GetName())
		{
			monsters[i]->Look();
			return;
		}
	}

	// Couldn't find a target in this room.

	std::cout << "Sorry, I didn't understand the target \"" << target << "\"" << std::endl;
	std::cout << "Try looking at the area around you, yourself, or a specific item, feature, or monster!" << std::endl << std::endl;

}

void Area::Go(Player* thePlayer, std::string target)
{
	for (int i = 0; i < exits.size(); ++i)
	{
		if (target == exits[i]->GetName())
		{
			std::cout << "You go to " << target << std::endl << std::endl;
			thePlayer->SetCurrentArea(exits[i]);
			return;
		}
	}
	std::cout << "Sorry, I didn't understand the target \"" << target << "\"" << std::endl;
	std::cout << "Try looking at the area around you and going to one of the connected areas." << std::endl << std::endl;
}

void Area::AttackContents(std::string target, Player* thePlayer)
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (target == monsters[i]->GetName())
		{
			monsters[i]->Attack(thePlayer);
			return;
		}
	}

	// Couldn't find a target in this room.
	std::cout << "Sorry, I didn't understand the target \"" << target << "\"" << std::endl;
	std::cout << "Try looking at the area around you to see what targets you might find!" << std::endl << std::endl;
}

void Area::AddExit(Area* exitToAdd)
{
	exits.push_back(exitToAdd);
}

void Area::AddMonster(Monster* monsterToAdd)
{
	monsters.push_back(monsterToAdd);
}
