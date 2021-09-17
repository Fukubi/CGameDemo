#include "includes/player_character.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

void player_character_renderIdle(player_character *player, SDL_Renderer *renderer, int *animationTime) {
  if (*animationTime >= 1 && *animationTime < 5)
    player->texture = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_1.png");
  else if (*animationTime >= 5 && *animationTime < 10)
    player->texture = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_2.png");
  else if (*animationTime >= 10 && *animationTime < 15)
    player->texture = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_3.png");
  else if (*animationTime >= 15 && *animationTime < 20)
    player->texture = IMG_LoadTexture(renderer, "../resources/Bandit/Bandit_Idle_4.png");
  else
    *animationTime = 1;

	if (!player->texture)
		fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());

	SDL_QueryTexture(player->texture, NULL, NULL, &player->sprite.w, &player->sprite.h);

	player->sprite.w *= 2;
	player->sprite.h *= 2;
}

void player_character_DestroyPlayer(player_character *player) {
	SDL_DestroyTexture(player->texture);
}
