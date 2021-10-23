#pragma once
#include "Item.h"

// Forward Declarations
class Lock;

class Key :
    public Item
{
public:

	// Constructors/Destructors
	Key(std::string newName, std::string newDescription, Lock* newLock);
	virtual ~Key();

	// Actions
	void Use(Thing* target);

private:

	Lock* myLock;
};

