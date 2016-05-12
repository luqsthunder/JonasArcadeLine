#include "WallPong.h"

WallPong::WallPong(sf::Vector2f position, sf::Vector2f size) :
  Wall(position, size)
{
  _shape.setFillColor(sf::Color::Transparent);
  _shape.setOutlineThickness(-1);
  _shape.setOutlineColor(sf::Color::Red);
}

void WallPong::tellMe(IShock& other)
{
}