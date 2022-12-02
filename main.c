#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "board.h"

int main()
{
    Board brd = makeBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    displayBoard(&brd);
    return 0;  
}
