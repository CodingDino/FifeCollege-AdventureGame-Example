#include "Potion.h"
#include <iostream>
#include "Creature.h"
#include "Player.h"

Potion::Potion(std::string newName, std::string newDescription, int newHealing)
	: Item		(newName, newDescription)
	, healing	(newHealing)
	, used		(false)
{
}

Potion::~Potion()
{
}

void Potion::Look()
{
	Thing::Look();

	if (used)
		std::cout << "It's use up." << std::endl << std::endl;
}

void Potion::Use(Thing* target)
{
	Creature* targetCreature = dynamic_cast<Creature*>(target);
	if (targetCreature != nullptr)
	{
		std::cout << "You use the " << GetName() << " on " << target->GetName() << "." << std::endl;
		std::cout << target->GetName() << " is healed by " << healing << "!" << std::endl;
		targetCreature->Heal(healing);
	}
}
