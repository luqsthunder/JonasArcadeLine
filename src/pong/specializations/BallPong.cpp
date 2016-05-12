#include "BallPong.h"

Ball::Ball()
{
  super::Ball();
  _circle.setColor(sf::Color::Blue);
}

void Ball::update()
{
  _circle.move({1,1});
}