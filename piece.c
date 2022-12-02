#include "piece.h"

char getPiece(Piece p)
{
    return p.type & 0x7;
}
char getColour(Piece p)
{
    return p.type & 0x18;
}
int getIndex(Piece p)
{
    return ((void*)&p - p.board) / sizeof(p);
}
char findSprite(char type)
{
    char sprites[KING+1] = {' ', 'p', 'n', 'b', 'r', 'q', 'k'};
    char sprite = sprites[type & 0x7];
    sprite += (type & 0x18) == WHITE ? 'A' - 'a' : 0;
    return sprite;
}
Piece makePiece(char type, void* board)
{
    return (Piece){type, findSprite(type), 0, board};
}

char fromChar(char fen)
{
    char colour = fen > '[' ? WHITE : BLACK;
    char types[6] = "rnbqkp";
    if (colour == WHITE)
        fen += 'A' - 'a';

    int i = 0;
    for (; types[i] != fen && i < 6; i++);
    if (i == 6)
        return BLANK;
    char typeActuals[6] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN};
    return typeActuals[i] | colour;
}
