//
// Created by Bartek on 10.03.2021.
//
#include <iostream>
#include <random>
#include "Naglowki/Knight.h"

void Board::InitialiseBoard() {
    do {
      std::cout << "Prosze okreslic rozmiar planszy wpierw x pozniej y (wieksze od 0) \n";
      std::cin >> sy_board >> sx_board;
    } while (sy_board < 1 || sx_board < 1);

    pBoard = new char *[sx_board];
    for (int i = 0; i < sx_board; i++) {
        pBoard[i] = new char[sy_board];
        for (int j = 0; j < sy_board; j++) {
            pBoard[i][j] = 'O';
        }
    }
}

void Knight::InitialiseKnight() {
    std::cout << "Prosze okerslic pozycje skoczka \n(wpierw wymiar 0 < x < " << sy_board << " pozniej 0 < y < " << sx_board << ") \n";

    /*
    std::random_device rd;
    std::default_random_engine el(rd());
    std::uniform_int_distribution<int> unfiorm_dist(0, sy_board - 1);
    knights_y = unfiorm_dist(el);
    std::uniform_int_distribution<int> unfiorm_dis(0, sx_board - 1);
    knights_x = unfiorm_dis(el);
     */
    do {
        std::cout << "tak zeby znajdowala sie na planszy \n";
        std::cin >> knights_y >> knights_x;
    } while (knights_x < 1 || knights_x >= sx_board || knights_y < 1 || knights_y >= sy_board);
    pBoard[knights_x][knights_y] = 'K';
    pHowKnightMoves = new mMovesStruct[8]{{-2, -1},
                                          {-2, 1},
                                          {-1, -2},
                                          {-1, 2},
                                          {1,  2},
                                          {1,  -2},
                                          {2,  -1},
                                          {2,  1}};

    pHead = new MovesList();
    pTail = nullptr;
    pHead->pBefore = nullptr;
    pHead->position_x = knights_x;
    pHead->position_y = knights_y;
    pTail = pHead;
}
