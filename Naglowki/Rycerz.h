//
// Created by Bartek on 10.03.2021.
//

#ifndef PROJEKT_RYCERZ_H
#define PROJEKT_RYCERZ_H

class Plansza {
protected:
    int ry_planszy, rx_planszy;
    char **plansza;

    void inicjalizacja_planszy();
};

class Rycerz : public Plansza {

private:
    struct ruch {
        int x, y;
    };

protected:
    ruch *jak_skacze_kon;
    int px_skoczka, py_skoczka;

    void inicjalizacja_rycerza();

    struct lewo_prawo {
        struct lewo_prawo *next;
        struct lewo_prawo *before;
        int pozycja_x, pozycja_y;
    };
    lewo_prawo *glowa;
    lewo_prawo *ogon;
};


#endif //PROJEKT_RYCERZ_H
