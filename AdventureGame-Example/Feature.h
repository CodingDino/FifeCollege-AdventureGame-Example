#pragma once
#include "Thing.h"

class Feature :
    public Thing

{
public:

	// Constructors/Destructors
	Feature(std::string newName, std::string newDescription);
	virtual ~Feature();

};

