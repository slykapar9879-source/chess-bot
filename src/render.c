#include <stdio.h>
#include <SDL2/SDL.h>

#include "render.h"

typedef struct
{
  SDL_Window* window_obj;
  SDL_Renderer* render_obj;
  rgb_t background_color;
} render_t;

render_t render;

int render_init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return -1;
  }

  SDL_Window* window = SDL_CreateWindow("Chess Bot",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH,
                                        WINDOW_HEIGHT,
                                        SDL_WINDOW_ALLOW_HIGHDPI);
  if(!window)
  {
    printf("Error while creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return -1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window,
                                              -1,
                                              SDL_RENDERER_ACCELERATED);

  if(!renderer)
  {
    printf("Error while creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }

  render.window_obj = window;
  render.render_obj = renderer;
  render.background_color = (rgb_t){ 0, 0, 0 };

  return 0;
}

void render_fill_rect(rect_t rect, rgb_t rgb)
{
  rgb_t prev;
  uint8_t prev_alpha;

  SDL_GetRenderDrawColor(render.render_obj, &prev.r, &prev.g, &prev.b, &prev_alpha);

  SDL_SetRenderDrawColor(render.render_obj, rgb.r, rgb.g, rgb.b, 255);
  SDL_RenderFillRect(render.render_obj, &(SDL_Rect){ rect.x, rect.y, rect.w, rect.h });

  SDL_SetRenderDrawColor(render.render_obj, prev.r, prev.g, prev.b, prev_alpha);
}

void render_draw_rect(rect_t rect, rgb_t rgb)
{
  rgb_t prev;
  uint8_t prev_alpha;

  SDL_GetRenderDrawColor(render.render_obj, &prev.r, &prev.g, &prev.b, &prev_alpha);

  SDL_SetRenderDrawColor(render.render_obj, rgb.r, rgb.g, rgb.b, 255);
  SDL_RenderDrawRect(render.render_obj, &(SDL_Rect){ rect.x, rect.y, rect.w, rect.h });

  SDL_SetRenderDrawColor(render.render_obj, prev.r, prev.g, prev.b, prev_alpha);
}

void render_clear()
{
  SDL_RenderClear(render.render_obj);
}

void render_execute()
{
  SDL_SetRenderDrawColor(render.render_obj, render.background_color.r,
                         render.background_color.g,
                         render.background_color.b,
                         255);

  SDL_RenderPresent(render.render_obj);
}

void render_background_color(rgb_t rgb)
{
  render.background_color = rgb;
}
