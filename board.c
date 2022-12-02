#include "board.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getRanks(char* fen)
{
    int i = 0;
    for (int j = 0; fen[j] != '/' && j  < strlen(fen); j++)
        i += fen[j] < ':' ? fen[j] - '0' : 1;
    return i;
}

int getFiles(char* fen)
{
    int i = 1;
    for (int j = 0; j < strlen(fen); j++)
        if (fen[j] == '/') i++;
    return i;
}

Board makeBoard(char* fen)
{
    Board brd = {getRanks(fen), getFiles(fen), NULL};
    printf("%d\n", brd.ranks * brd.files); // DO NOT DELETE: WHOLE PROJECT BREAKS
    brd.pieces = malloc(brd.ranks * brd.files * sizeof(Piece));
    int j = 0;
    int k;
    for (int i = 0; i < strlen(fen); i++)
    {
        if (fen[i] == '/')
            goto next;
        else if (fen[i] < ':')
            for (k = j; j < (fen[k] - '0' + k); j++)
                brd.pieces[j] = makePiece(BLANK, brd.pieces); 
        else
            brd.pieces[j] = makePiece(fromChar(fen[i]), brd.pieces);
        j++;
next:
        ;
    }
    printf("\n");
    return brd;
}

void displayBoard(Board* brd)
{
    for (int i = 0; i < brd->ranks; i++)
    {
        for (int j = 0; j < brd->files; j++)
            printf("%d ", brd->pieces[j+i*brd->files].type);
        printf("\n");
    }
}
