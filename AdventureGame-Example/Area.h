#pragma once

#include <string>
#include <vector>

// Forward declaration for Player
class Player;

class Area
{
public:

	// Constructors/Destructors
	Area(std::string newName, std::string newDescription);
	~Area();

	// Actions
	void Look();
	void Go(Player* thePlayer, std::string target);

	// Data
	std::string name;
	std::string description;
	std::vector<Area*> exits;
};

