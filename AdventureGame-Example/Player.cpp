#include "Player.h"
#include <iostream>

Player::Player(std::string newName, std::string newDescription)
	: name			(newName)
	, description	(newDescription)
	, maxHealth		(100)
	, currentHealth	(100)
	, attack		(10)
	, currentArea	(nullptr)
{
}

Player::~Player()
{
}

void Player::Look()
{
	std::cout << "You look at yourself, " << name << "." << std::endl;
	std::cout << description << std::endl;
	std::cout << "Heath: " << currentHealth << "/" << maxHealth << std::endl;
	std::cout << "Attack: " << attack << std::endl << std::endl;
}

void Player::DealDamage(int damageToDeal)
{
	currentHealth -= damageToDeal;
}

Area* Player::GetCurrentArea()
{
	return currentArea;
}

int Player::GetAttack()
{
	return attack;
}

bool Player::GetAlive()
{
	return currentHealth > 0;
}

void Player::SetCurrentArea(Area* newCurrentArea)
{
	currentArea = newCurrentArea;
}
