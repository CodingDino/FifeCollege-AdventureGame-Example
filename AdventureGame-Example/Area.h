#pragma once

#include <string>

class Area
{
public:

	// Constructors/Destructors
	Area(std::string newName, std::string newDescription);
	~Area();

	// Actions
	void Look();

	// Data
	std::string name;
	std::string description;
	std::string exit;
};

