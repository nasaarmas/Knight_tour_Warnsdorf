//
// Created by Bartek on 10.03.2021.
//
#include <iostream>
#include <random>
#include "Naglowki/Rycerz.h"

void Plansza::inicjalizacja_planszy() {
    do {
      std::cout << "Prosze okreslic rozmiar planszy wpierw x pozniej y (wieksze od 0) \n";
      std::cin >> ry_planszy >> rx_planszy;
    } while (ry_planszy < 1 || rx_planszy < 1);

    plansza = new char *[rx_planszy];
    for (int i = 0; i < rx_planszy; i++) {
        plansza[i] = new char[ry_planszy];
        for (int j = 0; j < ry_planszy; j++) {
            plansza[i][j] = 'O';
        }
    }
}

void Rycerz::inicjalizacja_rycerza() {
    std::cout << "Prosze okerslic pozycje skoczka \n(wpierw wymiar 0 < x < " << ry_planszy << " pozniej 0 < y < " << rx_planszy <<") \n";

    /*
    std::random_device rd;
    std::default_random_engine el(rd());
    std::uniform_int_distribution<int> unfiorm_dist(0, ry_planszy - 1);
    py_skoczka = unfiorm_dist(el);
    std::uniform_int_distribution<int> unfiorm_dis(0, rx_planszy - 1);
    px_skoczka = unfiorm_dis(el);
     */
    do {
        std::cout << "tak zeby znajdowala sie na planszy \n";
        std::cin >> py_skoczka >> px_skoczka;
    } while (px_skoczka < 1 || px_skoczka >= rx_planszy || py_skoczka < 1 || py_skoczka >= ry_planszy);
    plansza[px_skoczka][py_skoczka] = 'K';
    jak_skacze_kon = new ruch[8]{{-2, -1},
                                 {-2, 1},
                                 {-1, -2},
                                 {-1, 2},
                                 {1,  2},
                                 {1,  -2},
                                 {2,  -1},
                                 {2,  1}};

    glowa = new lewo_prawo();
    ogon = nullptr;
    glowa->before = nullptr;
    glowa->pozycja_x = px_skoczka;
    glowa->pozycja_y = py_skoczka;
    ogon = glowa;

}
