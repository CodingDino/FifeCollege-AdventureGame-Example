#pragma once

#include <string>
#include "Creature.h"

// Forward declaration for Area
class Area;

class Player : public Creature
{

public:

	// Constructors/Destructors
	Player(std::string newName, std::string newDescription);
	~Player();

	// Getters
	Area* GetCurrentArea();

	// Setters
	void SetCurrentArea(Area* newCurrentArea);

private:

	// Data
	Area* currentArea;
};

