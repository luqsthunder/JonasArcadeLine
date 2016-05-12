#ifndef JONASARCADEPROJECT_WALLPONG_H
#define JONASARCADEPROJECT_WALLPONG_H

#include "core/Wall.h"

class WallPong : public Wall
{
public:
  WallPong(sf::Vector2f position, sf::Vector2f size);

   void tellMe(IShock& other);
};


#endif //JONASARCADEPROJECT_WALLPONG_H
