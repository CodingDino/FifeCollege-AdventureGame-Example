// AdventureGame-Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Area.h"
#include "Monster.h"
#include "Item.h"
#include "Potion.h"
#include "Key.h"
#include "Feature.h"
#include "Lock.h"
#include "Weapon.h"
#include "Armor.h"

int main()
{

    std::cout << "Welcome to Adventure Game!" << std::endl;

    // NOTE: I create the areas first since the player can then access them for the name.


    // Create some areas
    std::cout << "Generating the word..." << std::endl;
    
    // Setup each area
    Area entrance("Entrance", "A grand entryway with soaring Columns. You see a Hallway ahead.");
    Area hallway("Hallway", "A long, featureless hallway leading into darkness. A large door at the end of the wall has an ornate Lock on it. A large Crack in the wall leads to darkness.");
    Area throneroom("Throneroom", "A huge throneroom shrouded in darkness. A grim purple crystal Throne lies at the center on an obsidian Dais. Tattered red Curtains hang on the walls. Behind you is the Hallway. Above you is the Belfry");
    Area crack("Crack", "A small crack that you can barely squeeze through. It travels between the Hallway and the Chamber.");
    Area chamber("Chamber", "This room is covered in strange, soft Eggs. They are sticky as if covered in web. A Crack leads out.");
    Area belfry("Belfry", "This Belfry is full of Bats. Lots and lots of Bats. Bats in the Belfry. Below you is the Throneroom.");

    // Setup exits for each area
    entrance.AddExit(&hallway);
    hallway.AddExit(&entrance);
    hallway.AddExit(&crack);
    throneroom.AddExit(&hallway);
    throneroom.AddExit(&belfry);
    crack.AddExit(&hallway);
    crack.AddExit(&chamber);
    chamber.AddExit(&crack);
    belfry.AddExit(&throneroom);

    // Create Monsters
    Monster goblin("Goblin", "A smelly green goblin.", 50, 5);
    Monster goblinKing("GoblinKing", "Some kind of rock star with very tight pants.", 200, 50);
    Monster spider("Spider", "A giant spider. Just wants to catch and eat giant flies - your friend, really.", 100, 10);

    hallway.AddMonster(&goblin);
    throneroom.AddMonster(&goblinKing);
    chamber.AddMonster(&spider);

    // Create Features
    Lock ornateLock("Lock", "A fancy and ornate golden lock. It needs an equally ornate key.", &hallway, &throneroom);
    Feature columns("Columns", "These soaring columns are made of marble, and contain carvings. On closer inspection, the carvings are all rude cartoons of goblins.");
    Feature throne("Throne", "The throne is made of purple crystal, and shines earily in the dim light. It gives off a sense of forboding.");
    Feature dais("Dais", "The dais is low and made of a dark obsidian, shiny like glass. It looks slippery.");
    Feature curtains("Curtains", "The red curtains are in tatters - someone really should replace them. They are dusty too, and full of cobwebs - gross.");
    Feature eggs("Eggs", "The eggs are sticky and webby. They are warm to the touch and soft. You feel small movements in side of them, and a tiny chittering sound emenates from them. They give you the willies.");
    Feature bats("Bats", "There are bats here. Lots of them. They squeek, hang upsideown, flutter around, and are generally very cute. If you don't like them, too bad. This is their home, man - don't be rude.");

    hallway.AddFeature(&ornateLock);
    entrance.AddFeature(&columns);
    throneroom.AddFeature(&throne);
    throneroom.AddFeature(&dais);
    throneroom.AddFeature(&curtains);
    chamber.AddFeature(&eggs);
    belfry.AddFeature(&bats);

    // Create items
    Item pebble("Pebble", "A useless pebble");
    Potion smallPotion("Potion", "A bubbling red potion. It smells delicious.", 50);
    Potion healingCrystal("Crystal", "A shining crystal the size of your fist that gives off a warm healing feeling.", 100);
    Key ornateKey("Key", "An ornate golden key that looks to be for an equally ornate lock.", &ornateLock);
    Weapon masterSword("Sword", "A sword made of glittering diamond. It looks almost too big to lift, but is surprisingly light. Glows with a magical light.", 100);
    Armor goldArmor("Armor", "This breastplate appears to be made of pure gold. But rather than be soft and easy to bend, it seems as hard as adamantine.", 100);

    entrance.AddItem(&pebble);
    hallway.AddItem(&smallPotion);
    chamber.AddItem(&healingCrystal);
    chamber.AddItem(&ornateKey);
    belfry.AddItem(&masterSword);
    belfry.AddItem(&goldArmor);

    // Create the player
    std::cout << "Please name your character: " << std::endl;
    std::string playerName;
    getline(std::cin, playerName);
    std::cout << "Welcome, " << playerName << "!" << std::endl << std::endl;

    std::cout << "Please give a brief (one sentence) description of your character's appearance: " << std::endl;
    std::string playerDescription;
    getline(std::cin, playerDescription);
    std::cout << "Lookin' good!" << std::endl << std::endl;

    // We tell them to start in the entrance room, and use the name and description they provide.
    Player myPlayer(playerName, playerDescription);
    myPlayer.SetCurrentArea(&entrance);

    bool exit = false;

    while (exit == false)
    {
        // Print out where the player currently is, and their current health.
        std::cout << "You are in the " << myPlayer.GetCurrentArea()->GetName() << std::endl;

        std::cout << "What do you want to do?" << std::endl << std::endl;

        std::string choice;
        std::cin >> choice;

        if (choice == "look")
        {
            std::cout << "What do you want to look at? (Hint: type \"area\" to look around you)" << std::endl << std::endl;

            std::cin >> choice;

            // Check player and the area for the target
            Thing* targetPlayerThing = myPlayer.GetFromContents(choice);
            Thing* targetAreaThing = myPlayer.GetCurrentArea()->GetFromContents(choice);
            if (targetPlayerThing != nullptr)
            {
                targetPlayerThing->Look();
            }
            else if (targetAreaThing != nullptr)
            {
                targetAreaThing->Look();
            }
            else
            {
                std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                std::cout << "Try looking at the area around you, yourself, or a specific item, feature, or monster!" << std::endl << std::endl;
            }
        }
        else if (choice == "go")
        {
            std::cout << "Where do you want to go? Hint: Look at the area you are in to see exits." << std::endl << std::endl;

            std::cin >> choice;

            // Try going from the current area to the target area
            myPlayer.GetCurrentArea()->Go(&myPlayer, choice);
        }
        else if (choice == "attack")
        {
            std::cout << "What do you want to attack?" << std::endl << std::endl;

            std::cin >> choice;

            Thing* targetThing = myPlayer.GetCurrentArea()->GetFromContents(choice);
            Monster* targetMonster = dynamic_cast<Monster*>(targetThing);
            if (targetThing != nullptr && targetMonster == nullptr)
            {
                std::cout << "You can't attack \"" << choice << "\" - " << std::endl;
                std::cout << "Heroes can only attack monsters!" << std::endl << std::endl;
            }
            else if (targetMonster != nullptr)
            {
                targetMonster->Attack(&myPlayer);
            }
            else
            {
                std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                std::cout << "Try looking at the area around you to see what targets you might find!" << std::endl << std::endl;
            }
        }
        else if (choice == "take")
        {
            std::cout << "What do you want to take?" << std::endl << std::endl;
            std::cin >> choice;

            Thing* targetThing = myPlayer.GetCurrentArea()->GetFromContents(choice);
            Item* targetItem = dynamic_cast<Item*>(targetThing);
            if (targetItem != nullptr)
            {
                myPlayer.AddItem(targetItem);
                myPlayer.GetCurrentArea()->RemoveItem(targetItem);
                std::cout << "You take the " << choice << "." << std::endl << std::endl;
            }
            else
            {
                std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                std::cout << "Try looking at the area around you to see what items you might find!" << std::endl << std::endl;
            }
        }
        else if (choice == "use")
        {
            std::cout << "What do you want to use?" << std::endl << std::endl;

            std::cin >> choice;
            myPlayer.UseItemFromInventory(choice);
        }
        else if (choice == "equip")
        {
            std::cout << "What do you want to equip?" << std::endl << std::endl;

            std::cin >> choice;
            myPlayer.Equip(choice);
        }
        else if (choice == "exit")
        {
            std::cout << "Thank you for playing!" << std::endl << std::endl;
            exit = true;
        }
        else if (choice == "help")
        {
            std::cout << "You can use the following commands: " << std::endl;

            // Add to these as you add more commands!
            std::cout << "     look" << std::endl;
            std::cout << "     go" << std::endl;
            std::cout << "     attack" << std::endl;
            std::cout << "     take" << std::endl;
            std::cout << "     use" << std::endl;
            std::cout << "     equip" << std::endl;
            std::cout << "     exit" << std::endl;
            std::cout << "     help" << std::endl;

            std::cout << std::endl;
        }
        else
        {
            std::cout << "Sorry, I didn't understand the command \"" << choice << "\"" << std::endl;
            std::cout << "Try typing \"help\" for a list of commands." << std::endl << std::endl;
        }


        if (myPlayer.GetAlive() == false)
        {
            std::cout << "You have died. Game over." << std::endl << std::endl;
            exit = true;
        }


        if (goblinKing.GetAlive() == false)
        {
            std::cout << "You have defeated the Goblin King - you win! Congratulations!" << std::endl << std::endl;
            exit = true;
        }
    }

}
