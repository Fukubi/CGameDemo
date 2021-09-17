#include "includes/player_character.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

void player_character_renderIdle(player_character *player,
                                 SDL_Renderer *renderer, int *animationTime) {
  SDL_Texture *tex;

  if (*animationTime >= 1 && *animationTime < 5)
    tex = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_1.png");
  else if (*animationTime >= 5 && *animationTime < 10)
    tex = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_2.png");
  else if (*animationTime >= 10 && *animationTime < 15)
    tex = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_3.png");
  else if (*animationTime >= 15 && *animationTime < 20)
    tex = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_4.png");
  else
    *animationTime = 1;

  if (!tex)
    fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());

  SDL_QueryTexture(tex, NULL, NULL, &player->sprite.w, &player->sprite.h);

  player->sprite.w *= 2;
  player->sprite.h *= 2;

  SDL_RenderClear(renderer);

  SDL_RenderCopy(renderer, tex, NULL, &player->sprite);
	SDL_RenderPresent(renderer);

  SDL_DestroyTexture(tex);
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

void player_character_moveDown(player_character *player, const float LIMITMOVE) {
	player->sprite.y += 20;

	if (player->sprite.y >= LIMITMOVE)
		player->sprite.y = LIMITMOVE;
}
