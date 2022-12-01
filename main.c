#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

int main()
{
    Piece p = makePiece(WHITE | KING, NULL);
    printf("%c\n", p.sprite);
    return 0;  
}
