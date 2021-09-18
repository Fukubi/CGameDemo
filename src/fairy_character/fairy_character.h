#ifndef FAIRY_CHARACTER_H
#define FAIRY_CHARACTER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#define FAIRY_CHARACTER_NUMBER_OF_IDLE_TEXTURES 4

typedef struct fairy_character {
  SDL_Rect sprite;
  SDL_Texture *idleTextures[FAIRY_CHARACTER_NUMBER_OF_IDLE_TEXTURES];
} fairy_character;

void fairy_character_initializeCharacterTextures(fairy_character *fairy,
                                                  SDL_Renderer *renderer);
void fairy_character_destroyTexture(fairy_character *fairy);

void fairy_character_renderIdle(fairy_character *fairy,
                                 SDL_Renderer *renderer, int *animationTime);

void fairy_character_moveLeft(fairy_character *fairy, const float LIMITMOVE);
void fairy_character_moveRight(fairy_character *fairy,
                                const float LIMITMOVE);
void fairy_character_moveUp(fairy_character *fairy, const float LIMITMOVE);
void fairy_character_moveDown(fairy_character *fairy, const float LIMITMOVE);

#endif