#include "Wall.h"

Wall::Wall(sf::Vector2f position, sf::Vector2f size) : _shape(size)
{
  _shape.setPosition(position);
  _shape.setOrigin(size.x /2, size.y / 2);
}


void
Wall::position(sf::Vector2f position)
{
  _shape.setPosition(position);
}

const sf::Vector2f
Wall::position() const
{
  return _shape.getPosition();
}

void
Wall::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
  target.draw(_shape, state);
}

sf::FloatRect
Wall::bounds() const
{
  return _shape.getGlobalBounds();
}

void
Wall::tellMe(const IShock &other) const
{
}
