#include "SDL2/SDL.h"

// Global
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("01. With renderer - Initialization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window)
    return -1;
  // Second argument of "SDL_CreateRenderer()" is "index" - The index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags.
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer)
    return -2;

  // Initialize with green background
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  // Exit after 3 seconds
  SDL_Delay(3000);
  return 0;
}