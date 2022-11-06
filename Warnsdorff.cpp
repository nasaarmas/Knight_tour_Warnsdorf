#include "Naglowki/Warnsdorff.h"
#include <iostream>

void Warnsdorff::PlayAutomaticGame() {
    InitialiseBoard();
    InitialiseKnight();
    PrintTable();
    MoveKnightAutomatically();
    FreeMemory();
}

void Warnsdorff::MoveKnightAutomatically() {
    for (int i = 1; i < sy_board * sx_board; i++) {
        std::cout << "\n";
        if (setWhereToMove()) {
            break;
        }
        PrintTable();
    }
}

void Warnsdorff::PlayControllableGame() {
    InitialiseBoard();
    InitialiseKnight();
    char playing_button = '0';
    for (int i = 1; i < sy_board * sx_board; i++) {
        if (setWhereToMove()) {
            break;
        }
        CreateMovesList();
    }

    for (int i = 0; i < sx_board; i++) {
        for (int j = 0; j < sy_board; j++) {
            pBoard[i][j] = 'O';
        }
    }
    pBoard[pHead->position_x][pHead->position_y] = 'K';
    auto *pKnights_current_place = pHead;
    std::cout << "Controls: a - one step backward, d - one step forward, s - finish game automatically \n";
    PrintTable();
    do {
        std::cout << "\n";
        std::cin >> playing_button;
        if (playing_button == 'a') {
            if (pKnights_current_place->pBefore == nullptr) {
                std::cout << "can't move more backward\n";
            } else {
                pBoard[pKnights_current_place->position_x][pKnights_current_place->position_y] = '0';
                pKnights_current_place = pKnights_current_place->pBefore;
                pBoard[pKnights_current_place->position_x][pKnights_current_place->position_y] = 'K';
                knights_x = pKnights_current_place->position_x;
                knights_y = pKnights_current_place->position_y;
            }
        } else if (playing_button == 'd') {
            if (pKnights_current_place->pNext == nullptr) {
                std::cout << "No more moves\n";
                break;
            } else {
                pBoard[pKnights_current_place->position_x][pKnights_current_place->position_y] = char(131);
                pKnights_current_place = pKnights_current_place->pNext;
                pBoard[pKnights_current_place->position_x][pKnights_current_place->position_y] = 'K';
                knights_x = pKnights_current_place->position_x;
                knights_y = pKnights_current_place->position_y;
            }
        } else if (playing_button == 's') {
            MoveKnightAutomatically();
            break;
        }
        PrintTable();
    } while (playing_button != '0');
    FreeMemory();
    while (pHead->pNext != nullptr) {
        pKnights_current_place = pHead;
        pHead = pHead->pNext;
        delete pKnights_current_place;
    }
    delete pHead;
}

bool Warnsdorff::setWhereToMove() {
    int pomoc = 9;
    for (int i = 0; i < 8; i++) {
        if (CheckFieldAccessibility(knights_x + pHowKnightMoves[i].x, knights_y + pHowKnightMoves[i].y)) {
            if (getPossibleMoves(knights_x + pHowKnightMoves[i].x, knights_y + pHowKnightMoves[i].y) < pomoc) {
                knights_next_x = knights_x + pHowKnightMoves[i].x;
                knights_next_y = knights_y + pHowKnightMoves[i].y;
                pomoc = getPossibleMoves(knights_next_x, knights_next_y);
            }
        }
    }
    if (pomoc == 9) {
        std::cout << "Nie ma dalszych ruchow \n";
        return true;
    }
    pBoard[knights_x][knights_y] = char(131);
    pBoard[knights_next_x][knights_next_y] = 'K';
    knights_x = knights_next_x;
    knights_y = knights_next_y;
    return false;
}

int Warnsdorff::getPossibleMoves(int positionKnightX, int positionKnightY) {
    int p = 0;
    for (int i = 0; i < 8; i++) {
        if (CheckFieldAccessibility(positionKnightX + pHowKnightMoves[i].x, positionKnightY + pHowKnightMoves[i].y)) {
            p++;
        }
    }
    return p;
}

bool Warnsdorff::CheckFieldAccessibility(int fieldsX, int fieldsY) {
    if (fieldsX >= sx_board || fieldsX < 0 || fieldsY >= sy_board || fieldsY < 0 || pBoard[fieldsX][fieldsY] != 'O') {
        return false;
    }
    return true;
}

void Warnsdorff::CreateMovesList() {
    auto *pNew_node = new MovesList();
    pTail->pNext = pNew_node;
    pNew_node->pBefore = pTail;
    pTail = pTail->pNext;
    pTail->pNext = nullptr;
    pTail->position_y = knights_next_y;
    pTail->position_x = knights_next_x;
}

void Warnsdorff::PrintTable() {
    for (int i = 0; i < sx_board; i++) {

        for (int j = 0; j < sy_board; j++) {
            std::cout << pBoard[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Warnsdorff::FreeMemory() {
    for (int i = 0; i < sx_board; i++) {
        delete[] pBoard[i];
    }
    delete[] pBoard;
    delete[] pHowKnightMoves;
}
