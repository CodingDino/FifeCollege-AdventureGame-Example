#pragma once
#include "Thing.h"


class Item :
    public Thing
{
public:

	// Constructors/Destructors
	Item(std::string newName, std::string newDescription);
	virtual ~Item();

	// Actions
	virtual void Use(Thing* target);

};

