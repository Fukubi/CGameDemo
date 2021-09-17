#ifndef DIRT_TILE_H
#define DIRT_TILE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct dirt_tile {
  SDL_Rect sprite;
  SDL_Texture *texture;
} dirt_tile;

void dirt_tile_initializeTexture(dirt_tile *tile, SDL_Renderer *renderer);
void dirt_tile_destroyTexture(dirt_tile *tile);

void dirt_tile_renderTile(dirt_tile *tile, SDL_Renderer *renderer, int posX,
                          int posY);
void dirt_tile_renderLineXAxis(dirt_tile *tile, SDL_Renderer *renderer,
                               int size, int startXAxis, int startYAxis);
void dirt_tile_renderLineYAxis(dirt_tile *tile, SDL_Renderer *renderer,
                               int size, int startXAxis, int startYAxis);

#endif