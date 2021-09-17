#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct player_character {
  SDL_Rect sprite;
} player_character;

void player_character_renderIdle(player_character *player,
                                 SDL_Renderer *renderer, int *animationTime);
void player_character_moveLeft(player_character *player, const float LIMITMOVE);
void player_character_moveRight(player_character *player,
                                const float LIMITMOVE);
void player_character_moveUp(player_character *player, const float LIMITMOVE);
void player_character_moveDown(player_character *player, const float LIMITMOVE);

#endif
