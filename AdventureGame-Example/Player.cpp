#include "Player.h"
#include <iostream>

Player::Player(std::string newName, std::string newDescription)
	: Creature		(newName, newDescription, 100, 10)
	, currentArea	(nullptr)
{
}

Player::~Player()
{
}

Area* Player::GetCurrentArea()
{
	return currentArea;
}

void Player::SetCurrentArea(Area* newCurrentArea)
{
	currentArea = newCurrentArea;
}
