#ifndef RENDER_H
#define RENDER_H

#define WINDOW_WIDTH 940
#define WINDOW_HEIGHT 640

#include <stdint.h>

typedef struct
{
  int x, y, h, w;
} rect_t;

typedef struct
{
  uint8_t r, g, b;
} rgb_t;

int render_init();
void render_fill_rect(rect_t rect, rgb_t rgb);
void render_draw_rect(rect_t rect, rgb_t rgb);

void render_clear();
void render_execute();
void render_background_color(rgb_t rgb);

#endif
