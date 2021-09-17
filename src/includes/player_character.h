#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct player_character {
  SDL_Rect sprite;
  SDL_Texture *texture;
} player_character;

void player_character_renderIdle(player_character *player,
                                 SDL_Renderer *renderer, int *animationTime);
void player_character_DestroyPlayer(player_character *player);

#endif
