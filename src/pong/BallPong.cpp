#include "BallPong.h"

#include <iostream>

BallPong::BallPong(unsigned int radius, sf::Vector2f pos, size_t points) :
  Ball(radius, pos, points), dirBall(1,1)
{

}
void BallPong::update()
{
  move(dirBall);
}

void BallPong::tellMe( IShock &other)
{
  std::cout << "here now" << std::endl;
  dirBall = (dirBall.x < 0) ? sf::Vector2f{1, -1} : sf::Vector2f{-1, 1};
}





