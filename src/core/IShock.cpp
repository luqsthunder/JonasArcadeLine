#include "IShock.h"

void IShock::checkChock(const IShock &other)
{
  if(bounds().intersects(other.bounds()))
  {
    tellMe(other);
    other.tellMe(*(this));
  }
}

sf::FloatRect IShock::bounds() const
{
  return {0, 0, 0, 0};
}

void IShock::tellMe(const IShock& other) const
{
}