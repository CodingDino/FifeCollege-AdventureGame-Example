#pragma once

#include <string>
#include <vector>
#include "Thing.h"

// Forward declarations
class Player;
class Monster;
class Item;
class Feature;

class Area : public Thing
{
public:

	// Constructors/Destructors
	Area(std::string newName, std::string newDescription);
	virtual ~Area();

	// Actions
	void Look();
	void Go(Player* thePlayer, std::string target);

	// Setup
	void AddExit(Area* exitToAdd);
	void AddMonster(Monster* monsterToAdd);
	void AddItem(Item* itemToAdd);
	void RemoveItem(Item* itemToRemove);
	void AddFeature(Feature* featureToAdd);

	// Getters
	Thing* GetFromContents(std::string target);

private:

	// Data
	std::vector<Area*> exits;
	std::vector<Monster*> monsters;
	std::vector<Item*> items;
	std::vector<Feature*> features;
};

