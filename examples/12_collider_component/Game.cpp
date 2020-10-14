#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent *> Game::colliders;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

auto &tile0(manager.addEntity());
auto &tile1(manager.addEntity());
auto &tile2(manager.addEntity());

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
    isRunning = false;
  }
  else
  {
    std::cout << "SDL_image initialized!" << std::endl;
  }

  map = new Map();

  // ECS implementation

  tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
  tile0.addComponent<ColliderComponent>("water");
  tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
  tile1.addComponent<ColliderComponent>("dirt");
  tile2.addComponent<TileComponent>(150, 150, 32, 32, 2);
  tile2.addComponent<ColliderComponent>("grass");

  player.addComponent<TransformComponent>(2);
  player.addComponent<SpriteComponent>("assets/player.png");
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");

  wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
  wall.addComponent<SpriteComponent>("assets/dirt.png");
  wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents()
{
  // SDL_Event event;
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
  manager.refresh();
  manager.update();

  for (auto cc : colliders)
  {
    Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
  }
}

void Game::render()
{
  SDL_RenderClear(renderer);
  // map->DrawMap();
  manager.draw();
  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned" << std::endl;
}