#ifndef TextureManager_hpp
#define TextureManager_hpp

#include "Game.hpp"

class TextureManager
{
public:
  static SDL_Texture *LoadTexture(const char *textureFile);
  static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};

#endif /* TextureManager_hpp */