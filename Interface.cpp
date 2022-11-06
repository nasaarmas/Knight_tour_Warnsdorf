//
// Created by Bartek on 19.03.2021.
//
#include "Naglowki/Interface.h"
#include <iostream>

void Interface::ShowInterface() {
    char option_button = '1';
    do {
        std::cout
                << "\nProsze zdecydowac jak chcesz grac\nalbo czy zakonczyc program \n"
                   "MoveKnightAutomatically czy sterowac\n(1 - PlayAutomaticGame, 2 - sterowanie, 0 - koniec):  \n";
        std::cin >> option_button;
        switch (option_button) {
            case '1':
                PlayAutomaticGame();
                break;
            case '2':
                PlayControllableGame();
                break;
            case '0':
                std::cout << "koniec programu\n";
                break;
            default:
                std::cout << "Zla cyfra \n";
        }
    } while (option_button != '0');
}

