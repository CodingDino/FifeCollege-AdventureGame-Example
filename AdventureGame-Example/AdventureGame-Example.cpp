// AdventureGame-Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Area.h"
#include "Monster.h"
#include "Item.h"
#include "Potion.h"

int main()
{

    std::cout << "Welcome to Adventure Game!" << std::endl;

    // NOTE: I create the areas first since the player can then access them for the name.


    // Create some areas
    std::cout << "Generating the word..." << std::endl;
    
    // Setup each area
    Area entrance("Entrance", "A grand entryway with soaring columns. You see a Hallway ahead.");
    Area hallway("Hallway", "A long, featureless hallway leading into darkness. The Throneroom is ahead.");
    Area throneroom("Throneroom", "A huge throneroom shrouded in darkness. A grim purple crystal throne lies empty at the center on an obsidian dais. Tattered red curtains hang on the walls, covering a strange Crack in the wall. Behind you is the Hallway. Above you is the Belfry");
    Area crack("Crack", "A small crack that you can barely squeeze through. It travels between the Throneroom and the Chamber.");
    Area chamber("Chamber", "This room is covered in strange, soft eggs. They are sticky as if covered in web. A Crack leads out.");
    Area belfry("Belfry", "This Belfry is full of bats. Lots and lots of bats. Bats in the Belfry. Below you is the Throneroom.");

    // Setup exits for each area
    entrance.AddExit(&hallway);
    hallway.AddExit(&entrance);
    hallway.AddExit(&throneroom);
    throneroom.AddExit(&hallway);
    throneroom.AddExit(&crack);
    throneroom.AddExit(&belfry);
    crack.AddExit(&throneroom);
    crack.AddExit(&chamber);
    chamber.AddExit(&crack);
    belfry.AddExit(&throneroom);

    // Create Monsters
    Monster goblin("Goblin", "A smelly green goblin.", 50, 5);
    Monster goblinKing("GoblinKing", "Some kind of rock star with very tight pants.", 200, 50);
    Monster spider("Spider", "A giant spider. Just wants to catch and eat giant flies - your friend, really.", 100, 10);

    hallway.AddMonster(&goblin);
    throneroom.AddMonster(&goblinKing);

    // Create items
    Item pebble("Pebble", "A useless pebble");
    Potion smallPotion("Potion", "A bubbling red potion. It smells delicious.", 50);
    Potion healingCrystal("Crystal", "A shining crystal the size of your fist that gives off a warm healing feeling.", 100);

    entrance.AddItem(&pebble);
    hallway.AddItem(&smallPotion);
    chamber.AddItem(&healingCrystal);

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
            exit = false;
        }
    }

}
