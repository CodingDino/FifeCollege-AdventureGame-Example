#pragma once
#include "Item.h"

class Potion :
    public Item
{

public:

	// Constructors/Destructors
	Potion(std::string newName, std::string newDescription, int newhealing);
	virtual ~Potion();

	// Actions
	void Look();
	void Use(Thing* target);

private:

	bool used;
	int healing;
};

