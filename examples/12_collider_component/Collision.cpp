#include "Collision.hpp"
#include "ECS/ColliderComponent.hpp"

bool Collision::AABB(const SDL_Rect &recA, const SDL_Rect &recB)
{
  return SDL_HasIntersection(&recA, &recB);
}

bool Collision::AABB(const ColliderComponent &colA, const ColliderComponent &colB)
{
  // return AABB(colA.collider, colB.collider);
  if (AABB(colA.collider, colB.collider))
  {
    std::cout << colA.tag << " hit: " << colB.tag << std::endl;
    return true;
  }
  return false;
}