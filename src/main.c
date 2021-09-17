#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#include "includes/player_character.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[]) {
  int idleFrame = 1;
  player_character player;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!window) {
    fprintf(stderr, "Error creating window: %s\n", SDL_GetError());

    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!renderer) {
    fprintf(stderr, "Error initializing renderer: %s\n", SDL_GetError());

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  player.sprite.x = WINDOW_WIDTH / 2;
  player.sprite.y = WINDOW_HEIGHT / 2;

  while (1) {
    int walkLeft = 0;
    int walkRight = 0;
    int walkUp = 0;
    int walkDown = 0;

    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        break;

      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_A) {
          walkLeft = 1;
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_D) {
          walkRight = 1;
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_W) {
          walkUp = 1;
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_S) {
          walkDown = 1;
        }
      }
    }

    if (walkLeft)
      player_character_moveLeft(&player, 0);

    if (walkRight)
      player_character_moveRight(&player, (WINDOW_WIDTH - player.sprite.w));

    if (walkUp)
      player_character_moveUp(&player, 0);

    if (walkDown)
      player_character_moveDown(&player, (WINDOW_HEIGHT - player.sprite.h));

    player_character_renderIdle(&player, renderer, &idleFrame);

    idleFrame++;
    SDL_Delay(1000 / 60);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
