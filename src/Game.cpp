#include "Game.hpp"

SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  // Bit flag
  int flags = 0;
  if (fullscreen == true)
  {
    flags |= SDL_WINDOW_FULLSCREEN;
  }

  // Check if Initialize successful
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsystems Initialized" << std::endl;

    // Create and check window
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window)
    {
      std::cout << "Window created!" << std::endl;
    }
    else
    {
      std::cout << "Window creation failed" << std::endl;
    }

    // Create and check renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created!" << std::endl;
    }
    else
    {
      std::cout << "Rendere creation failed" << std::endl;
    }

    isRunning = true;
  }
  else
  {
    isRunning = false;
  }

  // Check SDL_image
  if (!IMG_Init(IMG_INIT_PNG))
  {
    std::cout << "SDL_image could not initialize! SDL_image Error:" << std::endl
              << IMG_GetError() << std::endl;
    // isRunning = false;
  }
  else
  {
    std::cout << "SDL_image initialized!" << std::endl;
  }

  // Load player image
  SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
  if (!tmpSurface)
  {
    std::cout << "Image load failed" << std::endl;
  }

  playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

  // Init player position
  destR.h = 32;
  destR.w = 32;
  destR.x = 0;
  destR.y = 0;
}

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::update()
{
  // Count frame
  ++cnt;

  destR.x = cnt;

  std::cout << cnt << std::endl;
}

void Game::render()
{
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, playerTex, nullptr, &destR);
  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned" << std::endl;
}