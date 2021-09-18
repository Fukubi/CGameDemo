#include "fairy_character.h"

#include <SDL2/SDL_image.h>

void fairy_character_initializeCharacterTextures(fairy_character *fairy,
                                                 SDL_Renderer *renderer) {
  fairy->idleTextures[0] =
      IMG_LoadTexture(renderer, "resources/Fairy/Fairy_Idle + Walk_1.png");

  fairy->idleTextures[1] =
      IMG_LoadTexture(renderer, "resources/Fairy/Fairy_Idle + Walk_2.png");

  fairy->idleTextures[2] =
      IMG_LoadTexture(renderer, "resources/Fairy/Fairy_Idle + Walk_3.png");

  fairy->idleTextures[3] =
      IMG_LoadTexture(renderer, "resources/Fairy/Fairy_Idle + Walk_4.png");
}

void fairy_character_renderIdle(fairy_character *fairy, SDL_Renderer *renderer,
                                int *animationTime) {
  int idleTextureId = 0;

  if (*animationTime >= 1 && *animationTime < 5)
    idleTextureId = 0;
  else if (*animationTime >= 5 && *animationTime < 10)
    idleTextureId = 1;
  else if (*animationTime >= 10 && *animationTime < 15)
    idleTextureId = 2;
  else if (*animationTime >= 15 && *animationTime < 20)
    idleTextureId = 3;
  else
    *animationTime = 0;

  SDL_QueryTexture(fairy->idleTextures[idleTextureId], NULL, NULL,
                   &fairy->sprite.w, &fairy->sprite.h);

  fairy->sprite.w *= 2;
  fairy->sprite.h *= 2;

  SDL_RenderCopy(renderer, fairy->idleTextures[idleTextureId], NULL,
                 &fairy->sprite);
}

void fairy_character_moveLeft(fairy_character *fairy,
                               const float LIMITMOVE) {
  fairy->sprite.x -= 20;

  if (fairy->sprite.x <= LIMITMOVE)
    fairy->sprite.x = LIMITMOVE;
}

void fairy_character_moveRight(fairy_character *fairy,
                                const float LIMITMOVE) {
  fairy->sprite.x += 20;

  if (fairy->sprite.x >= LIMITMOVE)
    fairy->sprite.x = LIMITMOVE;
}

void fairy_character_moveUp(fairy_character *fairy, const float LIMITMOVE) {
  fairy->sprite.y -= 20;

  if (fairy->sprite.y <= LIMITMOVE)
    fairy->sprite.y = LIMITMOVE;
}

void fairy_character_moveDown(fairy_character *fairy,
                               const float LIMITMOVE) {
  fairy->sprite.y += 20;

  if (fairy->sprite.y >= LIMITMOVE)
    fairy->sprite.y = LIMITMOVE;
}

void fairy_character_destroyTexture(fairy_character *fairy) {
  for (int i = 0; i < FAIRY_CHARACTER_NUMBER_OF_IDLE_TEXTURES; i++)
    SDL_DestroyTexture(fairy->idleTextures[i]);
}