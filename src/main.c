#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#include "dirt_border_down_tile/dirt_border_down_tile.h"
#include "dirt_border_up_tile/dirt_border_up_tile.h"
#include "dirt_tile/dirt_tile.h"
#include "grass_tile/grass_tile.h"
#include "includes/player_character.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

static void render_dirt_path(dirt_tile tile, dirt_border_up_tile tileBorderUp,
                             dirt_border_down_tile tileBorderDown,
                             SDL_Renderer *renderer) {
  dirt_border_up_tile_renderLineXAxis(&tileBorderUp, renderer, 5, 32 * 0,
                                      32 * 6);
  dirt_border_up_tile_renderLineXAxis(&tileBorderUp, renderer, 11, 32 * 8,
                                      32 * 6);
  dirt_tile_renderLineXAxis(&tile, renderer, 19, 32 * 0, 32 * 7);
  dirt_tile_renderLineXAxis(&tile, renderer, 19, 32 * 0, 32 * 8);
  dirt_border_down_tile_renderLineXAxis(&tileBorderDown, renderer, 11, 32 * 0,
                                        32 * 9);
  dirt_border_down_tile_renderLineXAxis(&tileBorderDown, renderer, 5, 32 * 14,
                                        32 * 9);

  dirt_tile_renderLineYAxis(&tile, renderer, 6, 32 * 6, 32 * 0);
  dirt_tile_renderLineYAxis(&tile, renderer, 6, 32 * 7, 32 * 0);

  dirt_tile_renderLineYAxis(&tile, renderer, 6, 32 * 12, 32 * 8);
  dirt_tile_renderLineYAxis(&tile, renderer, 6, 32 * 13, 32 * 8);
}

int main(int argc, char *argv[]) {
  int idleFrame = 1;
  player_character player;
  grass_tile grass;
  dirt_tile dirt;
  dirt_border_up_tile dirtBorderUp;
  dirt_border_down_tile dirtBorderDown;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  TTF_Init();

  TTF_Font *font = TTF_OpenFont("resources/Fonts/LEMONMILK-Medium.otf", 24);

  if (!font) {
    fprintf(stderr, "Error loading font: %s\n", TTF_GetError());

    SDL_Quit();
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Trying", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!window) {
    fprintf(stderr, "Error initializing window: %s\n", SDL_GetError());

    SDL_Quit();
    return 1;
  }

  SDL_Renderer *mainRenderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!mainRenderer) {
    fprintf(stderr, "Error initializing renderer: %s\n", SDL_GetError());

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  player_character_initializeCharacterTextures(&player, mainRenderer);
  player.sprite.x = WINDOW_WIDTH / 2;
  player.sprite.y = WINDOW_HEIGHT / 2;

  grass_tile_initializeTexture(&grass, mainRenderer);

  dirt_tile_initializeTexture(&dirt, mainRenderer);

  dirt_border_up_tile_initializeTexture(&dirtBorderUp, mainRenderer);

  dirt_border_down_tile_initializeTexture(&dirtBorderDown, mainRenderer);

  SDL_Color color = {255, 255, 255};
  SDL_Surface *surface =
      TTF_RenderText_Solid(font, "Welcome to this DEMO.", color);

  SDL_Texture *textTexture1 =
      SDL_CreateTextureFromSurface(mainRenderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect textRect;
  SDL_QueryTexture(textTexture1, NULL, NULL, &textRect.w, &textRect.h);

  while (1) {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        break;

      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_A)
          player_character_moveLeft(&player, 0);

        if (event.key.keysym.scancode == SDL_SCANCODE_D)
          player_character_moveRight(&player, (WINDOW_WIDTH - player.sprite.w));

        if (event.key.keysym.scancode == SDL_SCANCODE_W)
          player_character_moveUp(&player, 0);

        if (event.key.keysym.scancode == SDL_SCANCODE_S)
          player_character_moveDown(&player, (WINDOW_HEIGHT - player.sprite.h));
      }
    }

    SDL_RenderClear(mainRenderer);

    for (int i = 0; i < WINDOW_HEIGHT / 32; i++) {
      int posY = 32 * i;

      for (int j = 0; j < WINDOW_WIDTH / 32; j++)
        grass_tile_renderTile(&grass, mainRenderer, 32 * j, posY);
    }

    render_dirt_path(dirt, dirtBorderUp, dirtBorderDown, mainRenderer);

    player_character_renderIdle(&player, mainRenderer, &idleFrame);

    SDL_RenderCopy(mainRenderer, textTexture1, NULL, &textRect);

    SDL_RenderPresent(mainRenderer);

    idleFrame++;
    SDL_Delay(1000 / 60);
  }

  player_character_destroyTexture(&player);
  grass_tile_destroyTexture(&grass);
  dirt_tile_destroyTexture(&dirt);

  SDL_DestroyRenderer(mainRenderer);
  SDL_DestroyWindow(window);

  SDL_DestroyTexture(textTexture1);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
