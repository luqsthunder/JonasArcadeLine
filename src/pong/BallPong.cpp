#include "BallPong.h"

#include <iostream>

BallPong::BallPong(unsigned int radius, sf::Vector2f pos, size_t points) :
  Ball(radius, pos, points), dirBall(1,1), clockCont(0)
{

}
void BallPong::update()
{
  move(dirBall);
}

void BallPong::tellMe( IShock &other)
{
  clockCont = (clockCont + 1) % 4;
  switch (clockCont)
  {
    case 0:
      dirBall = {1, 1};
      break;
    case 1:
      dirBall = {1, -1};
      break;
    case 2:
      dirBall = {-1, -1};
      break;
    case 3:
      dirBall = {-1, 1};
      break;
    default:
      break;
  }
}





