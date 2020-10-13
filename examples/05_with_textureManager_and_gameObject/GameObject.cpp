#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *otherRenderer, int x, int y)
{
  renderer = otherRenderer;
  objTexture = TextureManager::LoadTexture(texturesheet, otherRenderer);

  xpos = x;
  ypos = y;

  srcRect.h = 32;
  srcRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;
}

void GameObject::Update()
{
  ++xpos;
  ++ypos;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w * 2;
  destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
  SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}