//
// Created by Bartek on 10.03.2021.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

class Board {
protected:
    int sy_board, sx_board;
    char **pBoard;

    void InitialiseBoard();
};

class Knight : public Board {

private:
    struct mMovesStruct {
        int x, y;
    };

protected:
    mMovesStruct *pHowKnightMoves;
    int knights_x, knights_y;
    void InitialiseKnight();
    struct MovesList {
        struct MovesList *pNext;
        struct MovesList *pBefore;
        int position_x, position_y;
    };
    MovesList *pHead;
    MovesList *pTail;
};

#endif //PROJECT_KNIGHT_H
