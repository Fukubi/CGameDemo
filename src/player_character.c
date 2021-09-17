#include "player_character.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

void player_character_initializeCharacterTextures(player_character *player,
                                          SDL_Renderer *renderer) {
  player->idleTextures[0] =
      IMG_LoadTexture(renderer, "resources/Bandit/Bandit_Idle_1.png");
  player->idleTextures[1] =
      IMG_LoadTexture(renderer, "resources/Bandit/Bandit_Idle_2.png");
  player->idleTextures[2] =
      IMG_LoadTexture(renderer, "resources/Bandit/Bandit_Idle_3.png");
  player->idleTextures[3] =
      IMG_LoadTexture(renderer, "resources/Bandit/Bandit_Idle_4.png");

  for (int i = 0; i < PLAYER_CHARACTER_NUMBER_OF_IDLE_TEXTURES; i++) {
    if (player->idleTextures[i] == NULL)
      fprintf(stderr, "Error initializing player IDLE texture: %s\n",
              SDL_GetError());
  }
}

void player_character_renderIdle(player_character *player,
                                 SDL_Renderer *renderer, int *animationTime) {
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

  SDL_QueryTexture(player->idleTextures[idleTextureId], NULL, NULL, &player->sprite.w, &player->sprite.h);

  player->sprite.w *= 2;
  player->sprite.h *= 2;

  SDL_RenderCopy(renderer, player->idleTextures[idleTextureId], NULL, &player->sprite);
}

void player_character_moveLeft(player_character *player,
                               const float LIMITMOVE) {
  player->sprite.x -= 20;

  if (player->sprite.x <= LIMITMOVE)
    player->sprite.x = LIMITMOVE;
}

void player_character_moveRight(player_character *player,
                                const float LIMITMOVE) {
  player->sprite.x += 20;

  if (player->sprite.x >= LIMITMOVE)
    player->sprite.x = LIMITMOVE;
}

void player_character_moveUp(player_character *player, const float LIMITMOVE) {
  player->sprite.y -= 20;

  if (player->sprite.y <= LIMITMOVE)
    player->sprite.y = LIMITMOVE;
}

void player_character_moveDown(player_character *player,
                               const float LIMITMOVE) {
  player->sprite.y += 20;

  if (player->sprite.y >= LIMITMOVE)
    player->sprite.y = LIMITMOVE;
}

void player_character_destroyTexture(player_character *player) {
  for (int i = 0; i < PLAYER_CHARACTER_NUMBER_OF_IDLE_TEXTURES; i++)
    SDL_DestroyTexture(player->idleTextures[i]);
}