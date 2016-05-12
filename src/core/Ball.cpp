#include "Ball.h"

#include <SFML/Graphics/RenderTarget.hpp>

Ball::Ball(unsigned int radius, sf::Vector2f position, size_t points) :
_circle(radius, points)
{
  _circle.setPosition(position);
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
}

void
Ball::move(sf::Vector2f pos)
{
  _circle.move(pos);
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
  return _circle.getGlobalBounds();
}