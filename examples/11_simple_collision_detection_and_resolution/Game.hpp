#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class Game
{
public:
  Game();
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  bool running() { return isRunning; };
  void render();
  void clean();

  static SDL_Renderer *renderer;
  static SDL_Event event;

private:
  int cnt = 0;
  bool isRunning = false;
  SDL_Window *window;
};

#endif /* Game_hpp */