#include "Key.h"

#include "Lock.h"
#include <iostream>

Key::Key(std::string newName, std::string newDescription, Lock* newLock)
	: Item		(newName, newDescription)
	, myLock	(newLock)
{
}

Key::~Key()
{
}

void Key::Use(Thing* target)
{
	if (target == myLock)
	{
		std::cout << "You turn the " << GetName() << " in the " << myLock->GetName() <<"..." << std::endl;
		myLock->Unlock();
	}
	else
	{
		std::cout << "This " << GetName() << " can't be used on the target \"" << target->GetName() << "\"." << std::endl;
		std::cout << "Look around for the correct target!" << std::endl << std::endl;
	}
}
