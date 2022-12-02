#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

typedef struct
{
    int ranks;
    int files;
    Piece* pieces;
} Board;

Board makeBoard(char* fen);
void displayBoard(Board* brd);

#endif
