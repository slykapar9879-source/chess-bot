#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "render/render.h"
#include "core/board.h"

int main(int argc, char *argv[])
{
  SDL_Event event;
  bool running = true;
  Board board;

  if(render_init() != 0)
  {
    return -1;
  }

  board_init(&board);

  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
        running = false;
    }

    render_clear();

    render_background_color((rgb_t){ 255, 255, 255 });


    for(int x = 0; x < 8; x++)
    {
      for(int y = 0; y < 8; y++)
      {
        if(x % 2 + y % 2 != 1)
          render_fill_rect((rect_t){ x * 80, y * 80, 80, 80 }, (rgb_t){ 238, 237, 210 });
        else
          render_fill_rect((rect_t){ x * 80, y * 80, 80, 80 }, (rgb_t){ 224, 216, 196 });
      }
    }

    render_render_board(&board);

    render_execute();

    SDL_Delay(1000 / 60);
  }

  SDL_Quit();
  return 0;
}
