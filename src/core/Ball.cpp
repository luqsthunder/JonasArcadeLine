#include "Ball.h"

#include <SFML/Graphics/RenderTarget.hpp>

Ball::Ball(unsigned int radius, sf::Vector2f position, size_t points) :
_circle(radius, points)
{
  _circle.setPosition(position);
  boundsShape.left = _circle.getPosition().x;
  boundsShape.top = _circle.getPosition().y;
  boundsShape.width = _circle.getRadius() * 2;
  boundsShape.height = _circle.getRadius() * 2;
}

void
Ball::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
  target.draw(_circle, state);
}

void
Ball::update() { }

void
Ball::position(sf::Vector2f pos)
{
  _circle.setPosition(pos);
  boundsShape.left = pos.x;
  boundsShape.top = pos.y;
}

void
Ball::move(sf::Vector2f pos)
{
  _circle.move(pos);

  boundsShape.left += pos.x;
  boundsShape.top += pos.y;
}

const sf::Vector2f
Ball::position() const
{
  return  _circle.getPosition();
}

void
Ball::tellMe(IShock& other) { }

sf::FloatRect
Ball::bounds() const
{
  return boundsShape;
}