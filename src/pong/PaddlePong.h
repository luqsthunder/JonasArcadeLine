#ifndef JONASARCADEPROJECT_PADDLEPONG_H
#define JONASARCADEPROJECT_PADDLEPONG_H

#include "core/Paddle.h"

class PaddlePong : public Paddle
{
public:
  PaddlePong(sf::Vector2f position, sf::Vector2f size);
  void tellMe(IShock& other);
};


#endif //JONASARCADEPROJECT_PADDLEPONG_H
