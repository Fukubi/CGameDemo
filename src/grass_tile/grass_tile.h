#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct grass_tile {
  SDL_Rect sprite;
  SDL_Texture *texture;
} grass_tile;

void grass_tile_initializeTexture(grass_tile *tile, SDL_Renderer *renderer);
void grass_tile_destroyTexture(grass_tile *tile);

void grass_tile_renderTile(grass_tile *tile, SDL_Renderer *renderer, int posX,
                           int posY);

#endif
