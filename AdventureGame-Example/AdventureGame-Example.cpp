// AdventureGame-Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Area.h"

int main()
{
    // Create the player
    Player myPlayer("Mario", "Mario is an Italian plumber.");

    // Set up the current area the player is in
    myPlayer.currentArea = "Entrance";

    // Test the player Look functionality
    myPlayer.Look();

    // Manually print out the current area
    std::cout << "Current area: " << myPlayer.currentArea << std::endl << std::endl;



    // Create some areas
    Area entrance("Entrance", "A grand entryway with soaring columns. You see a Hallway ahead.");
    Area hallway("Hallway", "A long, featureless hallway leading into darkness. The Throneroom is ahead.");
    Area throneroom("Throneroom", "A huge throneroom shrouded in darkness. A grim purple crystal throne lies empty at the center on an obsidian dais. Tattered red curtains hang on the walls. Behind you is the Hallway.");

    // Set up exits connecting these rooms
    // NOTE: We'll learn a better way to do this!
    entrance.exit = hallway.name;
    hallway.exit = throneroom.name;
    throneroom.exit = hallway.name;

    // Test the area Look functionality
    entrance.Look();
    hallway.Look();
    throneroom.Look();

}
