//
// Created by Bartek on 10.03.2021.
//

#ifndef PROJEKT_WARNSDORFF_H
#define PROJEKT_WARNSDORFF_H

#include "Rycerz.h"

class Warnsdorff : public Rycerz {
protected:
    int px_next, py_next;

    void automat();

    void automatycznie();

    void sterowane();

private:
    bool gdzie_sie_ruszyc();

    void wypisz_tablice();

    int mozliwe_ruchy(int px_skocz, int py_skocz);

    bool czy_nie_poza_plansza(int px, int py);

    void usun_dane();

    void tworzenie_listy();
};

#endif //PROJEKT_WARNSDORFF_H
