#include "Game.hpp"

Game *game = nullptr;

// Constants
enum
{
  FPS = 60,
  frameDelay = 1000 / FPS
};

int main(int argc, char **argv)
{
  Uint32 frameStart;
  int frameTime;

  // Create new game object and initialize
  game = new Game();
  game->init("04 With sprite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

  while (game->running())
  {
    // Check ticks before computations
    frameStart = SDL_GetTicks();

    // Do event handling, updates, rendering
    game->handleEvents();
    game->update();
    game->render();

    // Check ticks after computations
    frameTime = SDL_GetTicks() - frameStart;

    // Wait until next frame time
    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();

  return 0;
}