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
	void DealDamage(int damageToDeal);

	// Getters
	Area* GetCurrentArea();
	int GetAttack();
	bool GetAlive();

	// Setters
	void SetCurrentArea(Area* newCurrentArea);

private:

	// Data
	std::string name;
	std::string description;
	int currentHealth;
	int maxHealth;
	int attack;
	Area* currentArea;
};

