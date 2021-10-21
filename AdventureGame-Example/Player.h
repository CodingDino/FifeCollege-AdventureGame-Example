#pragma once

#include <string>

// Forward declaration for Area
class Area;

class Player
{

public:

	// Constructors/Destructors
	Player(std::string newName, std::string newDescription);
	~Player();

	// Actions
	void Look();

	// Data
	std::string name;
	std::string description;
	int currentHealth;
	int maxHealth;
	int attack;
	Area* currentArea;
};

