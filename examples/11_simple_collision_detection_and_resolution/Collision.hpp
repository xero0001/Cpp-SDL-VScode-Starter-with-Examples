#ifndef Collision_hpp
#define Collision_hpp

#include <string>
#include "SDL2/SDL.h"

class Collision
{
public:
  static bool AABB(const SDL_Rect &recA, const SDL_Rect &recB);
};

#endif /* Collision_hpp */