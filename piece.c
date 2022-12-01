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
