#include "Naglowki/Warnsdorff.h"
#include <iostream>


void Warnsdorff::automat() {
    inicjalizacja_planszy();
    inicjalizacja_rycerza();
    wypisz_tablice();
    automatycznie();
    usun_dane();
}

void Warnsdorff::automatycznie() {
    for (int i = 1; i < ry_planszy * rx_planszy; i++) {
        std::cout << "\n";
        if (gdzie_sie_ruszyc()) {
            break;
        }
        wypisz_tablice();
    }
}

void Warnsdorff::sterowane() {
    inicjalizacja_planszy();
    inicjalizacja_rycerza();
    char b = '0';
    for (int i = 1; i < ry_planszy * rx_planszy; i++) {

        if (gdzie_sie_ruszyc()) {
            break;
        }
        //zapelnienie planszy tworzac
        //liste dwukierunkowa zeby moc sie poruszac
        tworzenie_listy();
    }

    //ustawienie planszy jak w momencie poczatkowym
    //poniewaz zapelnilismy ja tworzac liste dwukierunkowa
    for (int i = 0; i < rx_planszy; i++) {

        for (int j = 0; j < ry_planszy; j++) {
            plansza[i][j] = 'O';
        }
    }
    //plansza jest cala w 0 teraz ustawiamy Konia jak na poczatku
    plansza[glowa->pozycja_x][glowa->pozycja_y] = 'K';
    auto *ruszajaca_sie = glowa;
    std::cout << "Sterowanie: a - ruch wstecz, d - ruch naprzod, s - dokonczenie gry automatycznie \n";
    wypisz_tablice();
    do {
        std::cout << "\n";
        std::cin >> b;
        if (b == 'a') {
            if (ruszajaca_sie->before == nullptr) {
                std::cout << "nie mozna wstecz\n";
            } else {
                plansza[ruszajaca_sie->pozycja_x][ruszajaca_sie->pozycja_y] = '0';
                ruszajaca_sie = ruszajaca_sie->before;
                plansza[ruszajaca_sie->pozycja_x][ruszajaca_sie->pozycja_y] = 'K';
                px_skoczka = ruszajaca_sie->pozycja_x;
                py_skoczka = ruszajaca_sie->pozycja_y;
            }
        } else if (b == 'd') {
            if (ruszajaca_sie->next == nullptr) {
                std::cout << "Brak dalszych ruchow\n";
                break;
            } else {
                plansza[ruszajaca_sie->pozycja_x][ruszajaca_sie->pozycja_y] = char(131);
                ruszajaca_sie = ruszajaca_sie->next;
                plansza[ruszajaca_sie->pozycja_x][ruszajaca_sie->pozycja_y] = 'K';
                px_skoczka = ruszajaca_sie->pozycja_x;
                py_skoczka = ruszajaca_sie->pozycja_y;
            }
        } else if (b == 's') {
            automatycznie();
            break;
        }
        wypisz_tablice();
    } while (b != '0');
    usun_dane();
    while (glowa->next != nullptr) {
        ruszajaca_sie = glowa;
        glowa = glowa->next;
        delete ruszajaca_sie;
    }
    delete glowa;
}

bool Warnsdorff::gdzie_sie_ruszyc() {
    int pomoc = 9;
    for (int i = 0; i < 8; i++) {
        if (czy_nie_poza_plansza(px_skoczka + jak_skacze_kon[i].x, py_skoczka + jak_skacze_kon[i].y)) {
            if (mozliwe_ruchy(px_skoczka + jak_skacze_kon[i].x, py_skoczka + jak_skacze_kon[i].y) < pomoc) {
                px_next = px_skoczka + jak_skacze_kon[i].x;
                py_next = py_skoczka + jak_skacze_kon[i].y;
                pomoc = mozliwe_ruchy(px_next, py_next);
            }
        }
    }
    if (pomoc == 9) {
        std::cout << "Nie ma dalszych ruchow \n";
        return true;
    }
    plansza[px_skoczka][py_skoczka] = char(131);
    plansza[px_next][py_next] = 'K';
    px_skoczka = px_next;
    py_skoczka = py_next;
    return false;
}

int Warnsdorff::mozliwe_ruchy(int px_skocz, int py_skocz) {
    int p = 0;
    for (int i = 0; i < 8; i++) {
        if (czy_nie_poza_plansza(px_skocz + jak_skacze_kon[i].x, py_skocz + jak_skacze_kon[i].y)) {
            p++;
        }
    }
    return p;
}

bool Warnsdorff::czy_nie_poza_plansza(int px, int py) {
    if (px >= rx_planszy || px < 0 || py >= ry_planszy || py < 0 || plansza[px][py] != 'O') {
        return false;
    }
    return true;
}

void Warnsdorff::tworzenie_listy() {
    auto *nowe_node = new lewo_prawo();
    ogon->next = nowe_node;
    nowe_node->before = ogon;
    ogon = ogon->next;
    ogon->next = nullptr;
    ogon->pozycja_y = py_next;
    ogon->pozycja_x = px_next;  
}

void Warnsdorff::wypisz_tablice() {
    for (int i = 0; i < rx_planszy; i++) {

        for (int j = 0; j < ry_planszy; j++) {
            std::cout << plansza[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Warnsdorff::usun_dane() {
    for (int i = 0; i < rx_planszy; i++) {
        delete[] plansza[i];
    }
    delete[] plansza;
    delete[] jak_skacze_kon;
}
