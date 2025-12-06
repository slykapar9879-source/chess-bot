#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY } PieceType;
typedef enum { WHITE, BLACK, NONE } Color;

typedef struct
{
  PieceType type;
  Color color;
} Piece;

typedef struct
{
  Piece squares[8][8];
} Board;

typedef struct 
{
  Board board;
  Color side_to_move;
  bool white_castled;
  bool black_castled
} GameState;

void board_init(Board *b);
Piece board_get(Board *b, int file, int rank);
void board_set(Board *b, int file, int rank, Piece p);

#endif
