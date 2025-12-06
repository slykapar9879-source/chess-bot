#include "assets.h"
#include "../core/board.h"

#include <stdio.h>

SDL_Texture* textures[12];

void assets_init_textures(SDL_Renderer* r)
{
  textures[PAWN] = IMG_LoadTexture(r, "assets/white-pawn.png");
}


void assets_render_board(Board* b, SDL_Renderer* r)
{
  SDL_RenderCopy(r, textures[PAWN], NULL, &(SDL_Rect){ 0, 0, 80, 80 });
}

void assets_render_piece(Piece* p, int x, int y)
{

}
