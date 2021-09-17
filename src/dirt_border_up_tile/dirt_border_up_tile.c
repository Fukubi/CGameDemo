#include "dirt_border_up_tile.h"

#include <SDL2/SDL_image.h>

void dirt_border_up_tile_initializeTexture(dirt_border_up_tile *tile,
                                           SDL_Renderer *renderer) {
  tile->texture =
      IMG_LoadTexture(renderer, "resources/Tiles/generic-rpg-tile25.png");

  if (!tile->texture)
    fprintf(stderr, "Error loading the border texture: %s\n", SDL_GetError());
}

void dirt_border_up_tile_destroyTexture(dirt_border_up_tile *tile) {
  SDL_DestroyTexture(tile->texture);
}

void dirt_border_up_tile_renderTile(dirt_border_up_tile *tile,
                                    SDL_Renderer *renderer, int posX,
                                    int posY) {
  SDL_QueryTexture(tile->texture, NULL, NULL, &tile->sprite.w, &tile->sprite.h);

  tile->sprite.w *= 2;
  tile->sprite.h *= 2;

  tile->sprite.x = posX;
  tile->sprite.y = posY;

  SDL_RenderCopy(renderer, tile->texture, NULL, &tile->sprite);
}

void dirt_border_up_tile_renderLineXAxis(dirt_border_up_tile *tile,
                                         SDL_Renderer *renderer, int size,
                                         int startXAxis, int startYAxis) {
  for (int i = 0; i < size + 1; i++)
    dirt_border_up_tile_renderTile(tile, renderer, (32 * i) + startXAxis,
                                   startYAxis);
}

void dirt_border_up_tile_renderLineYAxis(dirt_border_up_tile *tile,
                                         SDL_Renderer *renderer, int size,
                                         int startXAxis, int startYAxis) {
  for (int i = 0; i < size + 1; i++)
    dirt_border_up_tile_renderTile(tile, renderer, startXAxis, (32 * i) + startYAxis);
}