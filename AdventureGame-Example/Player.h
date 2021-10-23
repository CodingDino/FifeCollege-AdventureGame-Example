#pragma once

#include <string>
#include <vector>
#include "Creature.h"

// Forward declarations
class Area;
class Item;

class Player : public Creature
{

public:

	// Constructors/Destructors
	Player(std::string newName, std::string newDescription);
	virtual ~Player();

	// Actions
	void Look();
	void UseItemFromInventory(std::string target);

	// Setup
	void AddItem(Item* itemToAdd);

	// Getters
	Area* GetCurrentArea();
	Thing* GetFromContents(std::string target);

	// Setters
	void SetCurrentArea(Area* newCurrentArea);

private:

	// Data
	Area* currentArea;
	std::vector<Item*> items;
};

