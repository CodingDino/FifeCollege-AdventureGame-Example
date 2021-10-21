// AdventureGame-Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Area.h"

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
    entrance.exits.push_back(&hallway);
    hallway.exits.push_back(&entrance);
    hallway.exits.push_back(&throneroom);
    throneroom.exits.push_back(&hallway);
    throneroom.exits.push_back(&crack);
    throneroom.exits.push_back(&belfry);
    crack.exits.push_back(&throneroom);
    crack.exits.push_back(&chamber);
    chamber.exits.push_back(&crack);
    belfry.exits.push_back(&throneroom);

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
    myPlayer.currentArea = &entrance;

    bool exit = false;

    while (exit == false)
    {
        // Print out where the player currently is, and their current health.
        std::cout << "You are in the " << myPlayer.currentArea->name << std::endl;

        std::cout << "What do you want to do?" << std::endl << std::endl;

        std::string choice;
        std::cin >> choice;

        if (choice == "look")
        {
            std::cout << "What do you want to look at? (Hint: type \"area\" to look around you)" << std::endl << std::endl;

            std::cin >> choice;

            if (choice == "area")
            {
                // Go to our current area and Look at it!
                myPlayer.currentArea->Look();
            }
            else if (choice == "self")
            {
                myPlayer.Look();
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
            myPlayer.currentArea->Go(&myPlayer, choice);
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
            std::cout << "     exit" << std::endl;
            std::cout << "     help" << std::endl;

            std::cout << std::endl;
        }
        else
        {
            std::cout << "Sorry, I didn't understand the command \"" << choice << "\"" << std::endl;
            std::cout << "Try typing \"help\" for a list of commands." << std::endl << std::endl;
        }
    }

}
