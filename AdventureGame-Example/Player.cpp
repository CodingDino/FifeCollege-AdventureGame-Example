#include "Player.h"
#include <iostream>
#include "Item.h"
#include "Area.h"
#include "Armor.h"
#include "Weapon.h"

Player::Player(std::string newName, std::string newDescription)
	: Creature			(newName, newDescription, 100, 10)
	, currentArea		(nullptr)
	, items				()
	, equippedWeapon	(nullptr)
	, equippedArmor		(nullptr)
{
}

Player::~Player()
{
}

void Player::Look()
{
	Creature::Look();

	int numItems = items.size();
	if (numItems == 0)
		std::cout << "You have no items." << std::endl << std::endl;
	if (numItems == 1)
		std::cout << "You have a " << items[0]->GetName() << "." << std::endl << std::endl;
	else
	{
		std::cout << "You have " << numItems << " items:" << std::endl;
		for (int i = 0; i < items.size(); ++i)
		{
			std::cout << "     " << items[i]->GetName() << std::endl;
		}
		std::cout << std::endl;
	}
}

void Player::UseItemFromInventory(std::string target)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (target == items[i]->GetName())
		{
			std::string choice;

			std::cout << "Use " << target << " on what?" << std::endl << std::endl;
			std::cin >> choice;

			// Check if the player has the target
			Thing* targetThing = GetFromContents(choice);
			if (targetThing != nullptr)
			{
				items[i]->Use(targetThing);
				return;
			}

			// Check if the area has the target
			targetThing = currentArea->GetFromContents(choice);
			if (targetThing != nullptr)
			{
				items[i]->Use(targetThing);
				return;
			}

			// No target found, print error text and do nothing.
			std::cout << "Sorry, I couldn't understand the target \"" << choice << "\"." << std::endl;
			std::cout << "Try looking around to see what you could target." << std::endl << std::endl;

			return;
		}
	}

	// Couldn't find a target in inventory
	std::cout << "Sorry, you dont seem to have a \"" << target << "\" to use." << std::endl;
	std::cout << "Try looking at \"self\" to see your inventory, or \"take\" an item from the area around you if you don't have one." << std::endl << std::endl;
}

void Player::Equip(std::string target)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (target == items[i]->GetName())
		{
			Weapon* targetWeapon = dynamic_cast<Weapon*>(items[i]);
			Armor* targetArmor = dynamic_cast<Armor*>(items[i]);
			if (targetWeapon != nullptr)
			{
				// put on weapon

				// Remove existing weapon bonus if present
				if (equippedWeapon != nullptr)
				{
					attack -= targetWeapon->GetAttackValue();
				}
				equippedWeapon = targetWeapon;
				attack += targetWeapon->GetAttackValue();
				std::cout << "You weild the \"" << target << "\" in both hands and feel much stronger." << std::endl;
				std::cout << "Your attack is now " << targetWeapon->GetAttackValue() << " higher!" << std::endl << std::endl;
			}
			else if (targetArmor != nullptr)
			{
				// put on armor

				// Remove existing weapon bonus if present
				if (equippedArmor != nullptr)
				{
					maxHealth -= targetArmor->GetArmorValue();
					currentHealth -= targetArmor->GetArmorValue();
				}
				equippedArmor = targetArmor;
				maxHealth += targetArmor->GetArmorValue();
				currentHealth += targetArmor->GetArmorValue();
				std::cout << "You put on the \"" << target << "\" and feel much safer." << std::endl;
				std::cout << "Your health is now " << targetArmor->GetArmorValue() << " higher!" << std::endl << std::endl;
			}
			else
			{
				// The target item was not a valid target.
				std::cout << "Sorry, you can't equip the item \"" << target << "\"." << std::endl;
				std::cout << "Try using it instead." << std::endl << std::endl;
			}

			return;
		}
	}

	// Couldn't find a target in inventory
	std::cout << "Sorry, you dont seem to have a \"" << target << "\" to equip." << std::endl;
	std::cout << "Try looking at \"self\" to see your inventory, or \"take\" equipment from the area around you if you don't have any." << std::endl << std::endl;

}

void Player::AddItem(Item* itemToAdd)
{
	items.push_back(itemToAdd);
}

Area* Player::GetCurrentArea()
{
	return currentArea;
}

Thing* Player::GetFromContents(std::string target)
{
	if (target == GetName() || target == "self")
		return this;

	for (int i = 0; i < items.size(); ++i)
	{
		if (target == items[i]->GetName())
		{
			return items[i];
		}
	}

	return nullptr;
}

void Player::SetCurrentArea(Area* newCurrentArea)
{
	currentArea = newCurrentArea;
}
