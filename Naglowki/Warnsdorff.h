//
// Created by Bartek on 10.03.2021.
//

#ifndef PROJECT_WARNSDORFF_H
#define PROJECT_WARNSDORFF_H

#include "Knight.h"

class Warnsdorff : public Knight {
protected:
    int knights_next_x, knights_next_y;
    void PlayAutomaticGame();
    void MoveKnightAutomatically();
    void PlayControllableGame();

private:
    bool setWhereToMove();
    void PrintTable();
    int getPossibleMoves(int positionKnightX, int positionKnightY);
    bool CheckFieldAccessibility(int fieldsX, int fieldsY);
    void FreeMemory();
    void CreateMovesList();
};

#endif //PROJECT_WARNSDORFF_H
