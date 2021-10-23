#pragma once
#include "Feature.h"
#include "Area.h"

class Lock :
    public Feature
{

public:

	// Constructors/Destructors
	Lock(std::string newName, std::string newDescription, Area* newArea, Area* newExit);
	virtual ~Lock();

	// Actions
	void Unlock();

private:

	Area* area;
	Area* exit;
	bool locked;

};

