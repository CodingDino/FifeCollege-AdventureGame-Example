#pragma once

#include <string>

class Thing
{

public:

	// Constructors/Destructors
	Thing(std::string newName, std::string newDescription);
	~Thing();

	// Actions
	virtual void Look();

	// Getter
	std::string GetName();

private:

	// Data
	std::string name;
	std::string description;
};

