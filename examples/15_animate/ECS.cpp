#include "ECS/ECS.hpp"

void Entity::addGroup(Group mGroup)
{
  groupBitset[mGroup] = true;
  manager.AddToGroup(this, mGroup);
}