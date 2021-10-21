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
    Area entrance("Entrance", "A grand entryway with soaring columns. You see a Hallway ahead.");
    Area hallway("Hallway", "A long, featureless hallway leading into darkness. The Throneroom is ahead.");
    Area throneroom("Throneroom", "A huge throneroom shrouded in darkness. A grim purple crystal throne lies empty at the center on an obsidian dais. Tattered red curtains hang on the walls. Behind you is the Hallway.");

    // Set up exits connecting these rooms
    // NOTE: We'll learn a better way to do this!
    entrance.exit = hallway.name;
    hallway.exit = throneroom.name;
    throneroom.exit = hallway.name;

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
    myPlayer.currentArea = entrance.name;

    bool exit = false;

    while (exit == false)
    {
        // Print out where the player currently is, and their current health.
        std::cout << "You are in the " << myPlayer.currentArea << std::endl;

        std::cout << "What do you want to do?" << std::endl << std::endl;

        std::string choice;
        std::cin >> choice;

        if (choice == "look")
        {
            std::cout << "What do you want to look at? (Hint: type \"area\" to look around you)" << std::endl << std::endl;

            std::cin >> choice;

            if (choice == "area")
            {
                // Choose the correct area to print
                // We will learn a better way to do this!
                if (myPlayer.currentArea == entrance.name)
                {
                    entrance.Look();
                }
                else if (myPlayer.currentArea == hallway.name)
                {
                    hallway.Look();
                }
                else if (myPlayer.currentArea == throneroom.name)
                {
                    throneroom.Look();
                }
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

            // Choose the correct area to check exits
            // We will learn a better way to do this!
            if (myPlayer.currentArea == entrance.name)
            {
                if (choice == entrance.exit)
                {
                    std::cout << "You go to " << choice << std::endl << std::endl;
                    myPlayer.currentArea = choice;
                }
                else
                {
                    std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                    std::cout << "Try looking at the area around you and going to one of the connected areas." << std::endl << std::endl;
                }
            }
            else if (myPlayer.currentArea == hallway.name)
            {
                if (choice == hallway.exit)
                {
                    std::cout << "You go to " << choice << std::endl << std::endl;
                    myPlayer.currentArea = choice;
                }
                else
                {
                    std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                    std::cout << "Try looking at the area around you and going to one of the connected areas." << std::endl << std::endl;
                }
            }
            else if (myPlayer.currentArea == throneroom.name)
            {
                if (choice == throneroom.exit)
                {
                    std::cout << "You go to " << choice << std::endl << std::endl;
                    myPlayer.currentArea = choice;
                }
                else
                {
                    std::cout << "Sorry, I didn't understand the target \"" << choice << "\"" << std::endl;
                    std::cout << "Try looking at the area around you and going to one of the connected areas." << std::endl << std::endl;
                }
            }

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
