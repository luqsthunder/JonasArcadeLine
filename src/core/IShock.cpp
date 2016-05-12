#include "IShock.h"

void IShock::checkChock(IShock &other)
{
  auto v = bounds();
  auto v2 = other.bounds();
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

void IShock::tellMe( IShock& other)
{
}