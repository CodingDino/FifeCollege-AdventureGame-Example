#include "Lock.h"
#include <iostream>

Lock::Lock(std::string newName, std::string newDescription, Area* newArea, Area* newExit)
	: Feature				(newName, newDescription)
	, area					(newArea)
	, exit					(newExit)
	, locked				(true)
{
}

Lock::~Lock()
{
}

void Lock::Unlock()
{
	if (locked)
	{
		locked = false;
		area->AddExit(exit);

		std::cout << "The lock opens, revealing a path to " << exit->GetName() << "!" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The lock is already open - the path to " << exit->GetName() << " is clear!" << std::endl << std::endl;
	}
}
