#ifndef JONASARCADEPROJECT_BALLPONG_H
#define JONASARCADEPROJECT_BALLPONG_H

#include "core/Ball.h"

class BallPong : public Ball
{
public:
  BallPong(unsigned int radius, sf::Vector2f pos, size_t points = 30);
  void update();
  void tellMe(IShock& other);

protected:
  sf::Vector2f dirBall;
};


#endif //JONASARCADEPROJECT_BALLPONG_H
