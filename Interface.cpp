//
// Created by Bartek on 19.03.2021.
//
#include "Naglowki/Interface.h"
#include <iostream>

void Interface::ShowInterface() {
    char option_button = '1';
    do {
        std::cout
                << "\nPlease specify how you would like to play\nor if to end the game \n"
                   "Play the game automatically or with control\n(1 - Play Game Automatic, 2 - Controlling, 0 - End):  \n";
        std::cin >> option_button;
        switch (option_button) {
            case '1':
                PlayAutomaticGame();
                break;
            case '2':
                PlayControllableGame();
                break;
            case '0':
                std::cout << "End of Game\n";
                break;
            default:
                std::cout << "Bad Number \n";
        }
    } while (option_button != '0');
}

