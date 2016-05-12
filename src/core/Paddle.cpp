#include "Paddle.h"

Paddle::Paddle(sf::Vector2f position, sf::Vector2f size) : _shape(size)
{
  _shape.setOrigin(size.x /2, size.y / 2);
  _shape.setPosition(position);
  _horizontal = size.x > size.y;
}

void
Paddle::move(float x)
{
  if(_horizontal)
    _shape.move({x, 0});
  else
    _shape.move({0, x});
}

void
Paddle::position(sf::Vector2f position)
{
  _shape.setPosition(position);
}

const sf::Vector2f
Paddle::position() const
{
  return _shape.getPosition();
}

void
Paddle::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
  target.draw(_shape, state);
}

sf::FloatRect
Paddle::bounds() const
{
  return _shape.getGlobalBounds();
}

void
Paddle::tellMe(IShock &other)
{
}
