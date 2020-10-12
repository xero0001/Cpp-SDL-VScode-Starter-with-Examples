#include "SDL2/SDL.h"

SDL_Window *window = nullptr;
SDL_Surface *surface = nullptr;

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("02. With surface - Marching rect", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window)
    return -1;
  surface = SDL_GetWindowSurface(window);
  if (!surface)
    return -2;

  SDL_Rect rec;
  rec.x = 700;
  rec.y = 10,
  rec.w = 20;
  rec.h = 20;

  while (1)
  {
    // Fill old rectangle with dark purple color
    SDL_FillRect(surface, &rec, SDL_MapRGB(surface->format, 180, 10, 140));

    // Update rectangle position
    rec.x += 6;
    rec.y += 2;
    rec.x = rec.x > 800 ? 0 : rec.x;
    rec.y = rec.y > 600 ? 0 : rec.y;

    // Fill new rectangle with bright green color
    SDL_FillRect(surface, &rec, SDL_MapRGB(surface->format, 10, 200, 120));

    // Draw updated surface with 60FPS
    SDL_UpdateWindowSurface(window);
    SDL_Delay((1.0 / 60) * 1000);
  }

  // Destory and exit
  SDL_FreeSurface(surface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}