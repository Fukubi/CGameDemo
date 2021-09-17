#ifndef DIRT_BORDER_DOWN_TILE_H
#define DIRT_BORDER_DOWN_TILE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct dirt_border_down_tile {
  SDL_Rect sprite;
  SDL_Texture *texture;
} dirt_border_down_tile;

void dirt_border_down_tile_initializeTexture(dirt_border_down_tile *tile, SDL_Renderer *renderer);
void dirt_border_down_tile_destroyTexture(dirt_border_down_tile *tile);

void dirt_border_down_tile_renderTile(dirt_border_down_tile *tile, SDL_Renderer *renderer, int posX,
                          int posY);
void dirt_border_down_tile_renderLineXAxis(dirt_border_down_tile *tile, SDL_Renderer *renderer,
                               int size, int startXAxis, int startYAxis);
void dirt_border_down_tile_renderLineYAxis(dirt_border_down_tile *tile, SDL_Renderer *renderer,
                               int size, int startXAxis, int startYAxis);

#endif