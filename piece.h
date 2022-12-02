#ifndef PIECE_H
#define PIECE_H

#define BLANK   0b00000
#define PAWN    0b00001
#define KNIGHT  0b00010
#define BISHOP  0b00011
#define ROOK    0b00100
#define QUEEN   0b00101
#define KING    0b00110
#define BLACK   0b01000
#define WHITE   0b10000

typedef struct
{
    char type;
    char sprite;
    int state;
    void* board;
} Piece;

char getPiece(Piece p);
char getColour(Piece p);
int getIndex(Piece p);
char findSprite(char type);
Piece makePiece(char type, void* board);
char fromChar(char fen);

#endif
