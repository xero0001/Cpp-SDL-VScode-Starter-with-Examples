#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *textureFile, SDL_Renderer *renderer)
{
  SDL_Surface *tempSurface = IMG_Load(textureFile);
  if (!tempSurface)
  {
    std::cout << "Texture load failed" << std::endl;
  }
  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_FreeSurface(tempSurface);

  return tex;
}