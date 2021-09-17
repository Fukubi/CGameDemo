#include "grass_tile.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

void grass_tile_initializeTexture(grass_tile *tile, SDL_Renderer *renderer) {
  tile->texture =
      IMG_LoadTexture(renderer, "../resources/Tiles/generic-rpg-Slice.png");

  if (!tile->texture)
    fprintf(stderr, "Error loading grass texture: %s\n", SDL_GetError());
}

void grass_tile_renderTile(grass_tile *tile, SDL_Renderer *renderer, int posX,
                           int posY) {
  SDL_QueryTexture(tile->texture, NULL, NULL, &tile->sprite.w, &tile->sprite.h);

  tile->sprite.w *= 2;
  tile->sprite.h *= 2;

  tile->sprite.x = posX;
  tile->sprite.y = posY;

  SDL_RenderCopy(renderer, tile->texture, NULL, &tile->sprite);
}

void grass_tile_destroyTexture(grass_tile *tile) {
  SDL_DestroyTexture(tile->texture);
}
