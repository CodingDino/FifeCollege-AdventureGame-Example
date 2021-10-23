#pragma once
#include "Item.h"
class Equipment :
    public Item
{
public:

	// Constructors/Destructors
	Equipment(std::string newName, std::string newDescription);
	virtual ~Equipment();

	// Actions
	virtual void Use(Thing* target);
};

