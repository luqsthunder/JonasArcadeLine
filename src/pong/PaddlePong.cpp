#include "PaddlePong.h"

PaddlePong::PaddlePong(sf::Vector2f position, sf::Vector2f size) :
  Paddle(position, size)
{
  _shape.setFillColor(sf::Color::Yellow);
}

void PaddlePong::tellMe(IShock& other)
{
}