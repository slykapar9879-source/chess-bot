#include "../core/board.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void assets_init_textures(SDL_Renderer* r);
void assets_render_board(Board* b, SDL_Renderer* r);
void assets_render_piece(Piece* p, int x, int y);
