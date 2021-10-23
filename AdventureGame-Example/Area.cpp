#include "Area.h"

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "Feature.h"

Area::Area(std::string newName, std::string newDescription)
	: Thing		(newName, newDescription)
	, exits		()
	, monsters	()
	, items		()
	, features	()
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

	for (int i = 0; i < items.size(); ++i)
	{
		std::cout << "There is a " << items[i]->GetName() << " here." << std::endl;
	}
	std::cout << "Exits:" << std::endl;
	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << "     " << exits[i]->GetName() << std::endl;
	}
	std::cout << std::endl;
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

void Area::AddExit(Area* exitToAdd)
{
	exits.push_back(exitToAdd);
}

void Area::AddMonster(Monster* monsterToAdd)
{
	monsters.push_back(monsterToAdd);
}

void Area::AddItem(Item* itemToAdd)
{
	items.push_back(itemToAdd);
}

void Area::RemoveItem(Item* itemToRemove)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (itemToRemove == items[i])
		{
			items.erase(items.begin() + i); // Removes the item from the room, as it's in the player's inventory now.
			return;
		}
	}
}

void Area::AddFeature(Feature* featureToAdd)
{
	features.push_back(featureToAdd);
}

Thing* Area::GetFromContents(std::string target)
{
	if (target == GetName() || target == "area")
		return this;
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (target == monsters[i]->GetName())
		{
			return monsters[i];
		}
	}
	for (int i = 0; i < items.size(); ++i)
	{
		if (target == items[i]->GetName())
		{
			return items[i];
		}
	}
	for (int i = 0; i < features.size(); ++i)
	{
		if (target == features[i]->GetName())
		{
			return features[i];
		}
	}
	return nullptr;
}
