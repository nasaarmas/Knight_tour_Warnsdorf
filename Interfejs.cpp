//
// Created by Bartek on 19.03.2021.
//
#include "Naglowki/Interfejs.h"
#include <iostream>

Interfejs::Interfejs() {
    char a = '1';
    do {
        std::cout
                << "\nProsze zdecydowac jak chcesz grac\nalbo czy zakonczyc program \n"
                   "automatycznie czy sterowac\n(1 - automat, 2 - sterowanie, 0 - koniec):  \n";
        std::cin >> a;
        switch (a) {
            case '1':
                automat();
                break;
            case '2':
                sterowane();
                break;
            case '0':
                std::cout << "koniec programu\n";
                break;
            default:
                std::cout << "Zla cyfra \n";
        }
    } while (a != '0');
}

