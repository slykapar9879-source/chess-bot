#include "board.h"

void board_init(Board* b)
{
  for(int y = 0; y < 8; y++)
  {
    for(int x = 0; x < 8; x++)
    {
      if(y == 1)
        b->squares[x][y] = (Piece){ PAWN, BLACK };
      else if(y == 6)
        b->squares[x][y] = (Piece){ PAWN, WHITE };

      else
        b->squares[x][y] = (Piece){ EMPTY, NONE };
    }
  }


}

Piece board_get(Board* b, int file, int rank)
{

}

void board_set(Board* b, int file, int rank, Piece p)
{

}
