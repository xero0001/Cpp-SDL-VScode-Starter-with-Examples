#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *textureFile)
{
  SDL_Surface *tempSurface = IMG_Load(textureFile);
  if (!tempSurface)
  {
    std::cout << "Texture load failed" << std::endl;
  }
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
  SDL_FreeSurface(tempSurface);

  return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
  SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}